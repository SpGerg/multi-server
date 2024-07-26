#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <direct.h>
#include "server.h"
#include "..\logger\enums\color.h"
#include "..\logger\logger.h"

typedef struct server {
    const char* id;
    unsigned int port;
    logger* logger;
} server;

server* server_create(const char* id, unsigned int port) {
    server* instance = calloc(1, sizeof(server));

    if (instance == NULL) {
        printf(RED "Not enough memory to create the server.");
        printf(STANDART);

        return NULL;
    }

    char* directory = _getcwd(NULL, MAX_PATH_SIZE);

    if (directory == NULL) {
        printf(RED "Error with get directory");
        printf(STANDART);

        return NULL;
    }

    char* logsDirectory = calloc(strlen(directory) + strlen(id) + 15, sizeof(char));

    strcat(logsDirectory, directory);
    strcat(logsDirectory, "\\servers\\");
    strcat(logsDirectory, id);
    strcat(logsDirectory, "\\");
    strcat(logsDirectory, "logs");

    logger* logger = logger_create("SERVER", logsDirectory);

    if (logger == NULL) {
        printf(RED "The server cannot be created due to a logger creation error (not enough memory)");
        printf(STANDART);

        return NULL;
    }

    instance->id = id;
    instance->port = port;
    instance->logger = logger;

    free(logsDirectory);

    return instance;
}

void server_run(server* server) {
    logger_log(server->logger, "Running server...");
}

logger* server_get_logger(server* server) {
    return server->logger;
}

void server_destroy(server* server) {
    logger_destroy(server->logger);
    free(server);
}
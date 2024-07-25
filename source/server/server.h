#pragma once

#include "..\logger\logger.h"

#define MAX_PATH_SIZE 256

typedef struct server server;

server* server_create(const char* id, unsigned int port);

void server_run(server* server);

logger* server_get_logger(server* server);

void server_destroy(server* server);
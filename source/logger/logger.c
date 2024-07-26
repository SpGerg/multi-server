#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "..\utilities.h"
#include "logger.h"
#include "enums/color.h"

#define STRING_TIME_SIZE 128

typedef struct logger {
    const char* tag;
    char* directory;
    char* file_name;
    FILE* file;
} logger;

time_t get_current_time() {
    return time(NULL);
}

char* get_logs_folder_name(time_t time) {
    char* time_string = calloc(STRING_TIME_SIZE, sizeof(char));

    if (time_string == NULL) {
        printf(RED "Not enough memory to create the log file name.");
        printf(STANDART);

        return NULL;
    }

    struct tm* time_info = gmtime(&time);

    strftime(time_string, STRING_TIME_SIZE, "%Y_%m_%d", time_info);

    return time_string;
}

char* get_logs_file_name(time_t time) {
    char* time_string = calloc(STRING_TIME_SIZE, sizeof(char));

    if (time_string == NULL) {
        printf(RED "Not enough memory to create the log file name.");
        printf(STANDART);

        return NULL;
    }

    struct tm* time_info = gmtime(&time);

    strftime(time_string, STRING_TIME_SIZE, "%Y_%m_%d_%H_%M_%S", time_info);

    return strcat(time_string, ".log");
}

char* get_time_for_log(time_t time) {
    char* time_string = calloc(STRING_TIME_SIZE, sizeof(char));

    if (time_string == NULL) {
        printf(RED "Not enough memory to get log time.");
        printf(STANDART);

        return NULL;
    }

    struct tm* time_info = gmtime(&time);

    strftime(time_string, 26, "%Y-%m-%d %H:%M:%S", time_info);

    return time_string;
}

char* create_log_message(const char* tag, const char* messageType, const char* message) {
    char* current_time = get_time_for_log(get_current_time());

    char* finalMessage = calloc(strlen(messageType) + strlen(message) + strlen(current_time) + strlen(tag) + 5, sizeof(char));

    strcat(finalMessage, "[");
    strcat(finalMessage, current_time);
    strcat(finalMessage, "] ");
    strcat(finalMessage, "[");
    strcat(finalMessage, tag);
    strcat(finalMessage, "] ");
    strcat(finalMessage, messageType);
    strcat(finalMessage, message);

    free(current_time);

    return finalMessage;
}

logger* logger_create(const char* tag, const char* directory) {
    logger* instance = calloc(1, sizeof(logger));

    if (instance == NULL) {
        printf(RED "Not enough memory to create the logger.");
        printf(STANDART);

        return NULL;
    }

    char* logs_folder_name = get_logs_folder_name(get_current_time());
    char* time = get_logs_file_name(get_current_time());

    char* logs_folder = calloc(strlen(directory) + strlen(logs_folder_name) + 1, sizeof(char));

    if (logs_folder == NULL) {
        printf(RED "Not enough memory to create a logger.");
        printf(STANDART);
        
        return NULL;
    }

    strcat(logs_folder, directory);
    strcat(logs_folder, "\\");
    strcat(logs_folder, logs_folder_name);

    utilities_create_directories(logs_folder);

    char* directory_with_log_file = calloc(strlen(logs_folder) + strlen(time) + 1, sizeof(char));

    if (directory_with_log_file == NULL) {
        printf(RED "Not enough memory to create a logger.");
        printf(STANDART);
        
        return NULL;
    }

    strcat(directory_with_log_file, logs_folder);
    strcat(directory_with_log_file, "\\");
    strcat(directory_with_log_file, time);

    instance->tag = tag;
    instance->directory = directory_with_log_file;
    instance->file = fopen(instance->directory, "a");

    if (!instance->file) {
        printf("e");
    }

    free(time);
    free(logs_folder);
    free(logs_folder_name);

    return instance;
}

void logger_message(logger* logger, const char* message, color color) {
    const char* result = message;

    printf(getColor(color));
    printf(result);
    printf(STANDART);

    fprintf(logger->file, result);
}

void logger_log(logger* logger, char* message) {
    char* finalMessage = create_log_message(logger->tag, "[INFO] ", message);

    logger_message(logger, finalMessage, cyan);

    free(finalMessage);
}

void logger_debug(logger* logger, const char* message) {
    char* finalMessage = create_log_message(logger->tag, "[DEBUG] ", message);

    logger_message(logger, finalMessage, standart);

    free(finalMessage);
}

void logger_warn(logger* logger, const char* message) {
    char* finalMessage = create_log_message(logger->tag, "[WARN] ", message);

    logger_message(logger, finalMessage, yellow);

    free(finalMessage);
}

void logger_error(logger* logger, const char* message) {
    char* finalMessage = create_log_message(logger->tag, "[ERROR] ", message);

    logger_message(logger, finalMessage, red);

    free(finalMessage);
}

void logger_destroy(logger* logger) {
    fclose(logger->file);
    free(logger->directory);
    free(logger);
}
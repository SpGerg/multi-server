#pragma once

#include "enums/color.h"

typedef struct logger logger;

logger* logger_create(const char* tag, const char* directory);

void logger_message(logger* logger, const char* message, color color);

void logger_log(logger* logger, char* message);

void logger_debug(logger* logger, const char* message);

void logger_warn(logger* logger, const char* message);

void logger_error(logger* logger, const char* message);

void logger_destroy(logger* logger);
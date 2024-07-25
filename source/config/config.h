#pragma once

#define LAUNCH_CONFIG_FILENAME "config.yml"

#include "storage.h"

typedef struct config config;

config* config_create(const char* directory);

void config_load(config* config);

void config_destroy(config* config);
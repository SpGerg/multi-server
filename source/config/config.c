#include <stdlib.h>
#include <stdio.h>
#include <io.h>
#include <string.h>
#include "..\logger\enums\color.h"
#include "cyaml.h"
#include "config.h"
#include "storage.h"

#define DEFAULT_YAML_CONFIG { .log_fn = cyaml_log, .mem_fn = cyaml_mem, .log_level = CYAML_LOG_WARNING }

typedef struct config {
    storage* storage;
    const char* directory;
} config;

config* config_create(const char* directory) {
    config* instance = calloc(1, sizeof(config));

    if (instance == NULL) {
        printf(RED "Not enough memory to create the config.");
        printf(STANDART);

        return NULL;
    }

    instance->directory = directory;
    instance->storage = storage_create();
}

void config_load(config* config) {
    FILE* file;

    char* directoryWithFile = calloc(strlen(config->directory) + strlen(config->directory) + 1, sizeof(char));

    if (directoryWithFile == NULL) {
        printf(RED "Not enough memory to create the directory to launch config file.");
        printf(STANDART);

        return NULL;
    }

    cyaml_schema_field_t top_mapping_schema[] = {
        CYAML_FIELD_INT("tickDelay", CYAML_FLAG_DEFAULT, storage, tickDelay),
        CYAML_FIELD_END
    };

    strcat(directoryWithFile, config->directory);
    strcat(directoryWithFile, " ");
    strcat(directoryWithFile, LAUNCH_CONFIG_FILENAME);

    file = fopen(directoryWithFile, "w");

    cyaml_save_file(directoryWithFile, top_mapping_schema, NULL, (cyaml_data_t**) &config->storage, NULL);
}

void config_destroy(config* config);
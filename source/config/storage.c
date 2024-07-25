#include <stdlib.h>
#include <stdio.h>
#include "..\logger\enums\color.h"
#include "storage.h"

storage* storage_create() {
    storage* instance = calloc(1, sizeof(storage));

    if (instance == NULL) {
        printf(RED "Not enough memory to create the config.");
        printf(STANDART);

        return NULL;
    }

    instance->tickDelay = TICK_DELAY_DEFAULT;

    return instance;
}

void storage_destroy(storage* storage) {
    free(storage);
}
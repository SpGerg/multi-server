#pragma once

#define TICK_DELAY_DEFAULT 1000

typedef struct storage {
    int tickDelay;
} storage;

storage* storage_create();

void storage_destroy(storage* storage);
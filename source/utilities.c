#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "utilities.h"

void utilities_create_directories(const char* directory) {
    if (CreateDirectory(directory, NULL) == FALSE || GetLastError() == ERROR_ALREADY_EXISTS) {
        return;
    }

    int index = 0;
    char* copy = calloc(strlen(directory), sizeof(char));

    while (CreateDirectory(directory, NULL) == FALSE) {
        while (directory[index] != '\\') {
            index++;

            continue;
        }
        
        memcpy((void*)copy, directory, index);

        CreateDirectory(copy, NULL);

        index++;
    }

    free((void*)copy);
}
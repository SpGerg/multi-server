#pragma once

#define RED   "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE   "\x1B[34m"
#define MAGNETA  "\x1B[35m"
#define CYAN   "\x1B[36m"
#define WHITE   "\x1B[37m"
#define STANDART "\x1B[0m"

typedef enum {
    red,
    green,
    yellow,
    blue,
    magneta,
    cyan,
    white,
    standart
} color;

const char* getColor(color color);
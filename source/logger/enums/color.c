#include "color.h"

const char* getColor(color color) {
    switch (color)
    {
        case red:
            return RED;
        case green:
            return GREEN;
        case blue:
            return BLUE;
        case yellow:
            return YELLOW;
        case magneta:
            return MAGNETA;
        case cyan:
            return CYAN;
        case white:
            return WHITE;
        case standart:
            return STANDART;
        default:
            return STANDART;
    }
}
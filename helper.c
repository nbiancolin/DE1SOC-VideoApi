#include "helper.h"

unsigned short rbgToColour(int r, int g, int b){
    return (r << 11) | (g << 5) | b;
}
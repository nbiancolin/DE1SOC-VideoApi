#ifndef DRAW_H
#define DRAW_H

#include "globals.h"

//fills entire screen with black
void clearScreen(void* v);

//Fills the entire screen with the given color
void fillScreen(void* v, uWord c);

//draw horizontal line
void drawHLine(void* v, uWord c, int y);
//draw vertical line
void drawVLine(void* v, uWord c, int x);


#endif /*DRAW_H*/

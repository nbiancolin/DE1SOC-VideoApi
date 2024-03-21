#ifndef DRAW_H
#define DRAW_H

#include "globals.h"

//fills entire screen with black
void clearScreen(void* v);

//Fills the entire screen with the given color
void fillScreen(void* v, uWord c);

//draws a single pixel (not really used anywhere but incase you need it)
static inline void drawPixel(void* v, int x, int y, uWord C);

//draw horizontal line
void drawHLine(void* v, uWord c, int y);
//draw vertical line
void drawVLine(void* v, uWord c, int x);
//draws a line between any two points
void drawLine(void* v, int x0, int y0, int x1, int y1, int color);

//draws a filled rectangle
void drawRect(void* v, int x_i, int y_i, int width, int height, uWord c);

#endif /*DRAW_H*/

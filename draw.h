#ifndef DRAW_H
#define DRAW_H

#include "globals.h"

//fills entire screen with black

//remove pointers to v, make V a global variable and just access it in the function
void clearScreen();

//Fills the entire screen with the given color
void fillScreen(uWord c);

//draws a single pixel (not really used anywhere but incase you need it)
static inline void drawPixel(int x, int y, uWord C);

//draw horizontal line
void drawHLine(uWord c, int y);
//draw vertical line
void drawVLine(uWord c, int x);
//draws a line between any two points
void drawLine(int x0, int y0, int x1, int y1, int color);

//draws a filled rectangle
void drawRect(int x_i, int y_i, int width, int height, uWord c);

//draws an 8x8 sprite starting at x_i, y_i
void drawSprite(int x_i, int y_i, int* sprite);
//draws an entire image to the screen via deep copying the items to the frame buffer
void drawScreen(int* img);

//Goes through character buffer and draws the characters
void drawChar(int x, int y, char c);

void drawString(int x, int y, char* str);

#endif /*DRAW_H*/

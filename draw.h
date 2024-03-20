#ifndef DRAW_C
#define DRAW_C

#include "structs.h"

//draws screen to black
void clearScreen(VideoStruct *v);
//draws screen to color
void fillScreen(VideoStruct *v, unsigned short color);

//takes in an n x 2 array of pixels (outputted from draw rectangles and such) and only erases the drawn pixels
void smartClear(VideoStruct *v, int* pixels);

//Misc drawing functions, pretty self explanatory
static inline void drawPixel(VideoStruct *v, int x, int y, unsigned short color);
void drawLine(VideoStruct *v, int x1, int y1, int x2, int y2, unsigned short color);
void drawRect(VideoStruct *v, int x, int y, int width, int height, unsigned short color);
void drawHollowRect(VideoStruct *v, int x, int y, int width, int height, unsigned short color);

//uses the character buffer to draw a character at a given location
void drawChar(VideoStruct *v, int x, int y, char ch);

//same as drawChar but for strings
void drawString(VideoStruct *v, int x, int y, char* str);

//takes in a pointer to the array of pixels and points the frame buffer there
void drawImage(VideoStruct *v, unsigned short image[SCREEN_HEIGHT][SCREEN_WIDTH]);


#endif /*DRAW_C*/
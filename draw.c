#include "globals.h"
#include "structs.h"

void clearScreen(void* v){
    struct fb_t* framebuffer = ((struct videoStruct*)v)->fbp;
    for (int y = 0; y < SCREEN_HEIGHT; y++)
        for (int x = 0; x < SCREEN_WIDTH; x++)
            framebuffer->pixels[y][x] = C_BLACK;
}

void fillScreen(void* v, uWord c){
    struct fb_t* framebuffer = ((struct videoStruct*)v)->fbp;
    for (int y = 0; y < SCREEN_HEIGHT; y++)
        for (int x = 0; x < SCREEN_WIDTH; x++)
            framebuffer->pixels[y][x] = c;
}


void drawHLine(void* v, uWord c, int y){
    //uses void pointers to avoid the compiler trying to optimise the code
    struct fb_t* framebuffer = ((struct videoStruct*)v)->fbp;
    for (int x = 0; x < SCREEN_WIDTH; x++){
        framebuffer->pixels[y][x] = c;
    }
}
void drawVLine(void* v, uWord c, int x){
    struct fb_t* framebuffer = ((struct videoStruct*)v)->fbp;
    for (int y = 0; y < SCREEN_HEIGHT; y++){
        framebuffer->pixels[y][x] = c;
    }
}


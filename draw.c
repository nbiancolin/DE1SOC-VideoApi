#include "globals.h"
#include "structs.h"

void drawLine(struct fb_t *fbp, unsigned short c, int y){
    for (int x = 0; x < 320; x++){
        fbp->pixels[y][x] = c;
    }
}

void clearScreen(struct fb_t *fbp, uWord c){
    for (int y = 0; y < SCREEN_HEIGHT; y++)
        for (int x = 0; x < SCREEN_WIDTH; x++)
            fbp->pixels[y][x] = c;
}
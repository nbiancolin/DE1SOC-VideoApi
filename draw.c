#include "globals.h"
#include "structs.h"
#include "draw.h"
#include "helper.h"

#include <stdbool.h>
#include <stdlib.h>

void clearScreen(){
    //struct fb_t* framebuffer = ((struct videoStruct*)v)->fbp;
    for (int y = 0; y < SCREEN_HEIGHT; y++)
        for (int x = 0; x < SCREEN_WIDTH; x++)
            VIDEO_BASE->fbp->pixels[y][x] = C_BLACK;
}

void fillScreen(uWord c){
    //struct fb_t* framebuffer = ((struct videoStruct*)v)->fbp;
    for (int y = 0; y < SCREEN_HEIGHT; y++)
        for (int x = 0; x < SCREEN_WIDTH; x++)
            VIDEO_BASE->fbp->pixels[y][x] = c;
}


void drawHLine(uWord c, int y){
    //struct fb_t* framebuffer = ((struct videoStruct*)v)->fbp;
    for (int x = 0; x < SCREEN_WIDTH; x++){
        VIDEO_BASE->fbp->pixels[y][x] = c;
    }
}
void drawVLine(uWord c, int x){
    //struct fb_t* framebuffer = ((struct videoStruct*)v)->fbp;
    for (int y = 0; y < SCREEN_HEIGHT; y++){
        VIDEO_BASE->fbp->pixels[y][x] = c;
    }
}

void drawLine(int x0, int y0, int x1, int y1, int color){
    bool isSteep = abs(y1-y0) > abs(x1-x0);
    if (isSteep){
        swap(&x0, &y0);
        swap(&x1, &y1);
    }
    if (x0 > x1){
        swap(&x0, &x1);
        swap(&y0, &y1);
    }
    int deltaX = x1 - x0;
    int deltaY = abs(y1 - y0);
    int error = -(deltaX / 2);
    int y = y0;
    int y_step;
    if (y0 < y1) {
        y_step = 1 ;
    } else {y_step = -1;}

    for (int x = x0; x < x1; x++){
        if (isSteep){
            drawPixel(y, x, color);
        } else {
            drawPixel(x, y, color);
        }
        error = error + deltaY;
        if (error > 0){
            y = y + y_step;
            error -= deltaX;
        }
    }
}

void drawRect(int x_i, int y_i, int width, int height, uWord c){
	//struct fb_t* framebuffer = ((struct videoStruct*)v)->fbp;
	for(int y = y_i; y < height; ++y) {
		for(int x = x_i; x < width; ++x) {
			VIDEO_BASE->fbp->pixels[y][x] = c;	//could modify to use drawPixel but I don't think it makes a difference
		}
	}
}


static inline void drawPixel(int x, int y, uWord c){
    //struct fb_t* framebuffer = ((struct videoStruct*)v)->fbp;
    VIDEO_BASE->fbp->pixels[y][x] = c;
}

void drawChar(int x, int y, char c){
    volatile char* cBuffer = (char *)CHAR_BASE;
	int offset = (y << 7) +x;
	*(cBuffer + offset) = c;
}

void drawString(int x, int y, char* str){
    while(*str){
        drawChar(x++, y, *str);
        //wraparound checking just in case
        if(x > 79){
            x = 0;
            y++;
        } 
        if(y > 59){
            y = 0;
        }
        str++;
    }
}


void drawSprite(int x_i, int y_i, int* sprite){
    //Assuming sprite is 8x8
    for(size_t y = 0; y < 8; ++y){
        for(size_t x = 0; x < 8; ++x){
            drawPixel(x, y, *sprite);
            ++sprite;
        }
    }
}

void drawScreen(int* img){
    for(size_t y = 0; y < SCREEN_HEIGHT; ++y){
        for(size_t x = 0; x < SCREEN_WIDTH; ++x){
            drawPixel(x,y,*img);
            ++img;
        }
    }
}
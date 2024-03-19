#include "structs.h"
#include "draw.h"
#include "globals.h"
#include "helper.h"

void clearScreen(VideoStruct* v){
    //uses pointer arithmetic for better speed
    unsigned short* ptr = (unsigned short*)v->backBuffer;
    unsigned short* end = (unsigned short*)(v->backBuffer + SCREEN_HEIGHT * SCREEN_HEIGHT);
    while(ptr < end){
        *ptr = C_BLACK;
        ptr++;
    }
}

void fillScreen(VideoStruct* v, unsigned short colour){
    unsigned short* ptr = (unsigned short*)v->backBuffer;
    unsigned short* end = (unsigned short*)(v->backBuffer + SCREEN_HEIGHT * SCREEN_HEIGHT);
    
    while(ptr < end){
        *ptr = colour;
        ptr++;
    }
}

//TODO: Eventually add support for this in all the functions
void smartClear(VideoStruct* v, int* points){
    for(int i = 0; i < SCREEN_HEIGHT; i +=+ 2){
        if (*points == -1)
            return;
        v->backBuffer->pixels[*(points +i)][*(points +i +1)] = C_BLACK;
    }
}


void drawPixel(VideoStruct* v, int x, int y, unsigned short colour){
    if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT){
        return;
    }
    v->backBuffer->pixels[y][x] = colour;
}
void drawLine(VideoStruct* v, int x1, int y1, int x2, int y2, unsigned short colour){
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x = x1;
    int y = y1;
    int steps;
    if(abs(dx) > abs(dy)){
        steps = abs(dx);
    }else{
        steps = abs(dy);
    }
    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;
    for(int i = 0; i < steps; i++){
        drawPixel(v, x, y, colour);
        x += xInc;
        y += yInc;
    }
}

void drawRect(VideoStruct* v, int x, int y, int width, int height, unsigned short colour){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            drawPixel(v, x + j, y + i, colour);
        }
    }
}

void drawHollowRect(VideoStruct* v, int x, int y, int width, int height, unsigned short colour){
    for(int i = 0; i < width; i++){
        drawPixel(v, x + i, y, colour);
        drawPixel(v, x + i, y + height - 1, colour);
    }
    for(int i = 0; i < height; i++){
        drawPixel(v, x, y + i, colour);
        drawPixel(v, x + width - 1, y + i, colour);
    }
}
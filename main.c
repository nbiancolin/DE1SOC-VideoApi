#include <stdio.h>
#include "draw.h"

int main() {
    // Call the functions from draw.h

    
    
    clearScreen();
	fillScreen(0xFFF0);
	drawHLine(0x0000, 20);
	drawHLine(0x00FF, 200);
	drawRect(30, 30, 50, 40, 0xFF00);
	drawLine(40, 40, 100, 200, 0x0000);

    //Note that these functions only ever update the back buffer! It is your job to copy the back buffer to the front buffer every so often!
    //perhaps using interrupts or something? I have not thought that far ahead haha.

    return 0;
}
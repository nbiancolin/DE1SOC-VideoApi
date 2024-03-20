#include <stdio.h>
#include "draw.h"

int main() {
    // Call the functions from draw.h

    VideoStruct volatile *const v = (VideoStruct*)VIDEO_BASE;
    drawLine(v, 0, 0, 320, 240, C_RED);

    //Note that these functions only ever update the back buffer! It is your job to copy the back buffer to the front buffer every so often!
    //perhaps using interrupts or something? I have not thought that far ahead haha.

    return 0;
}
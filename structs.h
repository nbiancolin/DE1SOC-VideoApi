#ifndef STRUCTS_H
#define STRUCTS_H

//#define uint32 unsigned int
//#define uWord unsigned short

typedef struct frameBuffer {
    unsigned short volatile pixels[256][512];
} fb_t;

typedef struct videoStruct {
    fb_t *volatile frontBuffer; 
    fb_t *volatile backBuffer; 
    unsigned int volatile resolution; 
    unsigned int volatile StatusControl;
} VideoStruct;


#endif /*STRUCTS_H*/
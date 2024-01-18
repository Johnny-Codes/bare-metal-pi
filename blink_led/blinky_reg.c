#include <stdio.h>
// need some help with this

/* 
pin 17 is in register 0
which is memory address 0xFE200000 (FE for pi4)
*/
#define GPFSEL0 0xFE200000
#define GPFSEL1 0xFE200004
#define GPFSEL2 0xFE200008

/*

000 is input
001 is output
... alt functions
but really just need to set bit 3? or 5? to 1
probably 3 if read right to left
*/

/*
need to set pin 17 to output
bits 5-3
*/

/*
define delay between blinks
*/
#define DELAY 100

typedef unsigned int uint;

void write32(void *dst, uint val) 
{
    uint* dst_u = (uint*)dst;
    *dst_u = val;
    printf("writing %i\n", dst_u);
    return;
}

uint read32(uint *src)
{
    uint* src_u = (uint*)src;
    printf("reading %i\n", src_u);
    return *src_u;
}

void main(void)
{
    uint gpfsel0 = read32(GPFSEL0);
    gpfsel0 |= (1<<3); //turn 17 to outpout
    write32(GPFSEL0, gpfsel0);
}

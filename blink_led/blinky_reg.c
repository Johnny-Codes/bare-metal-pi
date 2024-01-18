// need some help with this

/* 
pin 17 is in register 0
which is memory address 0xFE200000 (FE for pi4)
*/
#define LED_REGISTER 0xFE200000
/*

000 is input
001 is output
... alt functions
but really just need to set bit 3? or 5? to 1
probably 3 if read right to left
*/
#define OUTPUT 001
/*
need to set pin 17 to output
bits 5-3
*/

/*
define delay between blinks
*/
#define DELAY 100

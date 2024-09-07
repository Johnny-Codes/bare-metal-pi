#include <stdio.h>
#include <bcm2835.h>

#define SERVO       18
#define PWM_CHANNEL 0
#define RANGE       180


void moveServo(int angle, int prevangle, int hold, int align) {
    int pulse;
    int j;
    float hightime = 13*(float)angle + 546;

    if (hold == 0) {
        if (align == 1) {
//            printf("Aligning to %d\n", angle);
            pulse = 40;
        } else {
            printf("Moving to %d with pulse %i\n", angle, pulse);
            pulse = (int)abs(((angle - prevangle)*33/RANGE));
        }
        
        for (j = 0; j < pulse ; ++j) {
            bcm2835_gpio_set(SERVO);
            bcm2835_delayMicroseconds((int)hightime);
            bcm2835_gpio_clr(SERVO);
            bcm2835_delayMicroseconds(20000);
        }
//        bcm2835_delay(1000);
    } 
}


int main(int argc, char *argv[])
{
    if (!bcm2835_init()) return 1;
    
    printf("Program is starting...\n");
    int prevangle;
    int a;
    int angle;
    int align;
    int hold; 
    bcm2835_gpio_fsel(SERVO, BCM2835_GPIO_FSEL_OUTP);
    
    // align servo to starting point
    moveServo(0, 0, 0, 1);
    prevangle = 0;

    // create an array of angles to iterate over while testing
    size_t angles[] = { 45, 90, 135, 180, 90, 45, 135, 180, 0, 180, 0, 135, 0, 90, 0, 45, 90 };
    for (a = 0; a < sizeof(angles) / sizeof(size_t); ++a) {
        moveServo(angles[a], prevangle, 0, 0);
        prevangle = angles[a];
    }
    
    // align servo back to 0 when done
    //moveServo(0, prevangle, 0, 1);    
    
    // safely close the board
    bcm2835_close();
    
    return 0;
}

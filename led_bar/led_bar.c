#include <stdio.h>
#include <bcm2835.h>

#define ledCount 10
int pins[ledCount] = { 17, 18, 27, 22, 23, 24, 25, 2, 3, 8 };


int main(int argc, char **argv)
{
    int i;
    
    if (!bcm2835_init()) return 1;
    printf("\nInitialized\n");

    // set all pins to output
    for (i = 0; i < ledCount; ++i) {
        bcm2835_gpio_fsel(pins[i], BCM2835_GPIO_FSEL_OUTP);
    }

    while (1) {    
        for (i = 0; i < ledCount; i++) {
            printf("Turning on pin %d\n", pins[i]);
            bcm2835_gpio_write(pins[i], LOW);
            bcm2835_delay(100);
            bcm2835_gpio_write(pins[i], HIGH);
        }
        
        for (i = (ledCount - 1); i > -1; --i) {
            printf("Turning on pin %d\n", pins[i]);
            bcm2835_gpio_write(pins[i], LOW);
            bcm2835_delay(200);
            bcm2835_gpio_write(pins[i], HIGH);
        }        

    }
    
    bcm2835_close();
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <bcm2835.h>

#define LED RPI_GPIO_P1_11 // pin 17 can also just set to 17

int main(int argc, char *argv[])
{
    if (!bcm2835_init()) return 1;
    
    bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP);
    
    unsigned int delay = 100;
    for (int i = 0; i < 10; ++i) {
            bcm2835_gpio_set(LED);
            bcm2835_delay(delay);
            bcm2835_gpio_clr(LED);
            bcm2835_delay(delay);
    }

    bcm2835_close();
    return 0;
}

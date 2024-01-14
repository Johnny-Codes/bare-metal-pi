#include <stdio.h>
#include <bcm2835.h>

#define LED    18
#define SENSOR 17
int main(int argc, char *argv[])
{
    if (!bcm2835_init()) return 1;

    bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP); // LED -> Output
    bcm2835_gpio_fsel(SENSOR, BCM2835_GPIO_FSEL_INPT); // Sensor -> Input

    while (1) {
        if (bcm2835_gpio_lev(SENSOR) == HIGH) {
            bcm2835_gpio_write(LED, HIGH);
//            printf("Motion Detected\n");
        }
        else {
//            printf("No Motion\n");
            bcm2835_gpio_write(LED, LOW);
        }
    }

    return 0;
}

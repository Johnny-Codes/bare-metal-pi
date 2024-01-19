#include <stdio.h>
#include <bcm2835.h>

void GetDHT11data(uint8_t pin)
{
    bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_write(pin, LOW);
    bcm2835_delayMicroseconds(1000);
    bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_INPT);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <bcm2835.h>

#define DHTPIN 17

int dht11_dat[5] = {0, 0, 0, 0, 0};

int main(int argc, char *argv[])
{
    if (!bcm2835_init())
        return 1;

    float f;

    dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;

    bcm2835_gpio_fsel(DHTPIN, BCM2835_GPIO_FSEL_OUTP);
    bcm2835_gpio_write(DHTPIN, LOW);
    bcm2835_delayMicroseconds(20);
    bcm2835_gpio_write(DHTPIN, HIGH);
    bcm2835_delayMicroseconds(40);
    bcm2835_gpio_fsel(DHTPIN, BCM2835_GPIO_FSEL_INPT);

    int i = 0;
    printf("line 26\n");

    while (bcm2835_gpio_lev(DHTPIN) == 1)
    {
        bcm2835_delayMicroseconds(1);
    }
    printf("line 32\n");
    while (bcm2835_gpio_lev(DHTPIN) == 0)
    {
        bcm2835_delayMicroseconds(1);
    }
    printf("Line 37\n");

    for (i = 0; i < 40; ++i)
    {
        printf("i: %i\n", i);

        uint32_t counter = 0; // Move counter initialization here
        printf("counter: %i\n", counter);

        while (bcm2835_gpio_lev(DHTPIN) == 1)
        {
            bcm2835_delayMicroseconds(1);
        }

        while (bcm2835_gpio_lev(DHTPIN) == 0)
        {
            bcm2835_delayMicroseconds(1);
            counter++;
        }

        dht11_dat[i / 8] <<= 1;
        if (counter > 30)
            dht11_dat[i / 8] |= 1;
    }

    printf("H: %d.%d%% T: %d.%dC\n", dht11_dat[0], dht11_dat[1], dht11_dat[2], dht11_dat[3]);

    bcm2835_close();

    return 0;
}


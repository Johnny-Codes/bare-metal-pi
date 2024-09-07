#include <bcm2835.h>
#include <stdio.h>
#include <unistd.h>

const int AirValue = 520;
const int WaterValue = 260;
int intervals = (AirValue - WaterValue) / 3;
int soilMoistureValue = 0;

#define PIN RPI_GPIO_P1_11 // Assuming analog pin 0 is connected to GPIO pin 17 (BCM)

int main(int argc, char **argv) {
    if (!bcm2835_init()) {
        printf("bcm2835_init failed. Are you running as root??\n");
        return 1;
    }

    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_INPT); // Set pin as input
    printf("yay\n");
    while (1) {
        // Read analog value by checking GPIO pin status
        soilMoistureValue = bcm2835_gpio_lev(PIN);
        
        if (soilMoistureValue > WaterValue && soilMoistureValue < (WaterValue + intervals)) {
            printf("Very Wet\n");
        } else if (soilMoistureValue > (WaterValue + intervals) && soilMoistureValue < (AirValue - intervals)) {
            printf("Wet\n");
        } else if (soilMoistureValue < AirValue && soilMoistureValue > (AirValue - intervals)) {
            printf("Dry\n");
        }

        usleep(100000); // 100ms delay
    }

    bcm2835_close();
    return 0;
}


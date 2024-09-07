#include <bcm2835.h>
#include <stdio.h>
#include <unistd.h>

#define SENSOR_PIN RPI_GPIO_P1_11 // Define the GPIO pin connected to the sensor

void setup() {
    if (!bcm2835_init()) {
        printf("bcm2835_init failed. Are you running as root?\n");
        return;
    }
    bcm2835_gpio_fsel(SENSOR_PIN, BCM2835_GPIO_FSEL_INPT); // Set the sensor pin as input
    bcm2835_gpio_set_pud(SENSOR_PIN, BCM2835_GPIO_PUD_UP); // Enable pull-up resistor
}

int main() {
    setup();

    while (1) {
        // Read the sensor value
        int sensorValue = bcm2835_gpio_lev(SENSOR_PIN);

        // Print the sensor value
        printf("Sensor value: %d\n", sensorValue);

        // Wait for a short interval before reading again
        usleep(500000); // 500 milliseconds
    }

    bcm2835_close();
    return 0;
}


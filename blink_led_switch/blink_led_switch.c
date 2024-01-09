#include <stdio.h>
#include <bcm2835.h>

#define LED    RPI_GPIO_P1_11 // LED on pin 17
#define BUTTON RPI_GPIO_P1_12 // Button on pin 18

int main() {
    if (!bcm2835_init()) return 1; // Initialize bcm2835
    printf("bcm2835 initialized\n");

    bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP);  // Set LED as output
    bcm2835_gpio_fsel(BUTTON, BCM2835_GPIO_FSEL_INPT); // Set button as input

    bcm2835_gpio_set_pud(BUTTON, BCM2835_GPIO_PUD_UP); // Pull-up button to HIGH

    while (1) {
        // Check if button is pressed (LOW)
        if (bcm2835_gpio_lev(BUTTON) == LOW) {
            printf("Button Pressed\n");

            // Toggle LED
            bcm2835_gpio_write(LED, HIGH);

            // Wait for button release
            while (bcm2835_gpio_lev(BUTTON) == LOW) {
                bcm2835_delay(10); // Adjust delay as needed for debouncing
            }

            // Toggle LED off
            bcm2835_gpio_write(LED, LOW);
        }
    }

    // Clean
    bcm2835_close();
    return 0;
}

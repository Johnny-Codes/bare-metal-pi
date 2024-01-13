#include <stdio.h>
#include <bcm2835.h>

#define LED         RPI_GPIO_P1_12
#define PWM_CHANNEL 0 
#define RANGE       1024

int main(int argc, char **argv)
{
    // initialize bcm
    if (!bcm2835_init()) return 1;
    
    bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_ALT5);
    
    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16); // play with DIVIDER_* to change the clock -> lower will cause flickering
    bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);
    bcm2835_pwm_set_range(PWM_CHANNEL, RANGE / 2); // play with numerator to see pwm effects

    int direction = 1;
    int data = 1;
    
    while (1) {
        if (data == 1) {
            direction = 1;
            bcm2835_delay(5000);
        }
        else if (data == RANGE-1) {
            direction = -1;
            bcm2835_delay(5000);
        }
        data += direction;
        bcm2835_pwm_set_data(PWM_CHANNEL, data);
        bcm2835_delay(1);
    }
    bcm2835_close();
    return 0;
}

// https://www.airspayce.com/mikem/bcm2835/pwm_8c-example.html help

#include <stdio.h>
#include <bcm2835.h>

#define SERVO 18
#define PWM_CHANNEL 0
#define RANGE 180

int main(int argc, char *argv[])
{
    if (!bcm2835_init()) return 1;
    
    printf("Program is starting...\n");

//    bcm2835_gpio_fsel(SERVO, BCM2835_GPIO_FSEL_ALT5); // selects alt function
//    bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);

    int i = 180;

    for (i = 180; i >= 0; i--) {
        printf("i: %i\n", i);
        bcm2835_gpio_set(SERVO);
        bcm2835_delayMicroseconds(10.3*i + 546);
        bcm2835_gpio_clr(SERVO);
        bcm2835_delayMicroseconds(20000 - 10.3*i + 546);
    }

}

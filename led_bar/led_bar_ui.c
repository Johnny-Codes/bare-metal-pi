#include <stdio.h>
#include <bcm2835.h>
#include <ctype.h>

#define ledCount 10
int pins[ledCount] = { 17, 18, 27, 22, 23, 24, 25, 2, 3, 8 };

// How to handle user inputting a char
int userPrompt()
{
    int x = -1;
    printf("Number 1-10\n");
    scanf("%d", &x);
    printf("selected %d\n", x);
    if (x <= 10 && x >= 1) {
        printf("Yay?\n");
        return x;
    } else {
        printf("not yay\n");
        x = -1;
        userPrompt();
    }
}   

int main(int argc, char **argv)
{
    int i;
    
    if (!bcm2835_init()) return 1;
    
    printf("\nInitialized\n");
    
    // initialize userLights for userPrompt()
    int userLights = userPrompt(); 

    printf("userLights: %i\n", userLights);
    
    // set all pins to output
    for (i = 0; i < ledCount; ++i) {
        bcm2835_gpio_fsel(pins[i], BCM2835_GPIO_FSEL_OUTP);
    }

    printf("Turning on %d lights\n", userLights);
    
    while (1) {
        for (i = 0; i < userLights; ++i) {
            bcm2835_gpio_write(pins[i], LOW);
        }
        for (i = userLights; i <= ledCount; ++i) {
            bcm2835_gpio_write(pins[i], HIGH);
        } 
    }
    
    bcm2835_close();
    return 0;
}

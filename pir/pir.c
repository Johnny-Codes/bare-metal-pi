#include <stdio.h>
#include <bcm2835.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>

#define LED    18
#define SENSOR 17

void handle_sigint(int sig)
{
    printf("\nReceived Ctrl+C. Cleaning up...\n");
    bcm2835_gpio_write(LED, LOW);
    bcm2835_close();

    printf("Cleanup complete. Exiting.\n");
    exit(EXIT_SUCCESS);
}

void capture_image()
{
//    time_t t;
//    struct tm *current_time;

//    time(&t);
//    current_time = localtime(&t);

    system("fswebcam -r 1280x720 --no-banner image.jpg");
    printf("Image captured.\n");
    
}


int main(int argc, char *argv[])
{
    signal(SIGINT, handle_sigint);
    
    if (!bcm2835_init()) {
        printf("Error initailzing BCM. Exiting.\n");
        return EXIT_FAILURE;
    }

    bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP); // LED -> Output
    bcm2835_gpio_fsel(SENSOR, BCM2835_GPIO_FSEL_INPT); // Sensor -> Input

    while (1) {
        if (bcm2835_gpio_lev(SENSOR) == HIGH) {
            bcm2835_gpio_write(LED, HIGH);
            capture_image();
            printf("Motion Detected\n");
        }
        else {
            printf("No Motion\n");
            bcm2835_gpio_write(LED, LOW);
        }
    }

    return 0;
}

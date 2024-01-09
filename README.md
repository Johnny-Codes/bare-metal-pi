My knowledge for bare metal programming on an RPi 4 Model B

## Libraries

- bcm2835.h - https://github.com/janne/bcm2835/blob/master/bcm2835.h

## Common Commands

- gcc -o output-filename input-filename -lbcm2835  

## Learning Resources
- youtube.com/@SpazztechLLC

- youtube.com/@lowleveldevel1712

- github.com/s-matyukevich/raspberry-pi-os

- youtube.com/@LowLevelLearning

## Using the bcm2835.h
```
wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.69.tar.gz
tar -zxvf bcm2835-1.69.tar.gz
cd bcm2835-1.69
./configure
make
sudo make install
```

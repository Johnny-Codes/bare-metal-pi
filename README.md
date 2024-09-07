#Bare Metal C Programming on a Raspberry Pi 4 Model B

My knowledge for bare metal programming on an RPi 4 Model B

## Libraries

- bcm2835.h - https://github.com/janne/bcm2835/blob/master/bcm2835.h

## Common Commands

### Making files

- gcc -o output-filename input-filename -lbcm2835  

### Copy img from RPi to PC

- scp <from> <to> 

ie. scp rpi@raspberrypi.local .

### Apache server

start command: sudo systemctl start apache2.service

stop command: sudo systemctl stop apache2.service

restart command: sudo systemctl restart apache2.service

status command: sudo systemctl status apache2.service

## Learning Resources

### Bare Metal Coding

- youtube.com/@SpazztechLLC

- youtube.com/@lowleveldevel1712

- github.com/s-matyukevich/raspberry-pi-os

- youtube.com/@LowLevelLearning

- youtube.com/watch?v=mshVdGIGwBs

- youtube.com/@Core-Electronics

- youtube.com/@EnginerringMindset

### Electronics/Electronics Engineering

- https://www.youtube.com/@SimplyElectronicsOfficial

## Using the bcm2835.h

```
wget http://www.airspayce.com/mikem/bcm2835/bcm2835-1.69.tar.gz
tar -zxvf bcm2835-1.69.tar.gz
cd bcm2835-1.69
./configure
make
sudo make install
```

## Installing Apache2 (Linux/Unix)

```
sudo apt update
sudo apt upgrade
sudo apt install apache2
```

https://www.digitalocean.com/community/tutorials/how-to-serve-django-applications-with-apache-and-mod_wsgi-on-ubunty-16-04

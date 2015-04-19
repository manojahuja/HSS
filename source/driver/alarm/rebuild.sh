
#!/bin/sh
module="gpio_drv"
device="gpio_drv"
mode="666"

host_ip="10.0.0.2"
raspi_ip="10.0.0.1"
raspi_username="pi"
raspi_password="raspberry"

echo "===========================make output ========================================"

#building kernel module

CCPREFIX=$HOME/Manoj/raspberrypi/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf- 

ARCH=arm CROSS_COMPILE=$CCPREFIX make -j8 

#building application code
$HOME/Manoj/raspberrypi/tools-master/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-gcc check.c -o check.out

echo "==============================================================================="

current_directory=$(pwd)

#transferring relevant files tp rpi board
echo "copying .ko file to raspberry pi board"
sshpass -p 'raspberry' scp -o StrictHostKeyChecking=no $current_directory/"$device".ko pi@"$raspi_ip":/home/pi/mymodule/

echo "copying check.out file to raspberry pi board"
sshpass -p 'raspberry' scp -o StrictHostKeyChecking=no $current_directory/check.out pi@"$raspi_ip":/home/pi/mymodule/

echo "copying check.sh file to raspberry pi board"
sshpass -p 'raspberry' scp -o StrictHostKeyChecking=no $current_directory/check.sh pi@"$raspi_ip":/home/pi/mymodule/


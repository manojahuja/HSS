#!/bin/arh
module="gpio_drv"
device="gpio_drv"




echo "=========================== module instertion and device node creation  ========================================"

lsmod_r=$(lsmod | awk '//gpio_drv{ print $1}')

if [ "$lsmod_r" = "$device" ]
then
	echo "$device" "already exists. Need to be removed first"
	rmmod "$device"	        
fi      

lsmod_r=$(lsmod | awk '/gpio_drv/{ print $1}')
echo $lsmod_r

if [ "$lsmod_r" = "$device" ]
then
	echo "$device" " not removed :("
else
	echo "$device" "doesnot exist"   
fi      

echo "inserting "$device" using insmod"
insmod "$device".ko

major=$(awk '/gpio_drv/ { print $1 }' /proc/devices)
echo "major number of inserted "$device" module is " $major

major=$(awk '/gpio_drv/ { print $1 }' /proc/devices)

dev_drv_nod=$(ls /dev/gpio_drv | awk '{ print }')

if [ "$dev_drv_nod" = "/dev/gpio_drv" ]
then
	echo "$device"" node exists"
        #echo "removing existing device driver node under /dev/"
        #echo "/dev/$device"
        #rm -f /dev/$device
else
	echo "creating device driver node under /dev/"
        mknod -m 666 /dev/$device c $major 0
fi

echo "=================================================================================="



echo "===========================check.c output ========================================"
echo "executing user space application program"
./check.out
echo "=================================================================================="




echo "===========================tailed dmesg output ==================================="
dmesg | tail
echo "=================================================================================="

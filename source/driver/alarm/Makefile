
# kernel build system and can use its language. 

ifneq ($(KERNELRELEASE),)
	#gpio_drv-objs := gpio.o  
	obj-m := gpio_drv.o

# otherwise we were called directly from the command
# line; invoke the kernel build system
else

	# KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	# KERNELDIR ?= /home/manoj/Manoj/raspberrypi/new/linux
	KERNELDIR ?= /home/manoj/Manoj/buildroot/rpi-buildroot/output/build/linux-rpi-3.19.y
# The current directory is passed to sub-makes as argument
	PWD := $(shell pwd)


default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	#$(MAKE) -C $(KERNELDIR) M=$(PWD) LDDINC=$(PWD)/../include modules


endif

clean:
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions *.order *.symvers *.out

depend .depend dep:
	$(CC) $(CFLAGS) -M *.c > .depend


ifeq (.depend,$(wildcard .depend))
	include .depend
endif

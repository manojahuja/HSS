#ifndef _GPIO_DRV_H_
#define _GPIO_DRV_H_


#define GPIO_DRV_IOCTL_MAGIC 'p'
 

struct gpio_drv_dev {
  int gpio_pin_number;
  struct cdev cdev;	/* Char device structure		*/
};

//void __exit gpio_drv_cleanup_module(void);

/*
* Prototypes for shared functions
*/


int gpio_drv_open(struct inode *inode, struct file *filep);
int gpio_drv_release(struct inode *inode, struct file *filep);

#endif // _GPIO_DRV_H

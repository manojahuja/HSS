#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>   /* dev_t,  */
#include <linux/kdev_t.h>  /* MKDEV */   
#include <linux/fs.h>	   /* everything... */
#include <linux/slab.h>	   /* kmalloc */
#include <linux/cdev.h>	   /* cdev */
#include <linux/semaphore.h>	   /* sema_init */
#include <asm/uaccess.h>	/* copy_*_user */
//#include <asm/semaphore.h>	/* init_MUTEX */ file does not exist anymore
#include <linux/ioctl.h>
#include <mach/platform.h>  /* GPIO base address */ 
#include <asm/io.h> 
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/irq.h>
#include <linux/jiffies.h>
#include "switch_drv.h"		/* local definitions */

#define GPIO_DRV_IOCTL_SETGPIO  _IO(GPIO_DRV_IOCTL_MAGIC, 1)
#define GPIO_DRV_IOCTL_RESETGPIO _IO(GPIO_DRV_IOCTL_MAGIC, 2)
#define GPIO_DRV_MAX_NR 2

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Manoj Ahuja");
MODULE_DESCRIPTION("Simple GPIO Toggle Driver");


int gpio_drv_major = 0;
int gpio_drv_minor = 0;


static dev_t devno=0;

struct gpio_drv_dev gpio_drv_device;    /* allocated in char_drv_init */

extern unsigned long volatile jiffies;
struct _Button
{
    unsigned gpio;
    int irq;
    const char* description;
    char last_value;
};
typedef struct _Button Button;

// we want GPIO 3 (pin 5) to generate interrupt
Button Button1 = {3, 0, "Gpio for button1", 1 };

struct GpioRegisters {
	uint32_t GPFSEL[6];
	uint32_t Reserved1;
	uint32_t GPSET[2];
	uint32_t Reserved2;
	uint32_t GPCLR[2];
};

struct gpio_number {
	int gpio_num;
};


struct GpioRegisters *s_pGpioRegisters;
static int LedGpioPin;


/****************************************************************************/
/* IRQ handler - fired on interrupt                                         */
/****************************************************************************/
static irqreturn_t irq_handler(int irq, void *dev_id, struct pt_regs *regs) 
{
   Button* button = (Button*) dev_id; 
   char value = gpio_get_value(button->gpio);

   if (value == button->last_value)
       return IRQ_HANDLED;

   if (0 == value)
   {
        static unsigned long old_jiffie = 0;
        unsigned long diff = jiffies - old_jiffie;
        if (diff < 23)
        {
          button->last_value = value;
          irq_set_irq_type(irq, IRQ_TYPE_LEVEL_HIGH);
          // old_jiffie = jiffies;
          return IRQ_HANDLED;
        }

        printk(KERN_NOTICE "Interrupt [%d] for device %s was triggered, jiffies=%lu, diff=%lu, direction: %d \n",
               irq, button->description, jiffies, diff, value);
        irq_set_irq_type(irq, IRQ_TYPE_LEVEL_HIGH);
        old_jiffie = jiffies;
   }

   else
   {
     irq_set_irq_type(irq, IRQ_TYPE_LEVEL_LOW);
   }

   button->last_value = value;
   return IRQ_HANDLED;
}
/****************************************************************************/
/* This function configures interrupts.                                     */
/****************************************************************************/
void int_config(Button* button)
{
   if (!button || gpio_request(button->gpio, button->description)) {
      printk("GPIO request faiure: %s\n", button->description);
      return;
   }
   gpio_direction_input(button->gpio);

   if ( (button->irq = gpio_to_irq(button->gpio)) < 0 ) {
      printk("GPIO to IRQ mapping faiure %s\n", button->description);
      return;
   }

   printk(KERN_NOTICE "Mapped int %d\n", button->irq);

   if (request_irq(button->irq,
                   (irq_handler_t ) irq_handler,
                   IRQF_TRIGGER_LOW,
                   button->description,
                   button)) {
      printk("Irq Request failure\n");
      return;
   }
   return;
}

/****************************************************************************/
/* This function releases interrupts.                                       */
/****************************************************************************/
void int_release(Button* button) {

   free_irq(button->irq, button);
   gpio_free(button->gpio);

   return;
}
static void SetGPIOFunction(int GPIO, int functionCode) {
	int registerIndex = GPIO / 10;
	int bit = (GPIO % 10) * 3;

	unsigned oldValue = s_pGpioRegisters->GPFSEL[registerIndex];
	unsigned mask = 0b111 << bit;
	printk(KERN_ALERT "Changing function of GPIO %d from %x to %x\n", GPIO, (oldValue >> bit) & 0b111, functionCode);
	s_pGpioRegisters->GPFSEL[registerIndex] = (oldValue & ~mask) | ((functionCode << bit) & mask);
	printk("old value of GPIO select register %d \n", oldValue);
	printk("new value of GPIO select register %d \n", s_pGpioRegisters->GPFSEL[registerIndex]);
}

static void SetGPIOOutputValue(int GPIO, bool outputValue)
{
	if (outputValue)
		s_pGpioRegisters->GPSET[GPIO / 32] = (1 << (GPIO % 32));
	else
		s_pGpioRegisters->GPCLR[GPIO / 32] = (1 << (GPIO % 32));
	printk("setting value of gpio pin GPIO %d to %d", GPIO, outputValue);
}


static int LedDev_probe(struct gpio_drv_dev *dev) {
	printk(KERN_ALERT "gpio Driver: led dev probe()\n");
	LedGpioPin = dev->gpio_pin_number;
	s_pGpioRegisters = (struct GpioRegisters *)__io_address(GPIO_BASE);
	SetGPIOFunction(LedGpioPin, 0b001);     //Configure the pin as output
	return 0;
}
/*
 * Open and close
 */

int gpio_drv_open(struct inode *inode, struct file *filp) {
	printk(KERN_ALERT "gpio Driver: open()\n");
	int_config(&Button1);	
	return 0;
}

int gpio_drv_release(struct inode *inode, struct file *filp) {	
	printk(KERN_ALERT "gpio Driver: release()\n");
	int_release(&Button1);
	return 0;
}

/*
 * ioctl implementation
 */

long gpio_drv_ioctl(struct file *filep, unsigned int cmd, unsigned long arg) {
	int err=0; 
	long ret=0;
  
	printk(KERN_ALERT "GPIO Driver: gpio_drv_ioctl\n");
	// dont even decode wrong commands: better return ENOTTY than EFAULT
	if(_IOC_TYPE(cmd) != GPIO_DRV_IOCTL_MAGIC)
		return -ENOTTY;
	if(_IOC_NR(cmd) > GPIO_DRV_MAX_NR)
		return -ENOTTY;
	/*
	* the type is a bitmask, and VERIFY_WRITE catches R/W
	* transfers. Note that the type is user-oriented, while
	* verify_area is kernel-oriented, so the concept of "read" and
	* "write" is reversed
	*/
	if (_IOC_DIR(cmd) & _IOC_READ)
		err = !access_ok(VERIFY_WRITE, (void __user *)arg, _IOC_SIZE(cmd));
	else if (_IOC_DIR(cmd) & _IOC_WRITE)
		err =  !access_ok(VERIFY_READ, (void __user *)arg, _IOC_SIZE(cmd));
	if (err)
		return -EFAULT;

	switch(cmd) {

		case GPIO_DRV_IOCTL_SETGPIO: // set gpio pin
			SetGPIOOutputValue(gpio_drv_device.gpio_pin_number, 1);
			break;

		case GPIO_DRV_IOCTL_RESETGPIO: // reset gpio pin
			SetGPIOOutputValue(gpio_drv_device.gpio_pin_number, 0);
			break;

		default:  /* redundant, as cmd was checked against MAXNR */
			return -ENOTTY;
	}	

	return ret;

}


struct file_operations char_drv_fops = {
	.owner		= THIS_MODULE,
	.unlocked_ioctl	= gpio_drv_ioctl,
	.open		= gpio_drv_open,
	.release	= gpio_drv_release,
};


/*
 *  * Set up the gpio_dev structure for this device.
 *   */
static void gpio_drv_setup(struct gpio_drv_dev *dev, int index)
{
	
	// index will be used in case of multiple instances of char_drv
	// until then value 0 will be used
	//
  
	int err, devno = MKDEV(gpio_drv_major, gpio_drv_minor + index);
		    
	printk(KERN_ALERT "gpio Driver: gpio drv setup()\n");
	
	
	dev->gpio_pin_number=2;
	LedDev_probe(dev);
	cdev_init(&dev->cdev, &char_drv_fops);
	dev->cdev.owner = THIS_MODULE;

	err = cdev_add(&dev->cdev, devno, 1);

	/* Fail gracefully if need be */
	if (err)
		printk(KERN_NOTICE "Error %d adding char_drv%d", err, index);
  
}


static int __init gpio_drv_init(void) {

	int result;
	
	printk(KERN_ALERT "Registering link Device Driver\n");
	
	result = alloc_chrdev_region(&devno, 0, 1, "gpio_drv");
	gpio_drv_major = MAJOR(devno);
	gpio_drv_minor = MINOR(devno);
	
	if (result < 0) {
		printk(KERN_ALERT "gpio_drv can't get major %d\n",gpio_drv_major);
		return result;
	}

	gpio_drv_setup(&gpio_drv_device, 0);
	
	return 0; /* succeed */

}


/*
 * The cleanup function is used to handle initialization failures as well.
 * Thefore, it must be careful to work correctly even if some of the items
 * have not been initialized
 */

void __exit gpio_drv_cleanup_module(void) {
	cdev_del(&gpio_drv_device.cdev);
	printk(KERN_ALERT "Un-Registering Led Device Driver\n");
  
	SetGPIOFunction(LedGpioPin, 0);//Configure the pin as input
	
	/* cleanup_module is never called if registering failed */
	unregister_chrdev_region(devno, 1);
}


module_init(gpio_drv_init);
module_exit(gpio_drv_cleanup_module);

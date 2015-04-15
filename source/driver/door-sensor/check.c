
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>


#define GPIO_DRV_IOCTL_MAGIC 'p'
#define GPIO_DRV_IOCTL_SETGPIO _IO(GPIO_DRV_IOCTL_MAGIC, 1) 
#define GPIO_DRV_IOCTL_RESETGPIO _IO(GPIO_DRV_IOCTL_MAGIC, 2) 


int main(void) {

	char data[100];
	int return_value;
	int fc = open("/dev/gpio_drv",O_RDWR);
	
	
	printf("Open file/device returned file descriptor: %d\n",fc);
	if (fc < 0)
		printf ("Device file open returned error %d.\n",fc);


	while(1) {

		char user_select_input,input_char;
		int char_count,complete=0;
		
		printf("---------------------------------\n");
		printf("Enter the operation \n    s=set gpio pin\n    r=reset gpio pin\n    q=quit\n");
		printf("---------------------------------\n");
		
		scanf(" %c", &user_select_input);
		
		printf("=================================\n");
		printf("Entered character is %c\n", user_select_input);


		switch (user_select_input) {
			case 's':
				printf("issuing ioctl command to set the gpio pin to turn the LED ON\n");
				return_value = ioctl(fc, GPIO_DRV_IOCTL_SETGPIO);
				if (return_value < 0)
					printf ("Set gpio ioctl returned error %d.\n",return_value);
				else
					printf("Set gpio ioctl executed successfully\n");
				break;
			case 'r':
				printf("issuing ioctl command to set the gpio pin to turn the LED OF\n");
				return_value = ioctl(fc, GPIO_DRV_IOCTL_RESETGPIO);
				if (return_value < 0)
					printf ("Reset gpio ioctl returned error %d.\n",return_value);
				else
					printf("Reset gpio ioctl executed successfully\n");
				break;
			case 'q':
				printf("Quiting\n");
				complete=1;
				break;
			default:
				printf("invalid character entered\n");

		}
		if(complete)
			break;
		
	}

	perror("Error/Success: ");
	close(fc);
	perror("Error/Success: ");
	return EXIT_SUCCESS;

}

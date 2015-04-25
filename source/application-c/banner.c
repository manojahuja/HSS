#include <stdio.h>
#define MAX_LEN 10
 
 
void printBanner(void) {
	char read_string[MAX_LEN];
	
	char *filename = "Banner.txt";
	FILE *fptr = NULL;

	if((fptr = fopen(filename,"r")) == NULL) {
	        fprintf(stderr,"error opening %s\n",filename);
	        return;
	}
	
	     
        while(fgets(read_string,sizeof(read_string),fptr) != NULL)
		printf("%s",read_string);
	fclose(fptr);
}

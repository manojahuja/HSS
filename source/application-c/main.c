#include<stdio.h>
#include "HumanInterface.h"

int main() {


	init_userInterfaceSM(); 

	while(1) {
		userInterfaceSM();
	}

	
	return 0;
}





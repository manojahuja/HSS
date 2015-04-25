#include "HumanInterface.h"
#include "stdio.h"
#include "banner.h"

void init_userInterfaceSM() {
	printBanner();
}


void userInterfaceSM(){ 
	typedef enum {
		Default_st,
		Admin_st,
		User_st,
		UserAuthentication_st,
		NumberOfStates
	} UI_EngineStates_t;
	

	UI_EngineStates_t previousState=Default_st, currentState=Default_st;

	int userChoice;

	switch (currentState) {
		case Default_st:
				if(currentState!=previousState) {
					// write state entry code here
					previousState=currentState;
					// write the transtions here
				}
				printf("please enter the choice 1. user 2. admin\n");
				scanf("%d",&userChoice);
				printf("user has enterred the choice %d\n",userChoice);
				if (userChoice==1)
					currentState=User_st;
				 else if (userChoice==2) 
					currentState=Admin_st;
			else 
				printf("user has entered the wrong selection value\n");
		
			break;
	
		case User_st:


			//passwordManagement.requestAuthentication('user','password');
			break;
	}	


}

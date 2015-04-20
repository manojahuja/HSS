#include "HumanInterface.h"
#include "stdio.h"

// constructor

void init_userInterfaceSM() {
	cout << string (35,'\n') ;
	cout << "==========================================================================\n" ;
	cout << "                 Welcome to Home Security System App                      \n" ;
	cout << "==========================================================================\n" ;


}

void userInterfaceSM() {
	typedef enum {
		Default_st,
		Admin_st,
		User_st,
		UserAuthentication_st,
		NumberOfStates
	} UI_EngineStates_t ;


	static UI_EngineStates_t previousState=Default_st, currentState=Default_st;

	int userChoice;

	switch (currentState) {
		case Default_st:
			if(currentState!=previousState) {
				// write state entry code here
				previousState=currentState;
			// write the transtions here
			//
			if (userChoice==1)  {
				currentState=User_st;
			} else if (userChoice==2) {
				currentState=Admin_st;
			} else {
				cout << "user has entered the wrong selection value\n";
			}
			break;
	
		case User_st:


			//passwordManagement.requestAuthentication('user','password');
			break;
	}	

}


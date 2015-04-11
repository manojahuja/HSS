#include "HumanInterface.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

// constructor

void init_userInterfaceSM() {
	cout << string (35,'\n') ;
	cout << "==========================================================================\n" ;
	cout << "                 Welcome to Home Security System App                      \n" ;
	cout << "==========================================================================\n" ;


}
HumanInterface::HumanInterface(int sysState):systemState(sysState) {
		init_userInterfaceSM();	
	}

void HumanInterface::userInterfaceSM() {
	typedef enum {
		Default_st,
		Admin_st,
		User_st,
		UserAuthentication_st,
		NumberOfStates
	} UI_EngineStates_t ;


	static UI_EngineStates_t previousState, currentState;

	int userChoice;

	switch (currentState) {
		case Default_st:
			if(currentState!=previousState) {
				// write state entry code here
				previousState=currentState;
			}

			// write state do activity code here
			
			

			cout << "please enter the choice 1. user 2. admin\n";

			cin >> userChoice;

			cout << "user has entered the choice << userChoice\n" ;

			// write the transtions here
			//
			if (userChoice==1) {
				currentState=User_st;
			} else if (userChoice==2) {
				currentState=Admin_st;
			} else {
				cout << "user has entered the wrong selection value\n";
			}
			break;
		case Admin_st:
			if(currentState!=previousState) {
				// write state entry code here
				cout << "entered the admin state\n";
				previousState=currentState;
			}

			// write state do activity code here
			




			// write the transtions here
			//
			if (userChoice==1) {
				currentState=User_st;
			} else if (userChoice==2) {
				currentState=Admin_st;
			} else {
				cout << "user has entered the wrong selection value\n";
			}
			break;
	
		case User_st:
			break;
	}	

}


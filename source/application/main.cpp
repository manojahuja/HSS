#include <iostream>
#include <string>

#include "HumanInterface.h"

using std::cout;
using std::string;

int main() {


	
	HumanInterface humanInterface(0);
	PasswordManagement passwordManagement();

	while(1) {
		humanInterface.userInterfaceSM(passwordManagement);
	}

	
	return 0;
}





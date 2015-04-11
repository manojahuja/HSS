#include <iostream>
#include <string>

#include "HumanInterface.h"

using std::cout;
using std::string;

int main() {


	
	HumanInterface humanInterface(0);

	while(1) {
		humanInterface.userInterfaceSM();
	}

	
	return 0;
}





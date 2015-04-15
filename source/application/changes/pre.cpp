#include <iostream>
#include "string.h"
#include"stdlib.h"

#define NEWLINE 0;

using std::cin;
using std::cout;
using std::string;
using std::endl;
//--------------------------------------------------------------------------------
 class HumanInterface {        
private:  char systemName[10];
		   char designBy[10];
             char  commandName[10];   

                                                                    
		   public: 
	 	   int UserInterface(void); 
                   void WhiteSpace(int);
                   void HomeSecurityInfo(void);	 
}; 
void HumanInterface:: WhiteSpace(int cursurePosition)
          {

	  int const lineEnd=102;
	  if(cursurePosition>=lineEnd)
		  cout<<"Please Do Not Cross The Limit\n";
	    else
		     {
	  	for(int start=1;start<=cursurePosition;start++)
                    cout<<"=";
		     }
  
	  };

void HumanInterface::HomeSecurityInfo(void)
{
system("reset");
strcpy (this->systemName,"Home Security Alaram System");
strcpy((this->commandName),"@@@@@");
strcpy((this->designBy),"SiddhiVinayaka");
strcpy((this->commandName),"@@@@@");
//cout<<systemName<<commandName<<designBy;
};

	
int  HumanInterface::UserInterface(void) {

                      HomeSecurityInfo();
      cout<<"==========================================================================\n" ;
                 cout<<WhiteSpace(35)<<systemName<<endl;
      cout<<"==========================================================================\n";
                   	cout<<"Enter You Choice\n";
			cout << "please enter the choice 1. user 2. admin\n";
int userType;
			cin >> userType;

			cout << "user has entered the choice << userChoice\n" ;

			// write the transtions here
			//
			if (userType==1) {
				cout<<"Welcome To Admin\n";
			}
			  else if (userType==2) 
			  { cout<<"User Interface\n";
				
			} else
		       	{
				cout << "\nuser has entered the wrong selection value\n";
			
			}
			return 0;
};
		
			
int main()
{
int userType;
HumanInterface test;
test.UserInterface();

};


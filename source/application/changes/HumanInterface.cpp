#include"system.h"
//#include "string.h"
//#include"stdlib.h"
//#include"SystemControllerI.cpp"
//#define NEWLINE 0;
/*
using std::cin;
using std::cout;
using std::string;
using std::endl;
#define NEWLINE 0;
*/

//--------------------------------------------------------------------------------
//class SystemController ;

class HumanInterface {        
	private:  char systemName[20];
		  char designBy[20];
                  char  commandName[20];   

                                                                    
		   public: 
	 	   int UserInterface(void); 
                   void WhiteSpace(int,char);
                   void HomeSecurityInfo(void);	 
		   void Banner();
//		   friend SystemController::DesignFuncion(HumanInterface);
}; 
void HumanInterface:: WhiteSpace(int cursurePosition,char data)
          {
           int const lineEnd=103;

	  if(cursurePosition>lineEnd)
		  cout<<"Please Do Not Cross The Limit\n";
	    else if(cursurePosition<=102&&data=='=')
		     {
	  	for(int start=1;start<=cursurePosition;start++)
                    cout<<"=";
		     }
	  else{
	     
	  	for(int start=1;start<=cursurePosition;start++)
	      cout<<" ";
	  }
           //   cout<<endl;
	  };

void HumanInterface::Banner(){
	system("reset");
	WhiteSpace(102,'=');
	WhiteSpace(32,' ');
	cout<<systemName<<endl;       
	WhiteSpace(102,'=');
	cout<<endl;
       
};
void HumanInterface::HomeSecurityInfo(void)
{

strcpy (this->systemName,"Home Security Alaram System");
strcpy((this->commandName),"@@@@@");
//strcpy((this->designBy),"SiddhiVinayaka");
strcpy((this->commandName),"@@@@@");
//cout<<systemName<<commandName<<designBy;
};

	
int  HumanInterface::UserInterface(void) {
			   HomeSecurityInfo();
                           //
		   	   //cout<<systemName<<endl;	   
                           //WhiteSpace(102);  
		                Banner();	   
                   		cout<<"Enter You Choice\n";
				cout<<"please enter the choice 1. user 2. admin\n";
				int userType;
				cin>>userType;

				cout<<"user has entered the choice << userChoice\n" ;

			// write the transtions here
			//
			if (userType==1) {
				strcpy(this->commandName,"Admin#~> "); 
				cout<<"Enter Password\n";
				
				cout<<commandName;
				cin>>userType;
                                Banner();
			
			}
			  else if (userType==2) 
			  { 
		             strcpy(this->commandName,"User#~> ");
			     cout<<"Enter Password ";
			     cout<<commandName;
			     cin>>userType;
			     Banner();
				
			} else
		       	{
				cout << "\nuser has entered the wrong selection value\n";
			
			}
			return 0;
};
		
			
/*int main()
{}*/

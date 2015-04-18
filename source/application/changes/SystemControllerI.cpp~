#include"system.h"
#define ALERT 10
using std::cin;
using std::cout;
 using std::string;
using namespace std;

//--------------------------------Please Write in Seprate file And name it System.h

class SystemControllerI {
	private : int userType,attemp;
        private :char password[10];
		 char userName[10];
	private : //int SetSysStat();
	public : int SelfCheck(int);	
	public  : int Authentication(int);
	public : int InvokePassword(class);	  
		   //friend GetAuthentication();

		 int getch(void);
	      // int SetAlaramStat();		  
		  	};
//----------------------------X-----------X--------------X-----------X-----------------
int SystemControllerI::InvokePassword(class temp)
{
                     

return(0);
};

int SystemControllerI::getch(void)
    {
	   struct termios oldattr, newattr;
	        int ch;
		  tcgetattr( STDIN_FILENO, &oldattr );
	  	      newattr = oldattr;
			   newattr.c_lflag &= ~( ICANON | ECHO );
		     tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
	          ch = getchar();
	     tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
        return ch;

};
int SystemControllerI::SelfCheck(int a)
	{
	char tempPass[10],tempPass2[10];
			int i=0;
		 	
				loop: i = i + 1;
		 	for(int i=0; i<10; tempPass[i]='\0',tempPass2[i]='\0',++i);
				cout<<"Enter Your Password\n";
                                int lop=0;
					while(1)
						{
						  tempPass[lop]=getch();

	                                            if(lop==10||tempPass[lop]==10)
	                                                {
							if(lop==10&&tempPass[lop]!=10)
							 {
	 						cout<<"Passward is Too Long Please Retype\n";
	 							system("pause");
                                                             	 goto  loop;
						         }
							++lop;
			                                tempPass[lop]='\0';
				  			break;
							}
						    						
	                                    lop++;
			                        }

                     			cout<<"Retype Your Passowrd";
		               
				lop=0;
		
					while(1)
						{
						  tempPass2[lop]=getch();

	                                            if(lop==10||tempPass2[lop]==10)
	                                                {
							if(lop==10&&tempPass2[lop]!=10)
							 {
	 						cout<<"Passward is Too Long Please Retype\n";
	 							system("pause");
                                                             	 goto  loop;
						         }
							++lop;
			                                tempPass2[lop]='\0';
				  			break;
							}
						    						
	                                    lop++;
			                        }

int t=strcmp(tempPass,tempPass2);
				 if(t==0)
				{
                                //cout<<t;
				 return t;
					
				}
				 else if(i<3)
					  {
					system("reset");
					       	 
//Banner;
 goto loop;
					  } 
				 	 
					else{
					return(ALERT);
		                              
					    }

				};
			

			



int  SystemControllerI::Authentication(int retVal) 
		{
			int retValue,userType;
			SelfCheck(1);
			if(retValue==10)
			 	 cout<<"Alert\n"; 
			      //System Satate 1 automatic;and Call Alaram 
			
			else if((retValue==0)&&(userType=1))
			      //Admin Management;
			{}
			else if((retValue==1)&&(userType==2))
			{}            //User Management;
		
		};
				


//reading a text file
//#include"SystemStat.h"
//#include"system.h"
//#define 1 Admin
//#define 2 User
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
		   //friend GetAuthentication();

		  
	  	 // int SetAlaramStat();		  
		  	};
//----------------------------X-----------X--------------X-----------X-----------------


int SystemControllerI::SelfCheck(int attemp)
	{
	char tempPass[10],tempPass2[10];
			int i=0;
		 	
				loop: i = i + 1;
		 	for(int i=0; i<10; tempPass[i]='\0',tempPass2[i]='\0',++i);
				cout<<"Enter Your Password\n";
                       		cin>>tempPass;
				cout<<"Retype Your Passowrd";
		                cin>>tempPass2;
			        int t=strcmp(tempPass,tempPass2);
				 if(t==0)
				{
                                //cout<<t;
				 return t;
					
				}
				 else if(i<3)
					  {
					system("reset");
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
				
//int main()

//	int userType=0;
  //     cout<<"HEllo";
//	SystemControllerI PCHECK;
//	int ret;
//	cout<<ret;
//	ret=PCHECK.SelfCheck(0);
  //       if(ret==0&&userType==1)
//		 int s;
             // GetPassword(userType);
//	 else if(ret==1&&userType==2)
	//	
//		 int t;
//		 GetPassword(userType);
          

//        SystemControllerI Auth;
 //	 ret=Auth.Authentication(ret,userType);
	


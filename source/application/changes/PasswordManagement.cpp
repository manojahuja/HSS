//// reading a text file
//#include"SystemControllerI.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include<string.h>
#define ADMIN 1
#define USER 2
#define DEFAULT 385744
using std::cin;
using std::cout;
using std::string;
using namespace std;
//class SystemControllerI;
//--------------------------------Please Write in Seprate file And name it System.h

class PasswordManagement {
	private :char uPassword[20],aPassword[20],dPassword[20];
		 int userType;
	public : //int SetSysStat();
		  int  SetPassword(int);
		   int GetPassword(int);
//        	  friend int SystemControllerI::InvokePassword(PasswordManagement);//friend
                     int Default(int);
                               
		  
	  	 // int SetAlaramStat();		  
		  };
//----------------------------X-----------X--------------X-----------X-----------------


int  PasswordManagement::SetPassword(int userType) 
		{
		if(userType==ADMIN)
		     {	cout<<"User="<<ADMIN<<endl; 
			   strcpy(this->aPassword,"ADMIN");
			   ofstream myfile;
			   myfile.open("AdminPass.txt");
		           myfile <<aPassword;
			   myfile.close();
					     
			  
			     
			     
			     
			     
			     
			     //Set Password Admin;				
//                       int d;
		     }
		else if(userType==USER)
			{

		       	cout<<"User="<<USER; 
			   strcpy(this->uPassword,"User");
		      cout<<"Check ="<<this->uPassword;
		         ofstream myfile;
			   myfile.open ("UserPass.txt");
			   myfile <<uPassword;
			   myfile.close();
			   
						
				}
                         else if(userType==DEFAULT)
		     		 {	
			     cout<<"Default="<<DEFAULT<<endl; 
			    strcpy(this->dPassword,"DEFAULT");
			    ofstream myfile;
			    myfile.open("DefaultAPass.txt");
		            myfile<<dPassword;
			    myfile.close();
					     
			  
				}
			     
			     
			     
			     
			     //Set Password Admin;				
//                       int d;
		     
			
			};
	


int PasswordManagement::GetPassword(int userType) 
		{
		  int returnStatus;
	 	 if(userType==ADMIN)
			{
		  string line;
	    		ifstream myfile ("AdminPass.txt");
	      			if (myfile.is_open())
		        		{
				    	while ( getline (myfile,line) )
				      	  {
						 cout <<"AdminPass =" <<line << '\n';
				          }								        				myfile.close();
					}
				
	      			  else {
					cout << "Unable to open System file"; 
                                     //return(int(line));
					}
			}
				else if(userType==USER) {				 
					     string line;
	    					ifstream myfile("UserPass.txt");
	      						if (myfile.is_open())
		        			 	{
				    			while( getline (myfile,line) )
				      		  	{
						 	cout <<"UserPassword =" <<line << '\n';
							}
                                                         myfile.close();
						         }
      			 			 else
							cout << "Unable to open System file"; 
		
                                			    //return(int(line));


						}					
				
		
						else if(userType==DEFAULT) {				 
					     string line;
	    					ifstream myfile("DefaultAPass.txt");
	      						if (myfile.is_open())
		        			 	{
				    			while( getline (myfile,line) )
				      		  	{
						 	cout <<"Default=" <<line << '\n';
							}
                                                         myfile.close();
						         }
      			 			 else
							cout << "Unable to open System file"; 

							}			
		
		
		};



int main()
    {

      int userType=1;//Value came from UserInterface;

  PasswordManagement USER_PASSWORD,ADMINPASSWORD;
// cout<<sizeof(USER_PASSWORD);
     	       


//     cout<<"HEllo";
   //   SystemControllerI PCHECK;
     //          int ret;
//	cout<<ret;
       // int   ret=PASSWORD_CHECK.SelfCheck(0);
         //       if(ret==0&&userType==ADMIN)
	//	  ret= PCHECK.InvokePassword(ADMIN_PASSWORD);
	//	else
	//	  ret= PCHECK.InvokePassword(USER_PASSWORD);
             // GetPassword(userType);
//	 else if(ret==1&&userType==2)
	//	
//		 int t;
//		 GetPassword(userType);
          

//        SystemControllerI Auth;
 //	 ret=Auth.Authentication(ret,userType);
              }


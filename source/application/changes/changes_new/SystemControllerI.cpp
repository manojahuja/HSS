

//--------------------------------Please Write in Seprate file And name it System.h


//----------------------------X-----------X--------------X-----------X----------------

      /* int SystemControllerI::InvokePassword(PasswordManagement TEMP_OBJECT,int userType,char *checkPassword)
	{ int  checkPassStat;
                         
                    checkpassStat=TEMP_OBJECT.GetPassword=(userType,*currentPassword);
                              if(userType==1) 
                                   { 
                                  return(strcmp(checkPassword,currentPassword));
                                        
                                   else if
                                          else if
                   	return(strcmp(tempPassword,aPassword));
	};
              return(strcmp(tempPassword,uPassword));
  return(strcmp(tempPassword,dPassword));

//return(0);
//};*/

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
int SystemControllerI::SelfCheck(char *tempPassword)
	{
	char tempPass[20],tempPass2[20];
			int i=0;
		 	
				loop: i = i + 1;
		 	for(int i=0; i<10; tempPass[i]='\0',tempPass2[i]='\0',++i);
 				if(userType==1)
			       cout<<"\t\t\t\t\t""Press Any Key To Procees USER Service !\n";
			         else
                                cout<<"Press Any Key To Proceed Admin Service!\n"; 
                                char demo;
				 demo=getch();
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
	 							//system("pause");
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
	 						cout<<"Password is Too Long Please Retype\n";
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
				{ cout<<"-----------------------:";
                                    strcpy(tempPassword,tempPass2);
                                cout<<t;
				 return t;
					
				}
				 else if(i<3)
					  {
					//system("reset");
					       	 
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
			//SelfCheck();
			if(retValue==10)
			 	 cout<<"Alert\n"; 
			      //System Satate 1 automatic;and Call Alaram 
			
			else if((retValue==0)&&(userType=1))
			      //Admin Management;
			{}
			else if((retValue==1)&&(userType==2))
			{}            //User Management;
		
		};
				


#include"system.h"
#include"HumanInterface.cpp"
#include"SystemControllerI.cpp"
#include"PasswordManagement.cpp"
#include"SystemStat.cpp"



 void Command_Name(HumanInterface TEMP)
     {
     TEMP.Set();
     };		
int main()
      {
       char commandLine[20],ch;
              strcpy(commandLine,"User#~> ");
              HumanInterface HUMAN_OBJECT1;
       char tempPassword[20];
       int userType=HUMAN_OBJECT1.UserInterface();
           //    Command_Name(HUMAN_OBJECT1);
               //HUMAN_OBJECT1.Banner();
                cout<<"USerType= "<<userType<<endl;//usertype
                SystemControllerI PASS_CHECK;
                int setPasswordRet,getPasswordRet,tempAlaramStorage,tempSystemStorage,tempDoorStorage,retPasswordStatus;
                    getPasswordRet=PASS_CHECK.SelfCheck(tempPassword);
	        char retSetSensor,retSetAlaram,dStat,stat,aStat;
		cout<<"PASSWORD="<<tempPassword;
                PasswordManagement USER_PASSWORD,ADMINPASSWORD,DEFAULTPASSWORD;
                getPasswordRet=USER_PASSWORD.GetPassword(userType,tempPassword);//temp password //file not; //Banner
	        cout<<"ReturnValue="<<getPasswordRet;
	       cout<<"\n";
              // PasswordManagement USER_PASSWORD,ADMINPASSWORD,DEFAULTPASSWORD;
       int press;
	        if(userType==USER && getPasswordRet==USER)
	           {
	             strcpy(commandLine,"User#~> ");
			            SystemStat STATUS_SYSTEM;
				    stat=STATUS_SYSTEM.GetSystemStat(1);  //calling get system stat                   
		   //    getPasswordRet=USER_PASSWORD.GetPassword(userType,tempPassword); //temp password //file not;
                          SWITCH_TO_PRESS :
		            cout<<commandLine<<"Press 1 To Change System Settting 2 For Enter Door\n";
			    cout<<commandLine;cin>>press;   //vaidation here!  
                                 if(press==1 && stat==49) //if system is secure
                     		 {
				         aStat=STATUS_SYSTEM.GetAlaramStat(1); //aStat =alaramstatretutn
					 dStat=STATUS_SYSTEM.GetDoorSensorStat(1);//getting sensor status
			                cout<<"dOOR= "<<dStat<<"The Following List\n" ;//you change 
	                                            if(aStat==49) //Alaram ONN
						        { 
                  			               cout<<commandLine<<"Alaram Stat = ON \n";
						       check ://if user enterd insted 1 then it become in loop
						       cout<<commandLine<<"\tPress 1 For Change Stat \t 0 To Exit\n"<<commandLine<<"\t";//enter valid
						       cin>>tempAlaramStorage; //temp variable for storing alaram stat value
						      // retSetAlaram=STATUS_SYSTEM.SetAlaramStat(48);
						       cout<<"\nCheck Retrun status ="<<retSetAlaram;	 
						         if(tempAlaramStorage==1 && aStat==49) 
							 {
								 
						                 retSetAlaram=STATUS_SYSTEM.SetAlaramStat(48);
								 cout<<commandLine<<"SucessFull\n";
								 aStat=48;
							 }         
						         else 
						               cout<<commandLine<<"\tHardware Bussy! Try Later";
							}      
					               else if(aStat==48) //if alaram return off then .
						       { 
						       cout<<commandLine<<"\tAlaram Stat = OFF\n";
	                                               cout<<commandLine<<"\tPress 1 For Change Stat \n 0 To Exit\n"<<commandLine<<"\t";
						       cin>>tempAlaramStorage;
						       //retSetAlaram=STATUS_SYSTEM.SetAlaramStat(49);   
						          if(tempAlaramStorage==1&& aStat==48)//alaram set mei ret value daalni hai    
							      {         
								      retSetAlaram=STATUS_SYSTEM.SetAlaramStat(49);
							               aStat=49;   //alaram stat on
								      cout<<commandLine<<"\t"<<"Alaram Status Changed Sucessfully!\n"; 
							      }   
						           else
						            cout<<commandLine<<"\t Hardware bussy\n";//if Unable to stor Value;
						        }
						       else //If user type invalid number instead 1 0r 0; 
                                                        {
						        cout<<commandLine<<"\nPlease Press Valid Number\n" ;
		      					goto  check ;//switch to check;
                         		                }     
				                   
						       
						       if(dStat==49) //Door Sensor ONN
						        { 
					               cout<<commandLine<<"Door Sensor Stat = ON \n";
						       check2 ://if user enterd insted 1 then it become in loop
						       cout<<commandLine<<"\tPress 1 For Change Stat \t 0 To Exit\n"<<commandLine<<"\t";//enter valid
						       cin>>tempDoorStorage; //temp variable for storing alaram stat value
						       dStat=STATUS_SYSTEM.SetDoorSensorStat(48); 
						       
						       if(tempDoorStorage==1 && dStat==48) 
							 {
		               				       cout<<"SucessFull";  
							       dStat=48;
							 }
							    else 
						               cout<<commandLine<<"\tHardware Bussy! Try Later";
							 } 
					               else if(dStat=48) //if alaram return off then .
						       { 
						       cout<<commandLine<<"\tDoor Sensor Stat = OFF\n";
	                                               cout<<commandLine<<"\tPress 1 For Change Stat \n 0 To Exit\n"<<commandLine<<"\t";
						       cin>>tempDoorStorage;
						       dStat=STATUS_SYSTEM.SetDoorSensorStat(49);   
						          if(tempDoorStorage==1 && dStat==49)//alaarm set mei ret value daalni hai    
							  {   dStat=49;
						              cout<<commandLine<<"\t"<<"Door Sensor Status Changed Sucessfully!\n"; }    
						           else
						            cout<<commandLine<<"\t Hardware bussy\n";//if Unable to stor Value;
						        }
						       else //If us`er type invalid number instead 1 0r 0; 
                                                        {
						        cout<<commandLine<<"\nPlease Press Valid Number\n" ;
		      					goto  check2 ;//switch to check;
                         		                }  
	
		        	} 
		   
	                          else //seconf IF
			    	        { 
					  while(1)
				    	    {
                                            
					    cout<<commandLine<<"Your System Is Not Active .Press 1 For Active 0 For Exit\n ";
					    cin>>ch;
					    if(ch==48) 
						    break;
					          if(ch==49)
					             { // stat=STATUS_SYSTEM.SetSystemStat(1);
							cout<<commandLine<<"\t\t\t\t\t!!!!Your System In Alert !!!\n";
						        cout<<commandLine<<"\t\t\t\t\t!!!!All Component Are Active!!!!!\n";
					                 dStat=STATUS_SYSTEM.SetDoorSensorStat(49);
							 retSetAlaram=STATUS_SYSTEM.SetAlaramStat(49);   
							 stat=STATUS_SYSTEM.SetSystemStat(49);
                                                          if(dStat==1 && retSetAlaram==1&&stat==1)
							  {
							  cout<<commandLine<<"\t"<<"All Hardware is Sucessfully Active\n";
							  break;
							  }

					                 else
						          		 
							  cout<<commandLine<<"\t"<<" Hardware is Bussy Active\n";
						     } 
						  else	
					             cout<<commandLine<<"\tPress Valid Number ?"<<endl;
					    }
								} 
                  }//Main IF end

                         else if(retPasswordStatus==0&&userType==ADMIN)
                            { 
                            /*  strcpy(commandLine,"Admin#~> ");
			      SystemStat STATUS_SYSTEM;
		              char stat=STATUS_SYSTEM.GetSystemStat();  //calling get system stat                   
				 //    getPasswordRet=USER_PASSWORD.GetPassword(userType,tempPassword); //temp password //file not;
			      SWITCH_TO_PRESS :
			      cout<<commandLine<<"Press 1 To Change System Settting 2 For Enter Door \n";
			      cout<<commandLine;cin>>press;   //vaidation here!  
			      if(press==1 && stat==49) //if system is secure
				     {
				      int aStat=STATUS_SYSTEM.GetAlaramStat();
				       char retSetSensor,retSetAlaram;
					int dStat=STATUS_SYSTEM.GetDoorSensorStat(1);//getting sensor status
																																																		                int tempAlaramStorage,tempDoorStorage,tempSystemStorage;
																																																								        cout<<"The Following List\n" ;//you change change 
																																																										                                            if(aStat==1) //Alaram ONN
																																																																    						        { 
																																																																								                  			               cout<<commandLine<<"Alaram Stat = ON \n";
																																																																														       						       check ://if user enterd insted 1 then it become in loop
																																																																														       						       cout<<commandLine<<"\tPress 1 For Change Stat \t 0 To Exit\n"<<commandLine<<"\t";//enter valid
																																																																																				       						       cin>>tempAlaramStorage; //temp variable for storing alaram stat value
																																																																																										       						         retSetAlaram=STATUS_SYSTEM.SetAlaramStat(1);   
																																																																																																	 						         if(tempAlaramStorage==1 && retSetAlaram==1) 
																																																																																																									 		               				       ciout<<"SucessFull";   
																																																																																																								 							    else 



















                       
				  
				  
				  
				  
				  
	       
				  
				  
				  
				  
				  
				  
                        */				  
				  
				  
				  
				  
				  
				  
				  
				  
				    //getPasswordRet=ADMIN_PASSWORD.GetPassword(userType,tempPassword);//temp password //file not;
	                     }
		
                       else if(retPasswordStatus==0&&userType==3)
                            {
	                
		 // getPasswordRet=DEFAULT_PASSWORD.GetPassword(userType,tempPassword);//temp password //file not;
	                     }



  //      SystemControllerI Auth;
// 	 ret=Auth.Authentication(ret,userType);

}
/*

PasswordManagement P;
P.SetPassword(1);
P.SetPassword(2);
P.SetPassword(385744);
P.GetPassword(1);
P.GetPassword(2);
P.GetPassword(385744);

SystemStat s1;
s1.GetSystemStat();
int f=s1.SetAlaramStat(1);
s1.SetSystemStat(34);
s1.SetDoorSensorStat(14);
s1.GetDoorSensorStat(4);
*/
//return 0;
//}




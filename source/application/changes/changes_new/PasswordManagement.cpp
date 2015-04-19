

int  PasswordManagement::SetPassword(int userType,char *updatePassword) 
		{
                    
		if(userType==ADMIN)
		     {	cout<<"User="<<ADMIN<<endl; 
			   strcpy(this->aPassword,"ADMIN");
			   ofstream myfile;
			   myfile.open("AdminPass.txt");
		           myfile <<aPassword;
			   myfile.close();
					     
			   }
		    else if(userType==USER)
			{

		       	cout<<"User=....."<<USER; 
			   //strcpy(this->uPassword,"User");
		          cout<<"Check = "<<this->uPassword;
		          ofstream myfile;
			   myfile.open ("UserPass.txt");
			   myfile <<uPassword;
			   cout<<"Password==>"<<uPassword;
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
	


int PasswordManagement::GetPassword(int userType,char *currentPassword) 
		{
		  int returnStatus;
	 	 if(userType==ADMIN)
			{
		  string line;
                   
	    		ifstream myfile ("AdminPass.txt");
	      			if (myfile.is_open())
		        		{
				     	while(getline(myfile,line) )
				      	   {
					   strcpy(this->aPassword, line.c_str());
						    
						   //cout <<"AdminPass =" <<line << '\n';

                                                    //strcpy(this->aPassword,line);
				          }								        				myfile.close();
                                              strcpy(currentPassword,this->aPassword);
					      cout<<currentPassword<<aPassword;
                                          return(ADMIN);
                                          }
				
	      			  else 
				  {	
	                         return(-1);//unable to open file		
 
                      		}
			}
				else if(userType==USER) {				 
					     string line;
					
	    					ifstream myfile("UserPass.txt");
	      						if (myfile.is_open())
		        			 	{
				    			while( getline (myfile,line) )
				      		  	{
						          strcpy(this->uPassword, line.c_str());
						           
							}
                                                         myfile.close();
                                                            strcpy(currentPassword,this->uPassword);
						         cout<<"PAAASWORD "<<currentPassword<<uPassword;
							    return(USER);
                                                         }
      			 			 
							return(-2);
  //                              			     return(int(line));


						}					
				
		
						else if(userType==DEFAULT) {				 
					     string line;
	    					ifstream myfile("DefaultAPass.txt");
	      						if (myfile.is_open())
		        			 	{
				    			while( getline (myfile,line) )
				      		  	{
						 strcpy(this->dPassword, line.c_str());
						  
							}
                                                         myfile.close();
							  strcpy(currentPassword,this->dPassword);
                                                            return(DEFAULT);
						         }
      			 			 else
							return(-3);

							}			
		
		
		};








//int main()S
  //  {

    //  int userType=1;//Value came from UserInterface;

  //PasswordManagement USER_PASSWORD,ADMINPASSWORD;
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
              //}


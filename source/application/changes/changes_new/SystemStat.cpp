

 


//--------------------------------Please Write in Seprate file And name it System.h


//----------------------------X-----------X--------------X-----------X-----------------


char  SystemStat::GetAlaramStat(char status) 
		{
		  string line;
                  char getAlaramStat=0;
	    		ifstream myfile ("AlaramStat.txt");
	      			if (myfile.is_open())
		        		{
				    	while( getline (myfile,line) )
				      	  {
						char *cstr = new char[line.length()+1];
                                           strcpy(cstr,line.c_str());
                                           getAlaramStat=*cstr;
                                             delete [] cstr;	
						 //cout <<"\nAlaram Status=" <<line << '\n';
                         	          }	
					
                                          cout<<"\nAlaram Stat = "<<getAlaramStat<<"\tok";					         
				          }	                                           											                             
                                         myfile.close();
                                         if(getAlaramStat==49)
                                         return(49);
                                         else
                                         return(48);
					};

						


char  SystemStat::GetSystemStat(char status) 
		{
		  string line;
                  char getSystemStat=0;
	    		ifstream myfile ("SystemStat.txt");
			 
				 
	      			if (myfile.is_open())
		        		{
				    	while ( getline (myfile,line) )
				      	   {
                                      //cout <<"System Status=" <<line << '\n';
                                       char *cstr = new char[line.length() + 1];
                                           strcpy(cstr,line.c_str());
                                           getSystemStat=*cstr;
                                             delete [] cstr;						         
				          }
					myfile.close();
                                    
				  	}

                                       if(getSystemStat==49)
                                         return(49);
                                      else
                                         return(48);
                              
		}	  //return(int(line));
					
					




char  SystemStat::SetAlaramStat(char status)
 {
	 int input=1;

                        //    cout<<"Default="<<DEFAULT<<endl; 
			    //strcpy(this->dPassword,"DEFAULT");
//	             if (status==49)
		     
			      cout<<"inside set alaram\n";
			    ofstream myfile;
			    myfile.open("AlaramStat.txt");
		            myfile<<status;
			    myfile.close();
		     
		     cout<<"\noutside set alaram\n";
                            return(49);

};

char SystemStat::SetSystemStat(char status)
 {

                        //    cout<<"Default="<<DEFAULT<<endl; 
			    //strcpy(this->dPassword,"DEFAULT");
			    ofstream myfile;
			    myfile.open("SystemStat.txt");
		            myfile<<status;
			    myfile.close();
return(1);

};


char  SystemStat::SetDoorSensorStat(char status)
 {

                        //    cout<<"Default="<<DEFAULT<<endl; 
			    //strcpy(this->dPassword,"DEFAULT");
			    ofstream myfile;
			    myfile.open("DoorSensorStatus.txt");
		            myfile<<status;
			    myfile.close();
                            return(48);

};


char  SystemStat::GetDoorSensorStat(char status) 
		{
                    char getDoorStat=0;
		  string line;
	    		ifstream myfile ("DoorSencorStatus.txt");
	      			if (myfile.is_open())
		        		{
				    	while ( getline (myfile,line) )
				      	  {
						 cout <<"System Status=" <<line << '\n';
				          }	
                                           char *cstr = new char[line.length() + 1];
                                           strcpy(cstr,line.c_str());
                                           getDoorStat=*cstr;
                                             delete [] cstr;						         
				          }	
                                                  myfile.close();
                                                 return(getDoorStat);
					};

	      			 
		  //return(int(line));
		





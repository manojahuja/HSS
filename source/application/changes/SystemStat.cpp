// reading a text file
//#include"SystemStat.h"

//--------------------------------Please Write in Seprate file And name it System.h

class SystemStat {
	private : int status;
	public:   int SetSystemStat(int);
		  int GetSystemStat();
	public:   int SetDoorSensorStat(int);
		  int GetDoorSensorStat(int);
		  int GetAlaramStat() ;
	  	  int SetAlaramStat(int);		  
		  };
//----------------------------X-----------X--------------X-----------X-----------------


int  SystemStat::GetAlaramStat() 
		{
		  string line;
	    		ifstream myfile ("AlaramStat.txt");
	      			if (myfile.is_open())
		        		{
				    	while ( getline (myfile,line) )
				      	  {
						 cout <<"\nAlaram Status=" <<line << '\n';
				          }												        myfile.close();
					}

	      			  else 
				cout << "Unable to open AlaramFile\n"; 
                                     //return(int(line));
					
				};			


int  SystemStat::GetSystemStat() 
		{
		  string line;
	    		ifstream myfile ("SystemStat.txt");
	      			if (myfile.is_open())
		        		{
				    	while ( getline (myfile,line) )
				      	  {
						 cout <<"System Status=" <<line << '\n';
				          }								        				myfile.close();
					}

	      			  else 
				cout << "Unable to open System file"; 
                            
		}	  //return(int(line));
					
					




int  SystemStat::SetAlaramStat(int)
 {

                        //    cout<<"Default="<<DEFAULT<<endl; 
			    //strcpy(this->dPassword,"DEFAULT");
			    ofstream myfile;
			    myfile.open("AlaramStat.txt");
		            myfile<<status;
			    myfile.close();
return(0);

};

int  SystemStat::SetSystemStat(int status)
 {
status=12;
                        //    cout<<"Default="<<DEFAULT<<endl; 
			    //strcpy(this->dPassword,"DEFAULT");
			    ofstream myfile;
			    myfile.open("SystemStat.txt");
		            myfile<<status;
			    myfile.close();
return(0);

};


int  SystemStat::SetDoorSensorStat(int status)
 {

                        //    cout<<"Default="<<DEFAULT<<endl; 
			    //strcpy(this->dPassword,"DEFAULT");
			    ofstream myfile;
			    myfile.open("DoorSensorStatus.txt");
		            myfile<<status;
			    myfile.close();
return(0);

};


int  SystemStat::GetDoorSensorStat(int a) 
		{

		  string line;
	    		ifstream myfile ("DoorSencorStatus.txt");
	      			if (myfile.is_open())
		        		{
				    	while ( getline (myfile,line) )
				      	  {
						 cout <<"System Status=" <<line << '\n';
				          }								        				myfile.close();
					}

	      			  else 
				cout << "Unable to open System file"; 
                            
		}	  //return(int(line));
		





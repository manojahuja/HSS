#include"system.h"
#include"all_classes.h"

//-----------------------------------------Defination of HumanInterface-------------

//-----------------------------------White Space function------------------------------------------
void HumanInterface:: WhiteSpace(int noOfPixel,char data)
          {
           int const lineEnd=103;

	  if(noOfPixel>lineEnd)
		  cout<<"Please Do Not Cross The Limit\n";
	    else if(noOfPixel<=103 && data == '=')
		     {
	  	for(int start=1;start<=noOfPixel;start++)
                    cout<<"=";
		     }

                  else if(noOfPixel<=103 && data == '_')
		     {
	  	for(int start=1;start<=noOfPixel;start++)
                    cout<<"_";
		     }


	  else{
	     
	  	for(int start=1;start<=noOfPixel;start++)
	      cout<<" ";
	  }
           //   cout<<endl;
	  };
//--------------XXXXXXXXXXXX--------------------XXXXXXXXXXXXX--------------XXXXXXXXXXXXXXXXXX-----------------XXXXXXXXXX---------!


//---------------------------------------Banner function----------------------------
void HumanInterface::Banner(){
      strcpy((this->designBy),"Siddhi Vinayaka");
	system("clear");
	WhiteSpace(102,'=');
        cout<<endl;
	//WhiteSpace(1,' ');
	//cout<<"UserName:"<<commandName;
	WhiteSpace(39,' ');
strcpy((this->systemName),"Home Security Alaram System");
	  cout<<systemName;
         cout<<endl;
        WhiteSpace(103,'=');
        cout<<endl;
         //strcpy((this->commandName),"@@@@@");
         WhiteSpace(3,' ');
         cout<<"USER:- "<<userName;//this
         WhiteSpace(60,' ');
      

        cout<<"DesignBy:-";
	cout<<designBy;
         cout<<endl;
           WhiteSpace(103,'_');

	 cout<<endl;
       
};
//--------------XXXXXXXXXXXX--------------------XXXXXXXXXXXXX--------------XXXXXXXXXXXXXXXXXX-----------------XXXXXXXXXX---------!

//--------------------------------------------Home SecurityInfo----------------------------INFO :- About Project and Devloper
void HumanInterface::Set(void)
{


 //strcpy(this->commandName,"USERRR");


};
//--------------XXXXXXXXXXXX--------------------XXXXXXXXXXXXX--------------XXXXXXXXXXXXXXXXXX-----------------XXXXXXXXXX---------!

//--------------------------------------------UserInterFacer function----------------------INFO :- Intraction Interface
	
int  HumanInterface::UserInterface(void) {
 system("reset");
                             
Head :		   

                           //
		   	   //cout<<systemName<<endl;	   
                            //WhiteSpace(102);
                                strcpy((this->userName),"@@@@@@");                
		                Banner();	   
                   		cout<<"Enter You Choice\n";
				cout<<"Please Enter The choice 1. Admin 2. User\n";
				int userType;
				cin>>userType;

				
			// write the transtions here
			//
			     if (userType==ADMIN) 
                                   {
				
				  Banner();
                                  strcpy(this->userName,"Admin"); 
				
                                 return(userType); 
			             
		                	}
			  else if (userType==USER) 
			  { 
		              
				
                                   strcpy(this->userName,"User"); 
				Banner();			     
					         
				/*  cout<<commandName;
			     cin>>userType;
			     Banner();*/
                           return(userType);
				
			} else 
		       	{
				cout << "\nuser has entered the wrong selection value\n";
			
                            
			}
                            goto Head ;
};
//--------------XXXXXXXXXXXX--------------------XXXXXXXXXXXXX--------------XXXXXXXXXXXXXXXXXX-----------------XXXXXXXXXX---------!

//EEEEEEEEEEEEEEEEEEEEEEE   		NNNNNNNNNNNNNNNNNNNNNNNNNNN  	        DDDDDDDDDDDDDDDDDDiDDDDDDDDDDDDDDDD


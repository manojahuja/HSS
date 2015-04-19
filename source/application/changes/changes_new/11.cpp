 #include"iostream"            //|                   
  #include "string.h"           //|                       
    #include"stdlib.h"            //|
      #define NEWLINE 0;            //|==============> Belongs to HumanInterface Class
        using std::cin;               //|
	  using std::cout;              //|
	   using std::string;            //|  
	      using std::endl; 

main()
{
      char apassword;
        

	std::string str = "1323";
	
	 char *cstr = new char[str.length() + 1];
         char p,temp[1];
 	 strcpy(cstr,str.c_str());
 //      	 strcpy(temp,cstr);
	  p=*cstr;
          cout<<cstr ;    
      	//strcpy(cstr,str.c_str());
 //        strcpy(p,cstr);
	// do stuff
	//cout<<p;
	 delete [] cstr;
	

cout<<endl<<p;
 

//icout<<cstr;
}

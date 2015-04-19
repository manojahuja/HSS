
/*----------------------------------------------------HUMANINTERFACE---------------------------------------------*/
//class   SystemController
//{ 
 // DesignFuncion(class HumanInterface);
 //};                 

 //void Command_Name(class HumanInterface);
  class HumanInterface {        
 	private:  char systemName[20];//
		  
                  char  commandLine[20];//  Admin#~> 
                  char  userName[15];//Member/Admin
                    char designBy[20];
                                                                    
		   public: 
	 	   int UserInterface(void); 
                   void WhiteSpace(int,char);
                 	 
		   void Banner();
                   public:void Set(void);
                  // friend void Command_Name(HumanInterface);
              	  // friend SystemController::DesignFunction(HumanInterface);
                      
};  

//--------------XXXXXXXXXXXX--------------------XXXXXXXXXXXXX--------------XXXXXXXXXXXXXXXXXX-----------------XXXXXXXXXX---------!



//--------------------------------------------------------------------------------------
class SystemControllerI {
	private : int userType,attemp;
        private :char currentPassword[20];
		 char userName[20];
	private : //int SetSysStat();                 FRIEND Fun
	public : int SelfCheck(char *);	
	public  : int Authentication(int);
        //public :  int InvokePassword(class PasswordManagement,int,char *tempPassword);//-------------------sddsdsdssddsdsd	  
		   //friend GetAuthentication();
		 int getch(void);
	      // int SetAlaramStat();		  
		  	};
//----------------------------------------------------------------------------------------


// class SystemControllerI;
//--------------------------------Please Write in Seprate file And name it System.h

class PasswordManagement {
	private :char uPassword[20],aPassword[20],dPassword[20];
		 int userType;
	public : //int SetSysStat();
   		  int  SetPassword(int,char*);
		   int GetPassword(int,char*);////////////////////ref *currentpassword
//        	  friend int SystemControllerI::InvokePassword(PasswordManagement,int,char *tempPassword);//friend======>>>>>>>
                     int Default(int);
                               
		  
	  	 // int SetAlaramStat();		  
		  };
//----------------------------X-----------X--------------X-----------X--------------




class SystemStat {
	private : char setstatus;
	public:   char SetSystemStat(char);
		  char GetSystemStat(char);
	public:   char SetDoorSensorStat(char);
		  char GetDoorSensorStat(char);
		  char GetAlaramStat(char) ;
	  	  char SetAlaramStat(char);		  
		  };









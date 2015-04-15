#include"system.h"
#include"HumanInterface.cpp"
#include"SystemControllerI.cpp"
#include"PasswordManagement.cpp"
#include"SystemStat.cpp"


//#include"File.h"
//#include "HumanInterface.h"
int main() 
{






int userType=0;
       cout<<"HEllo";
	SystemControllerI PCHECK;
	int ret;
	cout<<ret;
	ret=PCHECK.SelfCheck(0);
         if(ret==0&&userType==1)
              //GetPassword(userType);
		 int f;
	 else if(ret==1&&userType==2)
		// GetPassword(userType);
		 int d;
          else
	  {int p;}

  //      SystemControllerI Auth;
// 	 ret=Auth.Authentication(ret,userType);



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

return 0;
}



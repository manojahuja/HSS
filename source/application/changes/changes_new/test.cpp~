#include <iostream>
#include "string.h"
#include"stdlib.h"
#include"stdio.h"
#include <termios.h>
#include <unistd.h>
#define NEWLINE 0;

using std::cin;
using std::cout;
using std::string;
using std::endl;
//--------------------------------------------------------------------------------
 class HumanInterface {        
private:  char systemName[10];
		   char designBy[10];
             char  commandName[10];   

                                                                    
		   public: 
	 //	   int UserInterface(void); 
           //        void WhiteSpace(int);
                    int getch(void);	 
}; 

int HumanInterface::getch(void)
    {
	        struct termios oldattr, newattr;
		    int ch;
		        tcgetattr( STDIN_FILENO, &oldattr );
			    newattr = oldattr;
			        newattr.c_lflag &= ~( ICANON | ECHO );
				    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
				        ch = getchar();
				   // if(getchar()
					    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
					         return ch;
	//	getch(void);				
    }





	int main()
{
int userType;
HumanInterface t;
char i[20];
int a=0;
while(1)
{
 i[a]=t.getch();
 
if(a==10||i[a]==10)
{
	++a;
i[a]='\0';
	break;

}
a++;
}
cout<<i;
};


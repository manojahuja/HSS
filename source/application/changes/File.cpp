#include"File.h"
 System_State::System_State(void)

			{	
	 	int fd,temp=2;
 		fd = open("./dumpdemo.txt",O_RDWR|O_CREAT|O_TRUNC,0660);
                 cout<<"sdsds"; 	
       		if(fd < 0)
			{
			cout<<"Could not open file\n";
			exit(2);
			}
		 else {
		       temp=read(fd,&system_state,1);
		        
		 	}
		 if(temp<=1)
		 	{
			cout<<"Error MSG\n";
   			//System_State::System_State(Write);
		  	}
			      }

	
						


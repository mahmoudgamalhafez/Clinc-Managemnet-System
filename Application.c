#include "Types.h"
#include "Mode.h"
#include <stdio.h>
#define TRUE  1
#define FALSE 0
int main()
{
	u16 Buffer,CHECK;//CHECK is Flag
	while(1){
		printf("Enter 1 for Admin Mode \nEnter 2 for User Mode \nEnter 3 to exit Program");
		printf("\nYour Choice: ");
		scanf("%d",&Buffer);
		switch(Buffer){
			/* in case enterd 1 Admin_Mode fun is called */
			case 1: 
				Admin_Mode();	
				break;
			/* in case enterd 2 User_Mode fun is called */
			case 2:
				User_Mode();
				break;
			/* in case enterd 3 End  Program*/
			case 3 :
				printf("Good Bye");
				return 0;
			default:
				printf("Wrong Choice Try Again \n ");
			
		}
	}
}
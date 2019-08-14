#include "Types.h"
#include "Password.h"
#include <stdio.h>
#define DEFULT_PASSWORD 1234
#define TRIAL_ALLOWED 3
#define TRUE  1
#define FALSE 0
static u32 CURRENT_PASSWORD =DEFULT_PASSWORD;

/******************************************************************
*	CHECK_PASSWORD:-Asks the Admin for Password ,				  *	
*					allows 3 trial for the password ,return 1 	  *
*					if password right ,repeat for a second and	  *	 
*					third chances if wrong return 0;			  *	
*******************************************************************/
u16 CHECK_PASSWORD(){
	u32 ADMIN_PASSWORD; // it was u16 and something went wrong with i does not count 
	u16 i; // to count trials 
	for(i=0;i<TRIAL_ALLOWED;i++){
		/*scan password for another chances*/
		printf("Enter Password : ");
		scanf("%d",&ADMIN_PASSWORD);
		/*check password */
		if(ADMIN_PASSWORD==CURRENT_PASSWORD)
			return TRUE;
	}
	return FALSE;	
}

#include "Types.h"
#include "Patient.h"
#include "Password.h"
#include "Mode.h"
#include <stdio.h>
#define LEN_NAME 100
#define TRUE  1
#define FALSE 0
#define FALSE_ID 2
static u16 Buffer ; // to switch between functions
/*flag */
static u16 CHECK ;
/*Patient information */
static u32 user_ID ,user_Age;
static u8 user_Name[LEN_NAME],user_Gender ;
/* 
	Admin_Mode:-Asks user for password if right , allow four servcies"functions"
				1-Add_Patient_Record
				2-Edit_Patient_Record
				3-Reserve_Slot
				4-Cancel_Reservation
*/	
void Admin_Mode()
{
	//u32 user_ID ,user_Age;
	//u8 user_Name[LEN_NAME],user_Gender ,CHECK;
	//u16 Buffer ; // to switch between functions
	/*check for password */
	if(CHECK_PASSWORD())
	{
		/*if correct password*/
		/*Loop for servcies */
		while(1){
			printf("Choose a service: \n");
			printf("Enter 1 to Add Patient\nEnter 2 to Edit_Patient\nEnter 3 to  Reserve_Slot with doctor\nEnter 4 to Cancel_Reservation\nEnter 5 to exit Admin Mode:  " );
			printf("\nYour Choice: ");
			scanf("%d",&Buffer);
			switch(Buffer){
				/*in case Entered 1 Add_Patient_Record is called */
				case 1 :
					/*Patient information */
					/*maybe wrong check*/
					fflush(stdin);
					printf("Enter Patient Name: ");
					gets(user_Name);
					fflush(stdin); 
					printf("Enter Patient Gender 'M' for Male 'F' for Female: ");
					user_Gender=getchar();
					printf("Enter User ID: ");
					scanf("%d",&user_ID);
					printf("Enter User Age: ");
					scanf("%d",&user_Age);
					/*Check if allocated proberly */
					if(Add_Patient_Record(user_ID,user_Age,user_Gender,user_Name))
						printf("Patient Added: ");
					else
						printf("Something Wrong happended \nPatient can not be added\n");
					break;
				/* in case Entered 2 Edit Patient Record*/
				case 2 :
					/* Patient ID to be modified*/
					printf("Enter Patient ID: ");
					scanf("%d",&user_ID);
					/*Check if modfiend proberly */
					CHECK=Edit_Patient_Record(user_ID);
					/* in case ID Not Found*/
					if(CHECK==FALSE_ID)
						printf("\nID doesn't exist\n");
					/* in case No Patient Added yet*/
					else if(CHECK==FALSE)
						printf("No Records for Patient\n");
					/* in case Modified*/
					else
						printf("Mocified Proberly\n");
					break;
				case 3 :
					break;
				case 4 :
					break;
				/* in case Entered 5 to turn off admin mode*/
				case 5:
					return  ;
				default :
					printf("Wrong Choice Try Again\n");
			}
		}
	}
	/*if password not correct */
	else{
		printf("Wrong Password You did 3 Trials\n");
		return ;
	}
	
}
/* 
	User_Mode(): allow two features 
					1- View_Patient_Record
					2- View_Today's_Reservation
					
*/
void User_Mode()
{
	/*Loop for servcies */
	while(1){
		printf("Choose a service\n");
		printf("Enter 1 to View Patient Record\nEnter 2 to View Today's Reservation \nEnter 3 to exit User_Mode\n");
		printf("your Choice: ");
		scanf("%d",&Buffer);
		fflush(stdin);
		/* */
		switch(Buffer){
			/*in case Entered 1 View_Patient_Record is called */
			case 1 :
				/* scan for Patient ID to be viewed*/
				printf("Enter Patient ID: ");
				scanf("%d",&user_ID);
				CHECK=View_Patient_Record(user_ID);
				/* in case ID Not Found*/
					if(CHECK==FALSE_ID)
						printf("ID doesn't exist\n");
					/* in case No Patient Added yet*/
					else if(CHECK==FALSE)
						printf("No Records for Patient\n");
					/* in case Modified*/
					else
						printf("done Proberly\n");
					break;
			case 2 :
				break;
			case 3:
				return ;
			default:
				printf("Wrong Choice Try Again");
		}
	}
}

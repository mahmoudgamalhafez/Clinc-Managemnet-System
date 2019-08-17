#include "Types.h"
#include  "Patient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE  1
#define FALSE 0
#define FALSE_ID 2 

/* Reservation_APPOINTMENT schedule*/
#define FIRST_APPOINTMENT 		2
#define END_FIRST_APPOINTMENT  	2.30
#define END_SECOND_APPOINTMENT 	3
#define END_THIRD_APPOINTMENT 	3.30
#define FORTH_APPOINTMENT 		4
#define END_FORTH_APPOINTMENT 	4.30
#define END_FIFTH_APPOINTMENT	5

#define NUM_OF_SLOTS 5
#define Reservation_Information 2 // 


/* Type defintion*/
static Node *Head=NULL; // pointer to first element 
//Node *(Pointer_Node[NUM_OF_SLOTS])={NULL}
static u32 Reservation[NUM_OF_SLOTS][Reservation_Information]={FALSE}; // Flags to indicate if slots reserverd or not and ID reserverd the slot 
/*2 dimentional array  of 5 rows as number of slots each row reprsent strat of appointment and end of appointment*/
static f32 Reservation_APPOINTMENT[NUM_OF_SLOTS][Reservation_Information]={
																FIRST_APPOINTMENT,END_FIRST_APPOINTMENT,
												 			    END_FIRST_APPOINTMENT,END_SECOND_APPOINTMENT,
																END_SECOND_APPOINTMENT,END_THIRD_APPOINTMENT,
																FORTH_APPOINTMENT,END_FORTH_APPOINTMENT,
																END_FORTH_APPOINTMENT,END_FIFTH_APPOINTMENT};
																
																
//static 	u32 Reservation_ID[NUM_OF_SLOTS];					
																  

//static u32 NUM_OF_RECORDS=0; // Number of patients


/*function prototype*/
static u16 CHECK_EXSITING_ID(u32);


/* 
	Add_Patient_Record:-take information from user his name ,age, gender
						add them to a new record ,ID ,check if ID exits 
						if so ,reject the entry .
*/
u16 Add_Patient_Record(u32 user_ID ,u32 user_Age ,u8 user_Gender,u8 *user_Name)
{
	
	Node *last,*temp; // pointer to node to track list ,create node
	/*in case first node*/
	if(Head==NULL){ // check first Node 
		temp=(Node *)malloc(sizeof(Node)); //allocate first node
		/*Check if not allocated proberly  */
		if(temp==NULL){
			printf("can not allocate");
			return FALSE;
		}
		/* CHECK if  assigned Gender */
		/*if(user_Gender!='M'ORuser_Gender!='F'){
			printf("Gender not recognized\n");
			return FALSE;
		}*/
		/*Assigning Values to Node */
		stpcpy(temp->Name,user_Name);
		temp->ID=user_ID;
		temp->Age=user_Age;
		temp->Gender=user_Gender;
		/*pointing to next value*/
		temp->Next=NULL;
		/*Head point to first node */
		Head=temp;
	/*	printf("added to head");
		printf("\n%s",Head->Name);*/
		return TRUE;// return 1 if allocated properly 
	}
	/*in case there are nodes */
	else{
		/* check for ID if exists */
		if(CHECK_EXSITING_ID(user_ID)){
			printf("ID Entered already\n");
			return FALSE;
		}
		/* CHECK if  for Gender  */
		/*if(toupper(user_Gender)!='M'||toupper(user_Gender)!='F'){
			printf("Gender not recognized");
			return FALSE;
		}*/
		/* loop for last node*/	
		last=Head; 
		while((last->Next)!=NULL){
			last=last->Next;
			
		}
		
		temp=(Node *)malloc(sizeof(Node));//allocate last node
		/*Check if not allocated proberly  */
		if(temp==NULL){
			printf("can not allocate");
			return FALSE;
		}
			
		/*Assigning Values to Node */
		stpcpy(temp->Name,user_Name);
		temp->ID=user_ID;
		temp->Age=user_Age;
		temp->Gender=user_Gender;
		temp->Next=NULL;
		/* to link new node with last one*/
		last->Next=temp;
	/*	printf("\n%s" ,last->Name);
		printf("\n%s",Head->Name);
		printf("\n%s",temp->Name);
		printf("added to else");*/
		return TRUE; 	// return 1 if allocated properly 
			
		 
	}
}
/* 
	Edit_Patient_Record:- searching for ID , if doesn't exists 
						  return 0, if exist the user  edit patient information
							
*/
u16 Edit_Patient_Record(u32 user_ID)
{
	Node *last;
	last = Head;
	/*Check if list is empty */
	if(Head==NULL){
		//printf("Empty List\n");
		return FALSE;
	}
	/*loop  to check if ID exists or not */
	while(last->ID!=user_ID&&last->Next!=NULL){
			last=last->Next;
	}
	/*in case id does not exist */
	if(last->ID!=user_ID&&last->Next==NULL){
		//printf("ID doesn't exist\n");
		return FALSE_ID;
	}
	/* in case exist ID*/
	else{
		fflush(stdin);
		printf("Enter User Name: ");
		gets(last->Name);
		fflush(stdin);
		printf("Enter Gender 'M' for Male 'F' for Female: ");
		last->Gender=getchar();
		printf("Enter Age: ");
		scanf("%d",&(last->Age));
		
	}
}
/************************************************************************ 
*	View_Patient_Record:-search for ID ,if exist show the patient record*
*************************************************************************/
u16 View_Patient_Record(u32 user_ID)
{
	Node *last;
	last = Head;
	/*Check if list is empty */
	if(Head==NULL){
		//printf("Empty List");
		return FALSE;
	}
	/*loop  to check if ID exists or not */
	
	while(last->ID!=user_ID&&last->Next!=NULL){
			last=last->Next;
	}
	/*in case id does not exist */
	if(last->ID!=user_ID&&(last->Next)==NULL){
		//printf("ID doesn't exist");
		return FALSE_ID;
	}
	/* in case exist ID*/
	
	else{
		printf("User Name : %s",last->Name);
		printf("\nUser Age: %d",last->Age);
		printf("\nUser Gender : %c",last->Gender);
		return TRUE;
	}

	for(last=Head;last!=NULL;last=last->Next){
		if(last->ID==user_ID){
			printf("User Name : %s",last->Name);
			printf("\nUser Age: %d",last->Age);
			printf("\nUser Gender : %c",last->Gender);
		}
	}
	
}
/* 
	Reserve_Slot():-display the available slots,resverve a slot by enter 
					ID and desired slot .
*/

u16 Reserve_Slot()
{
	// check if defined here better or make them global 
	u16 i ,Desired_Appointment;
	u32 user_ID;
	/*print available Apointment */
	printf("Available appointment to reserve at : \n");
	for(i=0;i<NUM_OF_SLOTS;i++){
		if(!Reservation[i][0]){
			printf("\t%.2f TO %.2f\n",Reservation_APPOINTMENT[i][0],Reservation_APPOINTMENT[i][1]);
		}
	}
	/*scan user ID to reserve */
	printf("\n");
	printf("Enter ID: ");
	scanf("%d",&user_ID);
	/*check if ID exist */
	if(CHECK_EXSITING_ID(user_ID)){
		/*Check if id reserved before */
		for(i=0;i<NUM_OF_SLOTS;i++){
			if(user_ID==Reservation[i][1]){
				printf("ID already reserved\n");
				return FALSE ;
			}
				
		}
		/*scan for Appointment */
		printf("Enter t Number from 1 to 5 to reserve at :\n");
		printf("Enter\t 1 to reserve at 2 \n\t 2 to reserve at 2.30  \n\t 3 to reserve at 3  \n\t 4 to reserve at 4  \n\t 5 to reserve at 4.30\n ");
		printf("Your choice:");
		scanf("%d",&Desired_Appointment);
		/*if enterd appointment correctly */
		if(Desired_Appointment>=1 && Desired_Appointment<=5){
			if(Reservation[Desired_Appointment-1][0]==TRUE){
					printf("Appointment Reserved before\n");
					return FALSE;
			}	
			Reservation[Desired_Appointment-1][1]=user_ID;
			Reservation[Desired_Appointment-1][0]=TRUE;
			return TRUE;
		}
		else{
			printf("Wrong Entity\n");
			return FALSE;
		}
	}
	/*in case ID does not exsit */
	else{
		printf("ID does not exist\n");
		return FALSE;
	}
}
/* 
	Cancel_Reservation(): scan for ID ,check if ID exist if so
						  check if reserve ,if so cancel reservation.
*/
u16 Cancel_Reservation()
{
	// check if defined here better or make them global 
	u32 user_ID;
	u16 i;
	printf("Enter ID : ");
	scanf("%d",&user_ID);
	/*check if ID exist */
	if(CHECK_EXSITING_ID(user_ID)){
		/*check if id reserved before  */
		for(i=0;i<NUM_OF_SLOTS;i++){
			if(user_ID==Reservation[i][1]){
					Reservation[i][0]=FALSE;
					Reservation[i][1]=FALSE;
					/*return if cancled  */
					return TRUE;
			}
		}
		/*return if id exist but does not reserved */
		printf("ID does not reserve before\n");
		return FALSE;
	}
	else
	{
		printf("ID does not exist\n");
		return FALSE;
	}
}
/****************************************************************************
*	view_Today_Reservation:-the system print all reservation with patient ID*
*****************************************************************************/
void view_Today_Reservation()
{
	u16 i;
	for(i=0;i<NUM_OF_SLOTS;i++){
		if(Reservation[i][0]){
			printf("ID %d Reserved Slot from %.2f To %.2f \n",Reservation[i][1],Reservation_APPOINTMENT[i][0],Reservation_APPOINTMENT[i][1]);
		}
	}
}
/********************************************************* 
*	CHECK_EXSITING_ID: check if ID exsit ,if so return 1 *
*						if not return 0					 * 	
**********************************************************/
static u16 CHECK_EXSITING_ID(u32 user_ID)
{
		Node *last; // Node to track list
		last=Head;
		/*check if empty list */
		if(Head==NULL){
			printf("No Patient Records\n");
			return FALSE;
		}
			
		/* check if ID exsit*/
		while(last->ID!=user_ID &&last->Next!=NULL ){
			last=last->Next;
		}
		/*in case not found */
		if((last->ID==user_ID))
			return TRUE;
		/*in case not found */
		else 
			return FALSE;
}
	
/****************************************************
*	Print_List: print all elements of the list 		*
*****************************************************/
/*
void Print_List(){
	u16 i=1;
	Node *last;
	last=Head;
	if(Head==NULL){
		printf("Node is Empty");
	}
	else{
		printf("-------------------------------\n");
		//printf("Node Number %d = %d\n", i,Head->value);
		while((last->Next)!=NULL){
			printf("Node Number %d =%s\n",i,last->Name);
			printf("Node Number %d =%d\n",i,last->ID);
			printf("Node Number %d =%d\n",i,last->Age);
			i++;
			last=last->Next;
		}
		printf("Node Number %d =%s\n",i,last->Name);
			printf("Node Number %d =%d\n",i,last->ID);
			printf("Node Number %d =%d\n",i,last->Age);
	}
		printf("-------------------------------\n");
	
}


int main()
{
	u32 user_ID,user_Age,input,check;
	u8 user_Name[100];
	u8 user_Gender;	
	while(1){
		printf("Enter number: ");
		scanf("%d",&input);
		switch(input){
			case 1:
				fflush(stdin);
				printf("\nEnter user Name");
				gets(user_Name);
				fflush(stdin);
				printf("Enter Gender M for male F for female: ");
				user_Gender=getchar();
				fflush(stdin);
				printf("\nEnter Age");
				scanf("%d",&user_Age);
				printf("\nEnter ID");
				scanf("%d",&user_ID);
				check=Add_Patient_Record(user_ID,user_Age,user_Gender,user_Name);
				printf("%d",check);
				break;
			case 2:
				printf("Enter ID");
				scanf("%d",&user_ID);
				View_Patient_Record(user_ID);
				break;
			case 3 :
				Print_List() ;
				break;
			case 4:
				printf("\nEnter ID");
				scanf("%d",&user_ID);
				Edit_Patient_Record(user_ID);
				break;
			default:
				return 0;
				
		}
	}
}



/*********************************************************************** 
*	terminate:- to handle unallocated memory and print message to user *
************************************************************************/
/*
static void terminate(const char *message)
{
	printf("%s\n",message);
	exit(EXIT_FAILURE);
}


*/








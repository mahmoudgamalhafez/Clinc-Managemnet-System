#include "Types.h"
#include  "Patient.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE  1
#define FALSE 0
#define FALSE_ID 2
#define NUM_OF_SLOTS 5
static Node *Head=NULL; // pointer to first element 
//Node *(Pointer_Node[NUM_OF_SLOTS])={NULL}
static u32 Reservation_Flags[NUM_OF_SLOTS]={FALSE}; // Flags to indicate if slots reserverd or not 
//static 
//static u32 NUM_OF_RECORDS=0; // Number of patients
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
		/* check for ID if exists  and loop for last node*/
	
		last=Head; 
		while((last->ID)!=user_ID&&(last->Next)!=NULL){
			last=last->Next;
			
		}
		/*if ID does not exist */
		if((last->ID)!=user_ID&&(last->Next)==NULL){
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
		else{
			printf("ID Entered already\n");
			return FALSE;
		}// return -1 if can not allocated properly 
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
/*
void Reserve_Slot()
{
	
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








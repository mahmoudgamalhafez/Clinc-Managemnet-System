#include "Types.h"
#include  "Patient.h"
#include <stdio.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE 0
extern Node head  ;
//u32 ListLength = 0;
/* 
	Add_Patient_Record:-take information from user his name ,age, gender
						add them to a new record ,ID ,check if ID exits 
						if so ,reject the entry .
*/
u16 Add_Patient_Record(u32 user_ID ,u32 user_Age ,u8 user_Gender,u8 user_Name[])
{
	//Node *last; // pointer to node to track list 
	/*in case first node*/
	if(Head==NULL){ // check first Node 
		Head=(Node *)malloc(sizeof(Node)); //allocate first node
		/*Check if not allocated proberly  */
		if(Head==NULL){
			printf("can not allocate");
			return FALSE;
		}
		/*Assigning Values to Node */
		Head->Name=&user_Name;
		Head->ID=user_ID;
		Head->Age=user_Age;
		Head->Gender=user_Gender;
		/*pointing to next value*/
		Head->Next=NULL;
		printf("added to head");
		printf("\n%s",Head->Name);
		return TRUE;// return 1 if allocated properly 
	}
	/*in case there are nodes */
	else{
		Node *last; 
		/* check for ID if exists  and loop for last node*/
		last=Head; 
		while((last->ID)!=user_ID&&(last->Next)!=NULL){
			last=last->Next;
		}
		/*if ID does not exist */
		if((last->ID)!=user_ID&&(last->Next)==NULL){
			last->Next=(Node *)malloc(sizeof(Node));//allocate last node
			/*Check if not allocated proberly  */
			if(last->Next==NULL){
				printf("can not allocate");
				return FALSE;
			}
			
			/*Assigning Values to Node */
			stpcpy(last->Name,user_Name);
			last->ID=user_ID;
			last->Age=user_Age;
			last->Gender=user_Gender;
			last->Next->Next=NULL;
			printf("\n%s" ,last->Name);
			printf("\n%s",Head->Name);
			printf("added to else");
			return TRUE; 	// return 1 if allocated properly 
		}
		else{
			printf("ID Entered already");
			return FALSE;
		}// return -1 if can not allocated properly 
	}
}
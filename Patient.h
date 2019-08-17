#ifndef PATIENT_H
#define PATIENT_H
#include "Types.h"
#define LEN_NAME 100
typedef struct Node_Patient Node;
struct Node_Patient{
	u32 Age ,ID;
	u8 Gender;
	u8 Name[LEN_NAME];
	Node *Next;
};
u16 Add_Patient_Record(u32 ,u32 ,u8,u8 *);
u16 Edit_Patient_Record(u32);
u16 View_Patient_Record(u32);
/* check if it right to be defined here */
//static u16 CHECK_EXSITING_ID(u32);
u16 Reserve_Slot();

u16 Cancel_Reservation();
void view_Today_Reservation();

#endif

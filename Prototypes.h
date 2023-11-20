
/********************************************************/
/********************************************************/
/*************Author : Ahmed Khaled Gamal****************/
/*********Description : Proto_Types**********************/
/******************Date : 23 /3/2023 ********************/
/*******************VERSION     : V02 *******************/
/********************************************************/
/********************************************************/

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_



void Admin_PassWord();

void Admin_Mode();

void User_voidMode();

void List_voidList(List *pl);

void List_voidInsert(int pos,List *pl,int ID,int age,char Gender,char *Name);

void Reserve_Slot(int ID,int mode);

int List_voidSize(List *pl);

int ID_Check(int ID,List *pl);

void Patient_Edit(List *pl,int ID,int New_age,char *New_name);

void Cancel_Reservation(int ID,List *pl);

void List_voidPrint(List* pl,int ID);

#endif
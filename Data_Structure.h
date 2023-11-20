/********************************************************/
/********************************************************/
/*************Author : Ahmed Khaled Gamal****************/
/*********Description : Data_Structure*******************/
/******************Date : 23 /3/2023 ********************/
/*******************VERSION     : V02 *******************/
/********************************************************/
/********************************************************/


#ifndef DATA_STRUCTURE_H_
#define DATA_STRUCTURE_H_


typedef struct Patient_Node
{
    
        int ID;
        int Age;
        char Name[10];
        char Gender;
        struct Patient_Node *Next;
    
    
}Patient_Node;

typedef struct 
{
    Patient_Node *Head;
    int Size;
} List;





#endif
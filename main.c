/********************************************************/
/********************************************************/
/*************Author : Ahmed Khaled Gamal****************/
/*********Description : Clinic Management System*********/
/******************Date : 23 /3/2023 ********************/
/*******************VERSION     : V02 *******************/
/********************************************************/
/********************************************************/

#include <stdio.h>
#include"Data_Structure.h"
#include"Prototypes.h"












void main()
{
    int Options;
    char tryAgain , Flag;
    printf("/****** Welcome to our CLinc System ******/\n");
    printf("\n");
    do
    {
        printf("Press 1 for admin mode.\n\nPress 2 for user mode.\n\n");            
        printf("Enter your option : ");
        scanf("%d",&Options);

        switch (Options)
        {
        case 1:Admin_PassWord();break;
        case 2:User_voidMode();break;
        default:printf("Invalid Option.");break;
        }
        printf("\n");
        printf("Do you want to exit ? (Y/N) : ");
        scanf(" %c", &tryAgain);

    }while (tryAgain == 'N' || tryAgain == 'n');
   
}






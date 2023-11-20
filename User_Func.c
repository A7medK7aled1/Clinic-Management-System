/********************************************************/
/********************************************************/
/*************Author : Ahmed Khaled Gamal****************/
/*********Description : User Functions Implemetation*****/
/******************Date : 23 /3/2023 ********************/
/*******************VERSION     : V02 *******************/
/********************************************************/
/********************************************************/


#include <stdio.h>
#include<stdlib.h>
#include "Data_Structure.h"
#include"Prototypes.h"

extern List *ps;
extern char Times[];
extern int id[];

void User_voidMode()
{
	int options,ID,i,f;
	char tryAgain;

	printf("/****** You are in user mode ******\\\n");
	printf("\n");
	do
	{
		printf("Press 1 to View patient record.\nPress 2 to View today's reservations.\n");
		printf("Enter your option : ");
		printf("\n");
		scanf("%d",&options);

		switch(options)
		{
		case 1:
			do
			{   
				printf("Enter patient ID : ");
				scanf("%d",&ID);
				f=ID_Check(ID,ps);
				while(f!=1)
				{
					printf("entered ID number is not exist, try again : ");
					scanf("%d",&ID);
					f=ID_Check(ID,ps);

				}

				List_voidPrint(ps,ID);

				printf("Do you want to view another patient? (Y/N) : ");
				scanf(" %c", &tryAgain);
			} while (tryAgain == 'Y' || tryAgain == 'y');


			break;
		case 2 :
			printf("Patient booking schedule\n");
			for(i=0;i<5;i++)
			{
				printf("The patient ID :%d --> time : %s \n",id[i],Times[i]);
			}

			break;
		default:printf("You entered an invalid option .");break;
		}
		printf("\n");
		printf("Do you want to go out from user mode ? (Y/N) : ");
		scanf(" %c", &tryAgain);
	}while (tryAgain == 'N' || tryAgain == 'n');


}




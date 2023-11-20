/********************************************************/
/********************************************************/
/*************Author : Ahmed Khaled Gamal****************/
/*********Description : Admin Functions Implemetation****/
/******************Date : 23 /3/2023 ********************/
/*******************VERSION     : V02 *******************/
/********************************************************/
/********************************************************/




#include <stdio.h>
#include<stdlib.h>
#include"Data_Structure.h"
#include"Prototypes.h"

List s1;
List *ps = &s1;

int id[5];
char Times[5][20]={"2:00pm - 2:30pm" , "2:30pm - 3:00pm","3:00pm - 3:30pm","4:00pm - 4:30pm","4:30pm - 5:00pm"};


        /*Function to check about admain password */
void Admin_PassWord()
{
	int Copy_Password,i,flag=0;


	printf("Please Enter The Password : ");

	for(i=0;i<3;i++)
	{   
		scanf("%d",&Copy_Password);
		if(Copy_Password == 1234)               /*Default pssword is 1234*/
		{

			flag = 1;
			Admin_Mode();
			break;
		}
		else if(i<2)
		{
			printf("\n");
			printf("Wrong password try again : ");
		}
	}

	if(flag==0)
	{
		printf("You enter password wrong for 3 times, No more chances");
	}


}



void Admin_Mode()
{
	/*Creat uniqe Patient Node*/
	int Options,pos,gender,age,ID,f,i;
	char Name[10];
	char tryAgain;
	int size =0;

	List_voidList(ps);

	printf("/****** You are in admin mode ******\\\n");
	printf("\n");


	printf("\n");
	do
	{
		printf("Press 1 to add new patient .\nPress 2 to edit patient record .\nPress 3 to reserve a slot with the doctor .\nPress 4 to cancel reservation.\nPress 0 to close .");
		printf("\n");
		printf("Enter your option : ");
		scanf("%d",&Options);
		printf("\n");
		switch (Options)
		{
		case 0:printf("Thank you for us our program :) ");break;

		case 1:
			do {

				size =List_voidSize(ps);

				printf("Number of patients in the row : %d ",size);
				printf("\n");

				printf("Please enter the name of the patient: ");
				scanf("%s", &Name);
				printf("\n");

				printf("Please enter the ID of the patient: ");
				scanf("%d", &ID);

				f=ID_Check(ID,ps);
				while(f==1)
				{   
					printf("\n");
					printf("entered ID number is exist, try again : ");
					scanf("%d",&ID);
					f=ID_Check(ID,ps);

				}
				printf("\n");

				printf("Please enter the patient number in row: ");
				scanf("%d", &pos);
				printf("\n");
				if(pos<=size)
				{
					printf("Wrong enter row number try again : ");
					scanf("%d",&pos);
				}
				printf("\n");

				printf("Please enter the age of the patient: ");
				scanf("%d", &age);
				printf("\n");

				printf("Please enter the gender of the patient: ");
				scanf(" %c", &gender);
				printf("\n");

				List_voidInsert(pos-1, ps, ID, age,gender, Name);
				printf("\n");
				printf("Do you want to add another patient? (Y/N) : ");
				scanf(" %c", &tryAgain);
			} while (tryAgain == 'Y' || tryAgain == 'y');

			break;



		case 2:
			printf("Please enter patient ID for edit his info : ");
			scanf("%d",&ID);
			printf("\n");
			if(List_voidSize(ps)>=1)
			{
				f=ID_Check(ID,ps);
				while(f!=1)
				{
					printf("entered ID number is exist, try again : ");
					scanf("%d",&ID);
					f=ID_Check(ID,ps);
				}
			}
			else 
			{
				printf("there is no patient");
			}

			if(List_voidSize(ps)>=1)
			{
				printf("Enter the new age : ");
				scanf("%d",&age);

				printf("\n");

				printf("Enter new name : ");
				scanf("%s",&Name);

				printf("\n");

				Patient_Edit(ps,ID,age,Name);

				printf("Edit complete");
			}


			break;
		case 3:
			do
			{ printf("Please enter patient ID to Reserve a slot with the doctor : ");
			scanf("%d",&ID);

			printf("\n");

			f=ID_Check(ID,ps);
			while(f!=0)
			{
				printf("entered ID number is exist, try again : ");
				scanf("%d",&ID);
				f=ID_Check(ID,ps);
			}
			Reserve_Slot(ID,1);
			printf("\n");
			printf("Do you want to reserve another slot? (Y/N) : ");
			scanf(" %c", &tryAgain);
			} while (tryAgain == 'Y' || tryAgain == 'y');
			break;
		case 4 :
			printf("Please enter patient ID for delete his info : ");
			scanf("%d",&ID);
			printf("\n");

			Reserve_Slot(ID,0);




			break;

		default:printf("You entered an invalid option .");break;

		}


		printf("Do you want to stay in admin mode ? (Y/N) : ");
		scanf(" %c", &tryAgain);
	}while(tryAgain == 'Y' || tryAgain == 'y');





}









void List_voidList(List *pl)
{
	pl->Head=NULL;

	pl->Size=0;
}





int List_voidSize(List *pl)
{
	return(pl->Size);
}





void List_voidInsert(int pos,List *pl,int ID,int age,char Gender,char *Name)
{

	int i=0;
	Patient_Node *pn = (Patient_Node *) malloc(sizeof(Patient_Node));

	pn->ID = ID;
	pn->Age=age;
	pn->Gender=Gender;

	while(Name[i]!='\0')
	{
		pn->Name[i]=Name[i];
		i++;
	}
	pn->Name[i]='\0';

	pn->Next = NULL;
	Patient_Node *Temp=pl->Head;
	if(pos==0)
	{
		pn->Next=pl->Head;
		pl->Head=pn;
	}
	else
	{
		for(i=0;i<pos-1;i++)
		{
			Temp=Temp->Next;
		}
		pn->Next=Temp->Next;
		Temp->Next=pn;

	}

	pl->Size++;


}


int ID_Check(int ID,List *pl)
{
	Patient_Node* t= pl->Head;
	int flag=0;

	while(t != NULL)
	{
		if(t->ID==ID)
		{
			flag=1;
		}

		t= t->Next;
	}
	return flag;

}

void Patient_Edit(List *pl,int ID,int New_age,char *New_name)
{
	int flag=1;
	int i=0;
	int j=0;
	Patient_Node* t= pl->Head;

	while(j<pl->Size)
	{
		if(t->ID==ID)
		{
			t->Age=New_age;
			while(New_name[i]!='\0')
			{
				t->Name[i]=New_name[i];
				i++;
			}
			t->Name[i]='\0';
		}


		t= t->Next;
		j++;
	}


}




void Cancel_Reservation(int ID,List *pl)
{
	Patient_Node *Temp=pl->Head;
	Patient_Node *Temp2=pl->Head;
	int i=0;
	int j=0;



	if(pl->Head->ID==ID)
	{
		pl->Head=pl->Head->Next;
		free(Temp);
	}
	else
	{

		while(Temp->ID!=ID)
		{
			Temp=Temp->Next;
			j++;
		}

		for(i=0;i<j-1;i++)
		{
			Temp2=Temp2->Next;
		}


		Temp2->Next=Temp->Next;
		free(Temp);

	}





	pl->Size--;


}


void Reserve_Slot(int ID,int mode)
{

	int i,x;
	char tryAgain;
	static int Slots[5]={1,1,1,1,1};

	if(mode==0)
	{
		while(id[i]!=ID)
		{
			if(id[i+1]==ID)
			{
				id[i+1]=0;
				Slots[i+1]=1;
				break;

			}

			i++;
		}

	}
	else
	{
		if(Slots[0]!=0)
		{
			printf("Press 1 for : 2:00pm - 2:30pm\n");
		}
		if(Slots[1]!=0)
		{
			printf("Press 2 for : 2:30pm - 3:00pm\n");
		}
		if(Slots[2]!=0)
		{
			printf("Press 3 for : 3:00pm - 3:30pm\n");
		}
		if(Slots[3]!=0)
		{
			printf("Press 4 for : 4:00pm - 4:30pm\n");
		}
		if(Slots[4]!=0)
		{
			printf("Press 5 for : 4:30pm - 5:00pm\n");
		}
		scanf("%d",&x);

		Slots[x-1]=0;
		id[x-1]=ID;
		printf("\n");
		printf("reserved");

	}













}


void List_voidPrint(List* pl,int ID)
{
	Patient_Node *Temp=pl->Head;

	while(Temp->ID!=ID)
	{
		Temp= Temp->Next;
	}

	printf("the patient name : %s\n",Temp->Name);
	fflush(stdout);

	printf("the patient age : %d\n",Temp->Age);
	fflush(stdout);
	printf("the patient gender : %c\n",Temp->Gender);   
	fflush(stdout); 

}
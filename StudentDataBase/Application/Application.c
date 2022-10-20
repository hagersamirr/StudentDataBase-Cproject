#include"../DataBase Module/SimpleDb.h"
#include "Application.h"
#include "stdio.h"

void App_Start()
{
          int input=0;
          int id , year;
          int grade[3];
          int subject [3];
          int  Count, List;
          int IdForSearch;
    printf("Press 1 to Check If The Database is Full or Not. \n");
    printf("Press 2 to Add a New Entry. \n");
    printf("Press 3 to Read an Entry. \n");
    printf("Press 4 to get ID List. \n");
    printf("Press 5 to check that an ID Is Exist. \n");
    printf("Press 6 to Delete an Entry. \n");
    printf("Press 7 to Get the Size of the Current Database. \n");
    scanf("%d",&input);
    switch(input)
    {
    case 1: //Check If The Database is Full or Not
        {
            if(SDB_IsFull()==TRUE)
             printf ("Database is Full \n");
             else
             printf ("Database is Not Full \n");
            break;
        }
    case 2: // Add a New Entry
        {
         printf ("Enter the Student ID \n");
         scanf("%d",&id);
          printf ("Enter the Entry year \n");
        scanf("%d",&year);
        for (int i =0; i<3 ; i++)
          {
            printf("Please Enter the ID of Subject %d \n",i+1);
            scanf("%d",&subject[i]);
            printf("Please Enter the grade of Subject %d \n",i+1);
            scanf("%d",&grade[i]);
          }

        SDB_AddEntry(id,year,&subject,&grade);
        break;
        }
    case 3: //Read an Entry
        {
            printf("Please Enter the ID to Search For \n");
                scanf("%d",&IdForSearch);
            SDB_ReadEntery(IdForSearch,&year,&subject,&grade);
            break;
        }
    case 4:
        {
            SDB_GetIdList(&Count,&List);
            break;
        }
    case 5:
        {
            printf("Please Enter the ID to check That If Exist\n");
                scanf("%d",&id);
                if( SDB_IsIdExist(id)== TRUE)
                       printf("This Entry Is Found In The Database\n");
                else
                     printf("This Entry Is Not Found In The Database !\n");
        break;
        }
    case 6:
        {
            printf("Please Enter the ID to Delete From the Database\n");
                scanf("%d",&id);
                SDB_DeleteEntry (id);
                break;
        }
    case 7:
        {
           printf("The used size: %d \n " , SDB_GetUsedSize());
                break;
        }
    default:
         {
                printf("Please Press Number From 1 to 7!\n");
                break;
            }
    }

}

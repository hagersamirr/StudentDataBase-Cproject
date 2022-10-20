#include <stdio.h>
#include "SimpleDb.h"
#define size 10
static uint8 count=0;
SimpleDb_t DataBase[size]={0}; // 0 -> 9

/*
Description: This function checks if the data base is full or not
*/
Bool_t SDB_IsFull(void)
{
if (count >= 10)
    return TRUE; // return 1 if the data base is full
else
    return FALSE;// return 0 otherwise not full
}
/*
Description: Get the number of entries in the database
This function takes void and return the number of entries
*/
uint8 SDB_GetUsedSize(void)
{
 return count;
}

/*
Description: Add new entry to the database
return True (1) if the new entry is successfully added; False (0)otherwise
*/
Bool_t SDB_AddEntry(int id, int year, int* subjects, int* grades)
{
 if (SDB_IsFull()== FALSE) // check if the database is full or not if it's not full you an add new entry
 {
    int index= -1;
    for (int i=0 ; i<10; i++)
    {
        if( (DataBase[i].Student_ID) == 0 ) //check for the first empty place in the database array
          {
               index = i;
               DataBase[index].Student_ID   = id;
               DataBase[index].Student_Year = year;
              for (int j =0; j<3 ;j++)
            {
                DataBase[index].Course_ID[j]= *(subjects+j);
                DataBase[index].Course_Grade[j] = *(grades+j);
            }
    count ++;
   printf ("The New Entry is Successfully Added \n");
    return TRUE;
 }
 }
}
else
{
      printf ("Sorry Database is FULL, You Cannot Add a New Entry! \n");
    return FALSE;
}
     }

/*
Description: Delete the entry with the given ID -- set them to zero
*/
void SDB_DeleteEntry(uint8 id)
{int idx = -1;
    for (int i =0; i<10; i++)
    {
                if (id == DataBase[i].Student_ID)
                {
                    idx=i;
                }
    }
    if(idx == -1)
        printf("This ID is Not Found in The Database ! \n");
    else
    {
        DataBase[idx].Student_ID   =0;
            DataBase[idx].Student_Year =0;
            for (int j =0; j<3 ;j++)
            {
                (DataBase[idx].Course_ID[j])= 0;
                (DataBase[idx].Course_Grade[j])=0;
            }
            printf("DONE! \n");
             count--;
    }

    }

/*
Description: Read an entry matching the provided ID
return True if the entry exist , zero otherwise
*/

Bool_t SDB_ReadEntery(int id, int* year, int* subjects, int* grades)
{
     for (int i =0; i<10; i++)
    {
        if (id == DataBase[i].Student_ID)
        {

            *year = DataBase[i].Student_Year;
            printf("The student year is %d \n", *year);
            for (int j =0; j<3 ;j++)
            {
               *(subjects) = (DataBase[i].Course_ID[j]);
                printf("The Course %d ID is %d \n",j+1,*subjects);
               *(grades)  = (DataBase[i].Course_Grade[j]);
                printf("The Course %d grade is %d \n", j+1, *grades);
            }
            return TRUE;

        }
        else
        {
            printf("This ID is Not Found in The Database ! \n");
            return FALSE;
        }

    }

}
/*
Description: Get the list of ids of the students
*/
void SDB_GetIdList(uint8* Count, uint8* List)
{
Count = &count;
printf ("The Number of Entries = %d\n", *Count);

for (int i=0; i<10; i++)
{
    *List= DataBase[i].Student_ID;
        printf ("The Id of entries = %d \n", *List);

}

}
/*
Description: Checks if the provided student ID exists
This function takes the needed id for search and return True if is exist
and return false if is not exist
*/
Bool_t SDB_IsIdExist(uint8 ID)
{
 for (int i =0; i<10; i++)
    {
        if (ID == DataBase[i].Student_ID)
            return TRUE;
        else
            return FALSE;
    }

}

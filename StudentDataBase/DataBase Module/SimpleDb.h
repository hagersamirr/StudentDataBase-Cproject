#ifndef SIMPLEDB_H_INCLUDED
#define SIMPLEDB_H_INCLUDED
typedef unsigned char uint8;

typedef struct SimpleDb
{
    uint8 Student_ID;
    uint8 Student_Year;
    uint8 Course_ID[3];
    uint8 Course_Grade[3];
}SimpleDb_t;

typedef enum boolean
{
    FALSE, TRUE
}Bool_t;


/*
Description: This function checks if the data base is full or not
*/
Bool_t SDB_IsFull(void);
/*
Description: Get the number of entries in the database
This function takes void and return the number of entries
*/
uint8 SDB_GetUsedSize(void);
/*
Description: Add new entry to the database
return True (1) if the new entry is successfully added; False (0)otherwise
*/
Bool_t SDB_AddEntry(int id, int year, int* subjects, int* grades);
/*
Description: Delete the entry with the given ID -- set them to zero
*/
void SDB_DeleteEntry(uint8 id);
/*
Description: Read an entry matching the provided ID
return True if the entry exist , zero otherwise
*/
Bool_t SDB_ReadEntery(int id, int* year, int* subjects, int* grades);
/*
Description: Get the list of ids of the students
*/
void SDB_GetIdList(uint8* Count, uint8* List);
/*
Description: Checks if the provided student ID exists
This function takes the needed id for search and return True if is exist
and return false if is not exist
*/
Bool_t SDB_IsIdExist(uint8 ID);
#endif // SIMPLEDB_H_INCLUDED

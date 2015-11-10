#include "exceptions.h"

/*
EXIT CODES
0 - 
1 - NO File Found
2 - Duplicates
3 - Type Conversion
4 - Type Error

*/

void Print_Column_Count_Error(int rowCount)
{
    printf("Column count at row %d of file does not match the header column count\n",rowCount);
}

void Print_No_File_Exception()
{
    printf("This file does not exist/ There is a file error\n");
}

void Print_Duplicate_Headers_Error(char* columnName)
{
    printf("The Column %s has a duplicate\n",columnName);
}

void Print_Type_Def_Error(int row)
{
    printf("The Column %d has a type error\n",row);
}
#ifndef exceptions_h
#define exceptions_h
#include <stdio.h>
#endif

void Print_Column_Count_Error(int linecount);

void Print_No_File_Exception();

void Print_Duplicate_Headers_Error(char* columnName);

void Print_Type_Def_Error(int row);
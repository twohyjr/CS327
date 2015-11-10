#ifndef util_h
#define util_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

//--------Prints the data type given by the users input---------------------------
void PrintHistogramRequest(char* filename, char* requestString,char* outputFileName);

void PrintMinRequest(char* filename, char* requestString,char* outputFileName);

void PrintMaxRequest(char* filename, char* requestString,char* outputFileName);

void PrintAverageRequest(char* filename, char* requestString,char* outputFileName);
//---------------------------------------------------------------------------------

//Creates a date struct in the format using the format mm/dd/yyyy-hh:mm
void createDateStruct(char* strDate, struct Date *date);

void createRange(char* filename, char* header, struct Date *begDate, struct Date *endDate, struct Range *range);

void createBinArray(char* filename, struct Bin **allBins, struct Range range);

int getWhichColumn(char* columnName, char **headers, int columns);

int getRowString(FILE* file, char **row);

int ReadUserInput(int argCount, char* argArr[]);

int RunQuery(char* dataFile,char* queryInputFile, char* outputFile);


#endif /* util_h */

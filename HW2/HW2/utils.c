#include "utils.h"
#include "exceptions.h"
#include "weatherio.h"
#include <stdlib.h>
#include <string.h>



int check_all_columns(char* filename, int headerCount)
{
    FILE* file;
    file = fopen(filename, "r");
    int errorCode = 0;
    char line [256];
    int linecount = 1;
    while ( fgets ( line, sizeof line, file ) != NULL )
    {
        const char delim[2] = ",";
        char *value;
        value = strtok(line, delim);
        int columnCount = 0;
        while( value != NULL )
        {
            columnCount += 1;
            value = strtok(NULL, delim);
        }
        if(columnCount != headerCount)
        {
            errorCode = linecount;
            Print_Column_Count_Error(linecount);
            return linecount;
        }
        linecount += 1;
        columnCount = 0;
    }
    
    return errorCode;
}

int check_duplicate_headers(char* filename)
{
    int error = 0;
    FILE *file;
    file = fopen(filename, "r");
    char **headers1 = (char**)malloc(sizeof(char*) * 5000);
    int ColumnCount1 = get_row_string(file, headers1);
    //printf("%d\n",ColumnCount);
    fclose(file);
    
    FILE *file2;
    file2 = fopen(filename, "r");
    char **headers2 = (char**)malloc(sizeof(char*) * 5000);
    get_row_string(file, headers2);
    fclose(file2);
    
    char* first;
    char* second;
    
    for (int i = 0; i < ColumnCount1; i++) {
        first = strtok(headers1[i], "\n");
        for (int j = i+1; j < ColumnCount1; j++) {
            second = strtok(headers2[j], "\n");
            if(strcmp(first, second) == 0)
            {
                Print_Duplicate_Headers_Error(headers1[i]);
                error = 2;
            }
        }
        if(error == 4)
        {
            break;
        }
    }
    return error;
    return 0;
}

int get_row_string(FILE* file, char **row)
{
    char headerStr[MAX_LINE_LENGTH];
    fgets(headerStr,MAX_LINE_LENGTH,file);
    
    row[0] = (void*)malloc(MAX_LINE_LENGTH * 100);
    
    char c = headerStr[0];
    char *p = row[0];
    int columnCount = 0;
    int i = 0;
    while (c != '\0') {
        c = headerStr[i];
        if(c != ',')
        {
            *p++ = c;
        }else //If it is a comma
        {
            *p = '\0';
            columnCount++;
            row[columnCount] = (char*)malloc(MAX_LINE_LENGTH);
            p = row[columnCount];
        }
        
        i++;
    }
    
    return columnCount+1;
}

int get_header_count(FILE* file,char** header)
{
    int count = 0;
    
    for (int i = 0; i < 100; i++) {
        if (header[i] == NULL) {
            break;
        }
        count++;
    }
    
    //printf("%d\n",count);
    return count;
}

int check_blank_row(char* filename)
{
    FILE* file;
    file = fopen(filename, "r");
    int linecount = 0;
    
    char **row = (char**)malloc(64*20);
    
    while (!feof(file)) {
        int columnCount = get_row_string(file, row);
        
        int ok = 0;
        for (int i = 0; i < columnCount;i++) {
            
        }
        
        if(ok == 1){
            linecount = 5;
        }
    }
    free(row);
    fclose(file);
    
    
    return linecount;
}
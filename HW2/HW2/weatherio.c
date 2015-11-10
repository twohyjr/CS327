#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exceptions.h"
#include "weatherio.h"
#include "utils.h"

int validate_format(char* filename)
{
    FILE *file;
    int lineError = 0;
    file = fopen(filename, "r");
    if(file == NULL)
    {
        Print_No_File_Exception(); //Checks file validity
        exit(0);
    }
    int headerCount = header_columns(filename);
    
    lineError = check_all_columns(filename,headerCount);
    if(lineError > 0)
    {
        return lineError;
    }
    lineError = check_blank_row(filename);
    if(lineError > 0)
    {
        return lineError;
    }
    lineError = check_duplicate_headers(filename);
    if(lineError > 0)
    {
        return lineError;
    }
    
    fclose(file);
    

    
    FILE* file2;
    file2 = fopen(filename, "r");
    
    char **headers = (char**)malloc(sizeof(char*) * 5000);
    get_row_string(file, headers);
    void **data = (void**)malloc(sizeof(void*) * 5000);
    int lineCount = 1;
    while(!feof(file))
    {
        lineCount++;
        lineError = read_row(file, headers, data);
        if(lineError > 0)
        {
            lineError = lineCount;
            break;
        }
    }
    
    fclose(file2);

    return lineError;
}

int header_columns(char* filename)
{
    FILE *file;
    file = fopen(filename, "r");
    int columnCount = 0;
    const char s[2] = ",";
    char *token;
    char headerStr[MAX_LINE_LENGTH];
    fgets(headerStr,MAX_LINE_LENGTH,file);
    token = strtok(headerStr, s);
    while( token != NULL )
    {
        columnCount += 1;
        token = strtok(NULL, s);
    }
    
    fclose(file);
    
    return columnCount;
}

int read_header(char *filename, char **headers)
{
    FILE *file;
    file = fopen(filename, "r");
    char headerStr[MAX_LINE_LENGTH];
    fgets(headerStr,MAX_LINE_LENGTH,file);
    headers[0] = (char*)malloc(MAX_LINE_LENGTH);

    char c = headerStr[0];
    char *p = headers[0];
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
            headers[columnCount] = (char*)malloc(MAX_LINE_LENGTH);
            p = headers[columnCount];
        }
        i++;
    }
    fclose(file);
    return columnCount + 1;
}

int read_row(FILE *file, char **headers, void **data)
{
    int errorLine = 0;
    char **myRow = (char**)malloc(sizeof(char*) * 5000);
    get_row_string(file, myRow);
    int headerCount = get_header_count(file,headers);
    
    //printf("%d\n",headerCount);
    
    for (int i =0; i < headerCount; i++) {
        
        if(strcasecmp(headers[i],"IDentification Name")==0 || strcasecmp(headers[i],"IDentification Name\n")==0)
        {
            data[i] = (char*)malloc(sizeof(char) * 64);
            data[i] = myRow[i];
            
        }else if(strcasecmp(headers[i],"USAF")==0 || strcasecmp(headers[i],"USAF\n")==0)
        {
            data[i] = malloc(sizeof(int) * 9);
            

        }else if(strcasecmp(headers[i],"NCDC")==0 || strcasecmp(headers[i],"NCDC\n")==0)
        {
            data[i] = malloc(sizeof(int) * 9);
            
           

        }else if(strcasecmp(headers[i],"Date")==0 || strcasecmp(headers[i],"Date\n")==0)
        {
            data[i] = malloc(sizeof(int) * 9);
            

        }else if(strcasecmp(headers[i],"HrMn")==0 || strcasecmp(headers[i],"HrMn\n")==0)
        {
            data[i] = malloc(sizeof(int) * 9);
            

        }else if(strcasecmp(headers[i],"I")==0 || strcasecmp(headers[i],"I\n")==0)
        {
            data[i] = malloc(sizeof(int) * 9);
            

        }else if(strcasecmp(headers[i],"Type")==0 || strcasecmp(headers[i],"Type\n")==0)
        {
            data[i] = (char*) malloc(sizeof(char) * 9);
            

        }else if(strcasecmp(headers[i],"QCP")==0 || strcasecmp(headers[i],"QCP\n")==0)
        {
            data[i] = (char*) malloc(sizeof(char) * 9);
            

        }else if(strcasecmp(headers[i],"Wind Dir")==0 || strcasecmp(headers[i],"Wind Dir\n")==0)
        {
            data[i] = malloc(sizeof(int) * 9);
            
        }
        else if(strcasecmp(headers[i],"Wind Dir Q")==0 || strcasecmp(headers[i],"Wind Dir Q\n")==0)
        {
            data[i] = malloc(sizeof(int) * 9);
            

        }else if(strcasecmp(headers[i],"Wind Dir I")==0 || strcasecmp(headers[i],"Wind Dir I\n")==0)
        {
            data[i] = (char*) malloc(sizeof(char) * 9);
            
            
        }else if(strcasecmp(headers[i],"Wind Spd")==0 || strcasecmp(headers[i],"Wind Spd\n")==0)
        {
            data[i] = malloc(sizeof(float) * 9);
            

        }else if(strcasecmp(headers[i],"Wind Spd Q")==0 || strcasecmp(headers[i],"Wind Spd Q\n")==0)
        {
            data[i] = malloc(sizeof(int) * 9);
            
            
        }else if(strcasecmp(headers[i],"Temp")==0 || strcasecmp(headers[i],"Temp\n")==0)
        {
            data[i] = (float*)malloc(sizeof(float) * 9);
            

        }else if(strcasecmp(headers[i],"Temp Q")==0 || strcasecmp(headers[i],"Temp Q\n")==0)
        {
            data[i] = malloc(sizeof(int) * 9);
            
            
        }else if(strcasecmp(headers[i],"Dewpt")==0 || strcasecmp(headers[i],"Dewpt\n")==0)
        {
            data[i] = (float*)malloc(sizeof(float) * 500);
            
            
        }else if(strcasecmp(headers[i],"Dewpt Q")==0 || strcasecmp(headers[i],"Dewpt Q\n")==0)
        {
            data[i] = malloc(sizeof(int) * 9);
            

        }else if(strcasecmp(headers[i],"Slp")==0 || strcasecmp(headers[i],"Slp\n")==0)
        {
            data[i] = (float*)malloc(sizeof(float) * 9);
            
            
        }else if(strcasecmp(headers[i],"Slp Q")==0 || strcasecmp(headers[i],"Slp Q\n")==0)
        {
            data[i] = malloc(sizeof(int) * 9);
           
            
        }else if(strcasecmp(headers[i],"RHx")==0 || strcasecmp(headers[i],"RHx\n")==0)
        {
            data[i] = malloc(sizeof(int) * 9);
            
        }else{
            errorLine = 2;
        }
        free(data[i]);
    }
    
    return errorLine;
}



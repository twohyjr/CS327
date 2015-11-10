#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "utils.h"
#include "weatherio.h"

//histogram Temp 5 01/01/2006-00:53 01/01/2006-18:53
void PrintHistogramRequest(char* filename, char* requestString, char* outputFileName){
    
    struct Date *begDate = malloc(sizeof(struct Date));
    struct Date *endDate = malloc(sizeof(struct Date));
    struct Range *range = malloc(sizeof(struct Range));
    struct Bin **allBins;
    
    char* requestType = malloc(sizeof(char)*64);
    char* header = malloc(sizeof(char)*64);
    char* binCount = malloc(sizeof(char)*10);
    char* start = malloc(sizeof(char)*20);
    char* end = malloc(sizeof(char)*20);
    
    sscanf(requestString, "%s %s %s %s %s", requestType,header,binCount,start,end);
    range->bins = atoi(binCount);
    allBins = malloc(sizeof(struct Bin)*atoi(binCount));
    
    createDateStruct(start, begDate);
    createDateStruct(end, endDate);
    
    createRange(filename, header, begDate, endDate, range);
    createBinArray(filename, allBins, *range);
    
    
    if(outputFileName == NULL){
        printf("Temp Range      Number Of Occurrences\n");
        for (int i = 0; i < atoi(binCount); i++) {
            printf("%.2f : %.2f       %d\n",allBins[i]->low,allBins[i]->high,allBins[i]->occurrences);
        }
    }else{
        fclose(fopen(outputFileName, "w"));
        FILE* file = fopen(outputFileName, "a");
        fprintf(file,"Temp Range      Number Of Occurrences\n");
        for (int i = 0; i < atoi(binCount); i++) {
            fprintf(file,"%.2f : %.2f       %d\n",allBins[i]->low,allBins[i]->high,allBins[i]->occurrences);
        }
        fclose(file);
        printf("PRINTED TO THE FILE %s\n",outputFileName);
    }
    
    
    free(requestType);
    free(header);
    free(binCount);
    free(start);
    free(end);
}

//min Temp 01/01/2006-00:53 01/01/2006-18:53
//min Temp 01/01/2014-00:00 12/31/2014-23:59
void PrintMinRequest(char* filename, char* requestString,char* outputFileName){
    struct Date *begDate = malloc(sizeof(struct Date));
    struct Date *endDate = malloc(sizeof(struct Date));
    struct Range *range = malloc(sizeof(struct Range));
    
    char* requestType = malloc(sizeof(char)*64);
    char* header = malloc(sizeof(char)*64);
    char* start = malloc(sizeof(char)*20);
    char* end = malloc(sizeof(char)*20);
    
    sscanf(requestString, "%s %s %s %s", requestType,header,start,end);
    
    createDateStruct(start, begDate);
    createDateStruct(end, endDate);
    
    createRange(filename, header, begDate, endDate, range);
    
    if(outputFileName == NULL){
        printf("MIN = %.2f\n", range->lowTemp);
    }else{
        fclose(fopen(outputFileName, "w"));
        FILE* file = fopen(outputFileName, "a");
        fprintf(file,"MIN = %.2f\n", range->lowTemp);
        fclose(file);
        printf("PRINTED TO THE FILE %s\n",outputFileName);
    }
    
    
}

//max Temp 01/01/2014-00:00 12/31/2014-23:59
void PrintMaxRequest(char* filename, char* requestString,char* outputFileName){
    struct Date *begDate = malloc(sizeof(struct Date));
    struct Date *endDate = malloc(sizeof(struct Date));
    struct Range *range = malloc(sizeof(struct Range));
    
    char* requestType = malloc(sizeof(char)*64);
    char* header = malloc(sizeof(char)*64);
    char* start = malloc(sizeof(char)*20);
    char* end = malloc(sizeof(char)*20);
    
    sscanf(requestString, "%s %s %s %s", requestType,header,start,end);
    
    createDateStruct(start, begDate);
    createDateStruct(end, endDate);
    
    createRange(filename, header, begDate, endDate, range);
    
    if(outputFileName == NULL){
        printf("MAX = %.2f\n", range->highTemp);
    }else{
        fclose(fopen(outputFileName, "w"));
        FILE* file = fopen(outputFileName, "a");
        fprintf(file,"MAX = %.2f\n", range->highTemp);
        fclose(file);
        printf("PRINTED TO THE FILE %s\n",outputFileName);
    }
    
    
}
//max Temp 01/01/2006-00:00 12/31/2006-17:55
void PrintAverageRequest(char* filename, char* requestString,char* outputFileName){
    struct Date *begDate = malloc(sizeof(struct Date));
    struct Date *endDate = malloc(sizeof(struct Date));
    struct Range *range = malloc(sizeof(struct Range));
    
    char* requestType = malloc(sizeof(char)*64);
    char* header = malloc(sizeof(char)*64);
    char* start = malloc(sizeof(char)*20);
    char* end = malloc(sizeof(char)*20);
    
    sscanf(requestString, "%s %s %s %s", requestType,header,start,end);
    
    createDateStruct(start, begDate);
    createDateStruct(end, endDate);
    
    createRange(filename, header, begDate, endDate, range);
    
    
    if(outputFileName == NULL){
        printf("Average = %.2f\n", range->average);
    }else{
        fclose(fopen(outputFileName, "w"));
        FILE* file = fopen(outputFileName, "a");
        fprintf(file,"Average = %.2f\n", range->average);
        fclose(file);
        printf("PRINTED TO THE FILE %s\n",outputFileName);
    }
}

void createBinArray(char* filename, struct Bin **allBins, struct Range range){
    FILE* file = fopen(filename, "r");
    char **headers = (char**)malloc(sizeof(char*) * 200);
    getRowString(file, headers);
    
    int rowCount = 1;
    int tempColumn = range.tempColumn;
    
    float currentTemp = range.lowTemp;
    float tempDivider = range.tempDivider;
    
    for(int i = 0; i < range.bins; i++){
        allBins[i] = malloc(sizeof(struct Bin));
        allBins[i]->low = currentTemp;
        currentTemp += tempDivider;
        allBins[i]->high = currentTemp;
    }
    
    while (!feof(file)) {
        if(rowCount+1 == range.begRow){
            break;
        }
        char **row = (char**)malloc(sizeof(char*) * 200);
        getRowString(file, row);
        rowCount++;
    }
    
    for (int i = 0; i < range.rowCount + 1; i++) {
        char **row = (char**)malloc(sizeof(char*) * 200);
        getRowString(file, row);
        float currentTemp = atof(row[tempColumn]);
        for (int j = 0; j < range.bins; j++) {
            float tempLow = allBins[j]->low;
            float tempHigh = allBins[j]->high;
            if(currentTemp >= tempLow && currentTemp <= tempHigh){
                allBins[j]->occurrences ++;
                break;
            }
        }
    }
    //fclose(file);
    
}

void createDateStruct(char* strDate,struct Date *date){
    char *cday = malloc(sizeof(char)*2);
    char *cmonth = malloc(sizeof(char)*2);
    char *cyear = malloc(sizeof(char)*4);
    char *chour = malloc(sizeof(char)*2);
    char *cmin = malloc(sizeof(char)*2);
    char* newDateString = malloc(sizeof(char)*8);
    char* fullTimeString = malloc(sizeof(char)*8);
    char* newTime;
    
    int index = 0;
    int timeCondense;
    
    //Loop for DAY creation
    for(int i = 0; i < 2; i++){
        char p = strDate[i];
        cday[index] = p;
        index++;
    }
    
    //Loop for MONTH creation
    index = 0;
    for(int i = 3; i < 5; i++){
        char p = strDate[i];
        cmonth[index] = p;
        index++;
    }
    
    //Loop for YEAR creation
    index  = 0;
    for(int i = 6; i < 10; i++){
        char p = strDate[i];
        cyear[index] = p;
        index++;
    }
    
    //Loop for HOUR creation
    index  = 0;
    for(int i = 11; i < 13; i++){
        char p = strDate[i];
        chour[index] = p;
        index++;
    }
    
    //Loop for MIN creation
    index  = 0;
    for(int i = 14; i < 16; i++){
        char p = strDate[i];
        cmin[index] = p;
        index++;
    }
    
    sprintf(newDateString, "%s%s%s",cyear,cday,cmonth);
    sprintf(fullTimeString, "%s%s",chour,cmin);
    
    timeCondense = atoi(fullTimeString);
    newTime = malloc(sizeof(char)*4);
    sprintf(newTime, "%d", timeCondense);
    
    date->day = atoi(cday);
    date->month = atoi(cmonth);
    date->year = atoi(cyear);
    date->hr = atoi(chour);
    date->min = atoi(cmin);
    date->fullDateString = atoi(newDateString);
    date->timeString = atoi(newTime);
}

void createRange(char* filename, char* header, struct Date *begDate, struct Date *endDate, struct Range *range){
    FILE* file = fopen(filename,"r");
    
    char **headers = (char**)malloc(sizeof(char*) * 200);
    int columnCount = getRowString(file, headers); //This pushes the row to the second row
    int dateColumn = getWhichColumn("Date", headers, columnCount);
    int timeColumn = getWhichColumn("HrMn", headers, columnCount);
    int tempColumn = getWhichColumn(header, headers, columnCount);
    
    int entered = 1;
    int rowCount = 2;
    int startRow = 0;
    int endRow = 0;
    int binCount = 0;
    
    float lowTemp = 0.0;
    float highTemp = 0.0;
    float tempDifference = 0.0;
    float tempDivider = 0.0;
    float averageTemp = 0.0;
    
    while (!feof(file)) {
        char **row = (char**)malloc(sizeof(char*) * 20);
        read_row(file, NULL, row);
        getRowString(file, row);
        int tempDate = atoi(row[dateColumn]);
        int tempTime = atoi(row[timeColumn]);
        float temp = atof(row[tempColumn]);
        
        if(tempDate == begDate->fullDateString && tempTime >= begDate->timeString && entered == 1){
            lowTemp = temp;
            highTemp = temp;
            startRow = rowCount;
            averageTemp += temp;
            entered = 0;
        }
        if(entered == 0){
            averageTemp += temp;
            if(temp < lowTemp){
                lowTemp = temp;
            }
            if(temp > highTemp && temp < 900){
                highTemp = temp;
            }
            if(tempDate == endDate->fullDateString && tempTime >= endDate->timeString){
                endRow = rowCount;
                break;
            }
            if(tempDate > endDate->fullDateString){
                endRow = rowCount - 1;
                break;
            }
        }
        rowCount += 1;
    }
    
    fclose(file);
    
    tempDifference = fabs(highTemp - lowTemp);
    binCount = range->bins;
    tempDivider = tempDifference/binCount;
    averageTemp = averageTemp/rowCount;
    
    range->dateColumn = dateColumn;
    range->timeColumn = timeColumn;
    range->begRow=startRow;
    range->endRow=endRow;
    range->rowCount = endRow-startRow+1;
    range->lowTemp = lowTemp;
    range->highTemp = highTemp;
    range->tempColumn = tempColumn;
    range->tempDifference = tempDifference;
    range->tempDivider = tempDivider;
    range->average = averageTemp;
}

int getWhichColumn(char* columnName, char **headers, int columns){
    
    for (int i = 0; i < columns; i++) {
        if(strcasecmp(headers[i], columnName)==0){
            return i;
        }
    }
    return 0;
}

int getRowString(FILE* file, char **row)
{
    if(file == NULL)exit(10);
    char headerStr[256];
    fgets(headerStr,256,file);
    
    row[0] = (void*)malloc(256);
    
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
            row[columnCount] = (char*)malloc(sizeof(char)*64);
            p = row[columnCount];
        }
        i++;
    }
    return columnCount+1;
}

//analyze df=AmesWeatherData.csv if=q.txt of=output.txt
int ReadUserInput(int argCount, char* arr[]){
    char *input;
    char *data;
    char *type = malloc(sizeof(char)*2);
    char *filename = malloc(sizeof(char)*256);
    char *query = malloc(sizeof(char)*256);
    char **dataStore = malloc(10000);
    char p;
    
    int isDF = 1;
    int isIF = 1;
    int isOF = 1;
    int quit = 1;
    
    for(int i = 1; i < argCount;i++){
        input = malloc(sizeof(char)*256);
        input = arr[i];
        
        for(int j = 0; j < 2; j++){
            type[j] = input[j];
        }
        data = malloc(sizeof(char)*256);
        int index = 0;
        int spot = 3;
        while(1){
            p = input[index];
            if(p == '\n')break;
            data[index] = input[spot];
            spot++;
            index++;
        }
        
        if(strcmp(type, "df") == 0){
            dataStore[0] = malloc(sizeof(char)*256);
            dataStore[0] = data;
            isDF = 0;
        }
        if(strcmp(type, "if") == 0){
            dataStore[1] = malloc(sizeof(char)*256);
            dataStore[1] = data;
            isIF = 0;
        }
        if(strcmp(type, "of") == 0){
            dataStore[2] = malloc(sizeof(char)*256);
            dataStore[2] = data;
            isOF = 0;
        }
    }
    
    
    if(isDF == 1){
        printf("Enter a Data-file filename please:");
        fgets (filename, sizeof(char)*256, stdin);
        filename[strlen(filename) - 1] = 0;
        dataStore[0] = filename;
    }
    if(isIF == 1){
        printf("Please Enter A Query:");
        fgets (query, sizeof(char)*256, stdin);
        query[strlen(query) - 1] = 0;
        dataStore[1] = query;
    }
    if(isOF == 1){
        
        printf("Output file not provided.  Printing out to the command line:\n");
        dataStore[2] = NULL;
    }
    
    quit = RunQuery(dataStore[0], dataStore[1], dataStore[2]);
    
//    printf("df = %s\n",dataStore[0]);
//    printf("if = %s\n",dataStore[1]);
//    printf("of = %s\n",dataStore[2]);
    return quit;
    
}
//char* filename, char* requestString
int RunQuery(char* dataFile,char* queryInputFile, char* outputFileName){
    char* request = malloc(sizeof(char)*64);
    
    sscanf(queryInputFile, "%s", request);

    if(strcmp(request, "histogram") == 0){
        PrintHistogramRequest(dataFile, queryInputFile, outputFileName);
        
    }else if(strcmp(request, "min") == 0){
        PrintMinRequest(dataFile, queryInputFile,outputFileName);
        
    }else if(strcmp(request, "max") == 0){
        PrintMaxRequest(dataFile, queryInputFile,outputFileName);
        
    }else if(strcmp(request, "average") == 0){
        PrintAverageRequest(dataFile, queryInputFile,outputFileName);
        
    }else if(strcmp(dataFile, "quit")){
        exit(0);
    }else{
        char* line = malloc(sizeof(char)*256);
        FILE* file = fopen(queryInputFile, "r");
        while (!feof(file)) {
            fgets(line,256,file);
            line[strlen(line) - 1] = 0;
            sscanf(line, "%s", request);
            
            if(strcmp(request, "histogram") == 0){
                PrintHistogramRequest(dataFile, line, outputFileName);
                
            }else if(strcmp(request, "min") == 0){
                PrintMinRequest(dataFile, line,outputFileName);
                
            }else if(strcmp(request, "max") == 0){
                PrintMaxRequest(dataFile, line,outputFileName);
                
            }else if(strcmp(request, "average") == 0){
                PrintAverageRequest(dataFile, line,outputFileName);
            }
        }
        fclose(file);
        return 0;
    }
    
    return 1;
}


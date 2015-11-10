#include<stdio.h>
#include "utils.h"


//histogram Temp 5 01/01/2006-01:53 01/01/2006-16:53
//histogram Temp 5 01/01/2014-00:00 12/31/2014-23:59
//min Temp 01/01/2014-00:00 12/31/2014-23:59
//max Temp 01/01/2014-00:00 12/31/2014-23:59
//average Temp 01/01/2014-00:00 12/31/2014-23:59

int main (int argc, char *argv[])
{
    
    int exitCode = 1;
    ///home/twohyjr/CS_327/HW3/AmesWeatherData.csv
    //char* arr1[] = {"garbage","df=/Users/Twohy/Documents/Fall2015/CS327/Hw3/AmesWeatherData.csv","if=histogram Temp 5 01/01/2006-01:53 01/01/2006-16:53","of=output.txt"};
    
    while (exitCode != 0) {
        exitCode = ReadUserInput(argc, argv);
    }
    
    return 0;
}

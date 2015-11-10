#include <stdio.h>
#include "weatherio.h"

int main(int argc, const char * argv[]) {
//    char* filename = "/home/twohyjr/CS_327/HW2/AmesWeatherDataTest.csv";
    
    //char* filename = "/home/twohyjr/CS_327/HW2/AmesWeatherDataTest.csv";
    //char* filename = "/Users/Twohy/Desktop/Homework2/AmesWeatherDataTest.csv";
    int lineError = 0;
    lineError = validate_format(argv[1]);
    //lineError = validate_format(filename);
    if(lineError == 0)
    {
        printf("%s\n","VALID");
    }else{
        printf("%s\n","INVALID");
    }
    
    return lineError;
}

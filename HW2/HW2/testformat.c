#include <stdio.h>
#include "weatherio.h"

int main(int argc, const char * argv[]) {
    char* filename = "/Users/Twohy/Documents/Fall2015/CS327/HW2/AmesWeatherData.csv";
    int lineError = 0;
    //lineError = validate_format(argv[1]);
    lineError = validate_format(filename);
    if(lineError == 0)
    {
        printf("%s\n","VALID");
    }else{
        printf("%s\n","INVALID");
    }
    
    return lineError;
}

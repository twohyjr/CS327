#include "StringConversion.h"


int StringConversion::getIntFromString(string str){
    std::istringstream ss(str);
    int i;
    ss >> i;
    if (ss.fail())
    {
        //exit(-1);
    }
    return i;
}

float StringConversion::getFloatFromString(string str){
    std::istringstream ss(str);
    float i;
    ss >> i;
    if (ss.fail())
    {
        //exit(-1);
    }
    return i;
}

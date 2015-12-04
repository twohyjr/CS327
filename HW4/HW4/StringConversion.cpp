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

std::string StringConversion::getStringFromInt(int num){
    ostringstream myString;
    myString << num;
    
    return myString.str();
}

std::string StringConversion::getStringFromFloat(float num){
    ostringstream myString;
    myString << num;
    
    return myString.str();
}

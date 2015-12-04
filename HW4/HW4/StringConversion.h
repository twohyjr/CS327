#ifndef StringConversion_h
#define StringConversion_h

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class StringConversion{
public:
    int getIntFromString(string str);
    float getFloatFromString(string str);
    std::string getStringFromInt(int num);
    std::string getStringFromFloat(float num);
};

#endif

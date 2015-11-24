#ifndef SoundFile_h
#define SoundFile_h

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include "StringConversion.h"

using namespace std;

class SoundFile {
public:
    virtual void getDataFromFile() = 0;
    virtual void display() = 0;
};

#endif

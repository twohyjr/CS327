#ifndef SoundFile_hpp
#define SoundFile_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class SoundFile {
public:
    virtual void getDataFromFile() = 0;
    virtual void display() =0;
    
};

#endif /*  SoundFile_hpp */

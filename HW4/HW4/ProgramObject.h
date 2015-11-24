#ifndef ProgramObject_h
#define ProgramObject_h

#include <unistd.h>
#include <stdlib.h>
#include "SoundFile.h"
#include "Cs229File.h"
#include "WavFile.h"
#include "ABC229File.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class ProgramObject{
    
public: //Constructors
    ProgramObject();
    ProgramObject(int fileCount, char *filenames[], std::string programName);
    
private: //Private Methods
    void createFileArray(int fileCount, char *filenames[]);
    
public:
    std::string createFileType(std::string filename);
    void display();
public:
    int fileCount;
    SoundFile** sounds;
    std::string programName;
    void checkForFlags();
};

#endif

#ifndef ProgramObject_hpp
#define ProgramObject_hpp

#include "SoundFile.hpp"
#include "Cs229File.hpp"
#include "WavFile.hpp"
#include "ABC229File.hpp"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class ProgramObject{
    
public: //Constructors
        ProgramObject();
        ProgramObject(int fileCount, const char *filenames[], string programName);
    
private: //Private Methods
    void createFileArray(int fileCount, const char *filenames[]);
    
public:
	string createFileType(string filename);
public:
    int fileCount = 0;
    SoundFile** sounds;
    string programName;
};

#endif /*     SoundObject_hpp */

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

/*
 	This class is used as an interface for my main program object.  Its job is to create an array of files with an array of
 	filenames given in the parameters. 
 	
 	If the parameters are empty it will instruct the user to input files.
 */

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

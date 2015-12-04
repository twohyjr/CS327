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
    ProgramObject(int fileCount,char *filenames[], std::string programName,int startPoint);
    
private: //Private Methods
    void createFileArray(int fileCount, char *filenames[]);
    void writeToFile(Cs229File newFile); //Writes to the output file if it isn't blank
    void writeToFile(WavFile newFile); //Writes to the output file if it isn't blank
    
public:
    std::string createFileType(std::string filename);
    void display();
public:
    int fileCount;
    int startPoint;
    std::string outputFile;
    SoundFile** sounds;
    std::string programName;
    void checkForFlags();
    Cs229File concatinateSoundFiles(int filecount, char *filenames[]);
    void exitWithError(std::string errorMsg, int error);
    Cs229File mixSoundFiles(int filecount, vector<std::string> filenames, vector<int> fileMulti);
};

#endif

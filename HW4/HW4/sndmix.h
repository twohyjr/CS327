#ifndef sndmix_hpp
#define sndmix_hpp
#include "ProgramObject.h"
#include "StringConversion.h"


/*
 (15 points)
 This program reads all sound files passed as arguments, and “mixes” them into a single sound file. 
 The program is invoked as
        sndmix [switches] mult1 file1 ...multn filen
 where the sample data of filei is multiplied by multi (a real value between -10 and 10); the scaled data is summed to produce the output file.
 
 SWITCHES
 1) -h : Shows the help screen
 2) -o file : specify the output file name; if omitted, write to standard output.
 */

#include <iostream>
#include <stdio.h>

using namespace std;
class sndmix : public ProgramObject{
    
public:
    sndmix();
    sndmix(int numberOfFiles,char *filenames[],std::string programName,int startPoint) : ProgramObject(numberOfFiles,filenames,programName,startPoint){}
public:
    int checkForFlags(int argCount, char *args[],sndmix* sound);
    void showHelpMenu();
    void createMixArrays(int count, char* parameters[], int startPoint);
public:
    int fileCount;
    vector<int> multipliers;
    vector<std::string> filenames;
    
};

#endif /* sndmix_hpp */

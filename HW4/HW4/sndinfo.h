#ifndef sndinfo_h
#define sndinfo_h
#include "ProgramObject.h"
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/*
 (10 points)
 This program reads all sound files passed as arguments, and for each one, displays the following.
 
 1) file name
 2) file type (.cs229 or optionally for bonus points .wav) sample rate
 3) bit depth
 4) number of channels
 5) number of samples
 6) length of the sound (in seconds)
 
 If no files are passed as arguments, then the program should read from standard input. The only required switch for this program is -h.
 */
using namespace std;
class sndinfo : public ProgramObject{
public:
    sndinfo();
    sndinfo(int numberOfFiles,char *filenames[],std::string programName) : ProgramObject(numberOfFiles,filenames,programName){}
public:
    int checkForFlags(int argCount, char *args[]);
    void showHelpMenu();
};

#endif /* sndinfo_h */

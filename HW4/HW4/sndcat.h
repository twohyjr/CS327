#ifndef sndcat_h
#define sndcat_h
#include "ProgramObject.h"

/*
 (15 points)
 This program reads all sound files passed as arguments, and writes a single sound file that is the concatenation of the inputs.
 Note that there are situations that make it hard to concatenate sound files such as ones with different numbers of channels.
 You must choose how to resolve these types of situations. One way here is to convert each sound to the maximum number of channels of any sound file, or simply give an error to the user.
 
 SWITCHES
 
 1) -h : Shows the help screen
 2) -o file : specify the output file name; if omitted, write to standard output.
 3) -w : optionally for bonus points output in .wav format instead of .cs229 format.
 */

#include <stdio.h>
#include <iostream>

using namespace std;
class sndcat : public ProgramObject{
    
public:
    sndcat();
    sndcat(int numberOfFiles,char *filenames[],std::string programName,int startPoint) : ProgramObject(numberOfFiles,filenames,programName,startPoint){}
public:
    int checkForFlags(int argCount, char *args[],sndcat* sound);
    void showHelpMenu();
};

#endif /* sndcat_hpp */

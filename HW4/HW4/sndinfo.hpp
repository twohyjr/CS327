#ifndef sndinfo_hpp
#define sndinfo_hpp
#include "ProgramObject.hpp"


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


class sndinfo : public ProgramObject{
public:
    sndinfo(int numberOfFiles, const char *filenames[],string programName) : ProgramObject(numberOfFiles,filenames,programName){}
    
};

#endif /* sndinfo_hpp */

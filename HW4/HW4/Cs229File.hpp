#ifndef Cs229File_hpp
#define Cs229File_hpp

#include "SoundFile.hpp"

class Cs229File: public SoundFile {
public:
    Cs229File(string filename,string filetype){
        this->filename = filename;
        this->fileType = filetype;
        getDataFromFile();
    }
    void getDataFromFile();
    void display();
private:
    string filename = "";
    string fileType = "";
    float sampleRate = 0;
    int bitDepth = 0;
    int numberOfChannels = 0;
    int numberOfSamples = 0;
    double lengthOfSound = 0;
};

#endif /* Cs229File_hpp */



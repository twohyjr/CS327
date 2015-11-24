#ifndef Cs229File_hpp
#define Cs229File_hpp


#include "SoundFile.h"
#include "Sample.h"
#include <vector>

class Cs229File: public SoundFile {
public:
    Cs229File();
    Cs229File(std::string filename,std::string filetype){
        this->filename = filename;
        this->fileType = filetype;
        getDataFromFile();
    }
    void getDataFromFile();
    void display();
    float getFloatFromString(string str);
    float getIntFromString(string str);
    bool checkSampleRangeValues(Sample sample);
public:
    std::string filename;
    std::string fileType;
    float sampleRate;
    int bitDepth;
    int numberOfChannels;
    int numberOfSamples;
    double lengthOfSound;
   	vector<Sample> samples;
};

#endif /* Cs229File_hpp */



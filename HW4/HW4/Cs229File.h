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
        sampleRate = 0;
        bitDepth = 0;
        numberOfChannels = 0;
        numberOfSamples = 0;
        lengthOfSound = 0;
        getDataFromFile();
    }
    void getDataFromFile();
    std::string getDisplay();
    float getFloatFromString(string str);
    float getIntFromString(string str);
    bool checkSampleRangeValues(Sample sample);
    std::string printSamples();
    std::string createNewFile(std::string programName);
public:
    std::string filename;
    std::string fileType;
    float sampleRate;
    int bitDepth;
    int numberOfChannels;
    int numberOfSamples;
    double lengthOfSound;
    void addSample(std::vector<int> channels, int multi);
   	vector<Sample> samples;
};

#endif /* Cs229File_hpp */
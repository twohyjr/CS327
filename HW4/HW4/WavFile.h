#ifndef WavFile_h
#define WavFile_h
typedef int DWORD;
#include "SoundFile.h"

class WavFile: public SoundFile {
public:
    WavFile(std::string filename,std::string filetype){
        this->filename = filename;
        this->fileType = filetype;
        getDataFromFile();
    }
    void getDataFromFile();
    std::string getDisplay();
private:
    std::string filename;
    std::string fileType;
    char type[4];
    DWORD size, chunkSize;
    short formatType, channels;
    DWORD sampleRate, averageBytesPerSecond;
    short bytesPerSample, bitsPerSample;
    DWORD dataSize;
    
};


#endif 

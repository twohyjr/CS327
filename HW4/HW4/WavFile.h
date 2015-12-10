#ifndef WavFile_h
#define WavFile_h
typedef int DWORD;
#include "SoundFile.h"
#include <cstring>

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
    DWORD size;
    DWORD chunkSize;
    short formatType;
    short channels;
    DWORD sampleRate;
    DWORD averageBytesPerSecond;
    short bytesPerSample;
    short bitsPerSample;
    DWORD dataSize;
    
};


#endif 

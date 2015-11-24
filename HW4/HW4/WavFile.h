#ifndef WavFile_h
#define WavFile_h

#include "SoundFile.h"

class WavFile: public SoundFile {
public:
    WavFile(std::string filename,std::string filetype){
        this->filename = filename;
        this->fileType = filetype;
        getDataFromFile();
    }
    void getDataFromFile();
    void display();
private:
    std::string filename;
    std::string fileType;
};


#endif 

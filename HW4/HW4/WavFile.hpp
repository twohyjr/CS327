#ifndef WavFile_hpp
#define WavFile_hpp

#include "SoundFile.hpp"

class WavFile: public SoundFile {
public:
    WavFile(string filename,string filetype){
        this->filename = filename;
        this->fileType = filetype;
        getDataFromFile();
    }
    void getDataFromFile();
    void display();
private:
    string filename = "";
    string fileType = "";
};


#endif /* WavFile_hpp */

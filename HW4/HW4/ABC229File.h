#ifndef ABC229File_h
#define ABC229File_h

#include "SoundFile.h"
#include "Instrument.h"

class ABC229File: public SoundFile {
public:
    ABC229File();
    ABC229File(std::string filename,std::string filetype){
        this->filename = filename;
        this->fileType = filetype;
        getDataFromFile();
    }
    void getDataFromFile();
    void display();
private:
    int numberOfInstruments;
    std::string filename;
    std::string fileType;
    int tempo;
    Instrument **instruments;

private:
    void addInstrument(std::ifstream myfile);
};

#endif /* ABC229File_hpp */

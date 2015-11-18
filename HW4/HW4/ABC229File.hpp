#ifndef ABC229File_hpp
#define ABC229File_hpp

#include "SoundFile.hpp"
#include "Instrument.hpp"

class ABC229File: public SoundFile {
public:
    ABC229File(string filename,string filetype){
        this->filename = filename;
        this->fileType = filetype;
        getDataFromFile();
    }
    void getDataFromFile();
    void display();
private:
    int numberOfInstruments = 0;
    string filename = "";
    string fileType = "";
    int tempo = 0;
    Instrument **instruments;

private:
    void addInstrument(ifstream myfile);
    
};

#endif /* ABC229File_hpp */

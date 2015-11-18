#ifndef ABC229File_hpp
#define ABC229File_hpp

#include "SoundFile.hpp"

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
    string filename;
    string fileType;
};

#endif /* ABC229File_hpp */

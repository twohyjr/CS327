#include "WavFile.hpp"


void WavFile::getDataFromFile(){
    
    display();
}

void WavFile::display(){
    cout << "--------------------WAV FILE-----------------------" << endl;
    cout << "Filename:----------- " <<  this->filename << endl;
    cout << "File Type:---------- " <<  this->fileType << endl;
    cout << "---------------------------------------------------" << endl;
    cout << endl;
}




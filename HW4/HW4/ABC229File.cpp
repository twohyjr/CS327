#include "ABC229File.hpp"


void ABC229File::getDataFromFile(){
    display();
}


void ABC229File::display(){
    cout << "--------------------WAV FILE-----------------------" << endl;
    cout << "Filename:----------- " <<  this->filename << endl;
    cout << "File Type:---------- " <<  this->fileType << endl;
    cout << "---------------------------------------------------" << endl;
    cout << endl;
}


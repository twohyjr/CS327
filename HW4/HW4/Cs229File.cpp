#include "Cs229File.hpp"


void Cs229File::getDataFromFile(){
    string line;
    ifstream myfile (filename);
    if (myfile.is_open()){
        string word;
        while (getline (myfile,line)){
            if(line[0] != '#'){
                istringstream iss(line);
                while(iss >> word) {
                    transform(word.begin(), word.end(), word.begin(), ::tolower);
                    if (word.compare("samples") == 0){
                        iss >> word;
                        numberOfSamples = stof(word);
                    }else if (word.compare("bitres") == 0){
                        iss >> word;
                        bitDepth = stoi(word);
                    }else if (word.compare("samplerate") == 0){
                        iss >> word;
                        sampleRate = stoi(word);
                        lengthOfSound = (double)1/numberOfSamples;
                    }else if (word.compare("channels") == 0){
                        iss >> word;
                        numberOfChannels = stoi(word);
                    }
                }
            }
        }
        myfile.close();
    }else{
        cout << "Unable to open file\n";
        exit(0);
    }
    
    display();
}

void Cs229File::display(){
    cout << "-----------------Cs229 File--------------------------" << endl;
    cout << "Filename:----------- " <<  this->filename << endl;
    cout << "File Type:---------- " <<  this->fileType << endl;
    cout << "Sample Rate:-------- " <<  this->sampleRate << endl;
    cout << "Bit Depth:---------- " <<  this->bitDepth << endl;
    cout << "Number Of Channels:- " <<  this->numberOfChannels << endl;
    cout << "Number Of Samples:-- " <<  this->numberOfSamples << endl;
    cout << "Length Of Sound:---- " <<  this->lengthOfSound << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;
}



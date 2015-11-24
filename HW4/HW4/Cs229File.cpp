#include "Cs229File.h"


void Cs229File::getDataFromFile(){
    std::string line;
    StringConversion strCon;
    int count = 0;
    std::ifstream myfile (filename.c_str());
    if(myfile.peek() == std::ifstream::traits_type::eof()){
        cout << "Not A Valid File" << endl;
        exit(-1);
    }
    if (myfile.is_open()){
        std::string word;
        while (getline (myfile,line)){
            count++;
            if(line[0] != '#'){
                std::istringstream iss(line.c_str());
                while(iss >> word) {
                    transform(word.begin(), word.end(), word.begin(), ::tolower);
                    if (word.compare("samples") == 0){
                        iss >> word;
                        numberOfSamples = strCon.getFloatFromString(word);
                    }else if (word.compare("bitres") == 0){
                        iss >> word;
                        bitDepth = strCon.getIntFromString(word);

                    }else if (word.compare("samplerate") == 0){
                        iss >> word;
                        sampleRate = strCon.getIntFromString(word);
                        lengthOfSound = (double)1/numberOfSamples;

                    }else if (word.compare("channels") == 0){
                        iss >> word;
                        numberOfChannels = strCon.getIntFromString(word);

                    }else if(word.compare("startdata") == 0){
                        int sampleCount = 0;
                        while(getline(myfile, line)){
                            string frequency;
                            string high;
                            string low;
                            std::istringstream iss2(line.c_str());
                            iss2 >> frequency;
                            iss2 >> high;
                            iss2 >> low;
                            
                            int newFrequency = strCon.getIntFromString(frequency);
                            int newHigh = strCon.getIntFromString(high);
                            int newLow = strCon.getIntFromString(low);
                            samples.push_back(*new Sample(newFrequency,newHigh,newLow));
                            if(!checkSampleRangeValues(samples[sampleCount])){
                                cout << "Sample Range Values Out Of Range" << endl;
                                exit(-1);
                            }
                        }
                        
                    }
                }
            }
        }
        myfile.close();
    }else{
        cout << "Unable to open file\n" << endl;
        exit(-1);
    }
    //display();
}

bool Cs229File::checkSampleRangeValues(Sample sample){
    
    //Checks the sample rate compared to a bit depth
    return true;
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
    
    cout << "Samples: ----------- ";
    
    for (int i = 0; i < numberOfSamples-1; i++) {
        cout << "[";
        cout << samples[i].getFrequency() << ", ";
        cout << samples[i].getHigh() << ", ";
        cout << samples[i].getLow()	 << "] ";
    }
    cout << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << endl;
}



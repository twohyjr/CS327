#include "Cs229File.h"

Cs229File::Cs229File(){
    filename = "";
    fileType = ".cs229";
    sampleRate = 0;
    bitDepth = 0;
   	numberOfChannels = 0;
    numberOfSamples = 0;
    lengthOfSound = 0;
}

void Cs229File::getDataFromFile(){
    std::string line;
    StringConversion strCon;
    int count = 0;
    std::ifstream myfile (filename.c_str());
    if(myfile.peek() == std::ifstream::traits_type::eof()){
        cout << filename + " is Not A Valid File" << endl;
        exit(-1);
    }
    if (myfile.is_open()){
        std::string word;
        while (getline (myfile,line)){
            
            if(line.compare("Cs229") != 0 && count == 0){
                cout << "NO Cs229 Line To Match" << endl;
                exit(-1);
            }
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
                        lengthOfSound = (double)numberOfSamples/sampleRate;

                    }else if (word.compare("channels") == 0){
                        iss >> word;
                        numberOfChannels = strCon.getIntFromString(word);

                    }else if(word.compare("startdata") == 0){
                        while(getline(myfile, line)){
                            std::istringstream iss2(line.c_str());
                            std::string channel;
                            vector<int> channels;
                            while (iss2 >> channel) {
                                channels.push_back(strCon.getIntFromString(channel));
                                
                            }
                            samples.push_back(*new Sample(channels));
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
}

void Cs229File::addSample(std::vector<int> channels, int multi){
    for (int i = 0; i < (int)(channels.size()); i++) {
        channels[i] = channels[i] * multi;
    }
     samples.push_back(*new Sample(channels));
}

bool Cs229File::checkSampleRangeValues(Sample sample){
    
    //Checks the sample rate compared to a bit depth
    return true;
}

std::string Cs229File::createNewFile(std::string programName){
    StringConversion con;
    std::string newFileString;
    newFileString.append("Cs229\n");
    newFileString.append("\n");
    newFileString.append("#This File Was Created By " + programName + "\n");
    newFileString.append("\n");
    newFileString.append("Samples       " + con.getStringFromInt(numberOfSamples) + "\n");
    newFileString.append("\n");
    newFileString.append("Channels      " + con.getStringFromInt(numberOfChannels) + "\n");
    newFileString.append("\n");
    newFileString.append("BitRes        " + con.getStringFromInt(bitDepth) + "\n");
    newFileString.append("\n");
    newFileString.append("SampeleRate   " + con.getStringFromFloat(sampleRate) + "\n");
    newFileString.append("\n");
    newFileString.append("StartData\n");
    newFileString.append(printSamples());
    
    return newFileString;
}
//+-(2^n-1)-1

std::string Cs229File::printSamples(){
    std::string sampleString;
    StringConversion con;
    
    for (int i = 0; i < numberOfSamples; i++) {
        int nums = (int)(samples[i].channels.size());
        for (int j = 0; j < nums; j++) {
            sampleString.append(con.getStringFromInt(samples[i].channels[j]));
            
            if(j != nums-1){
                sampleString.append("   ");
            }
        }
        sampleString.append("\n");
    }
    sampleString.append("\n");
    return sampleString;
}

std::string Cs229File::getDisplay(){
    StringConversion con;
    std::string csOutString;
    csOutString.append("-----------------Cs229 File--------------------------\n");
    csOutString.append("Filename:----------- " + this->filename + '\n');
    csOutString.append("File Type:---------- " + this->fileType + '\n');
    csOutString.append("Sample Rate:-------- " + con.getStringFromFloat(this->sampleRate) + '\n');
    csOutString.append("Bit Depth:---------- " + con.getStringFromInt(this->bitDepth) + '\n');
    csOutString.append("Number Of Channels:- " + con.getStringFromInt(this->numberOfChannels) + '\n');
    csOutString.append("Number Of Samples:-- " + con.getStringFromInt(this->numberOfSamples) + '\n');
    csOutString.append("Length Of Sound:---- " + con.getStringFromFloat(this->lengthOfSound) + '\n');
    //csOutString.append(printSamples());
    csOutString.append("-----------------------------------------------------\n");
    return csOutString.c_str();
}



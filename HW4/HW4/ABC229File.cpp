#include "ABC229File.h"


void ABC229File::getDataFromFile(){
    instruments = new Instrument*[10];
    StringConversion strCon;
    int instrumentCount = 0;
    std::string line;
    std::ifstream myfile (filename.c_str());
    
    if(myfile.peek() == std::ifstream::traits_type::eof()){
        cout << "Not A Valid File" << endl;
        exit(-1);
    }
    if (myfile.is_open()){
        std::string word;
        while (getline (myfile,line)){
            if(line[0] != '%'){
                std::istringstream iss(line);
                while(iss >> word) {
                    transform(word.begin(), word.end(), word.begin(), ::tolower);
                    if (word.compare("tempo") == 0){
                        iss >> word;
                        tempo = strCon.getIntFromString(word);
                    }else if(word.compare("instrument") == 0){//<-----This is where I create instruments
                        iss >> word;
                        instruments[instrumentCount] = new Instrument();
                        if(instrumentCount != strCon.getIntFromString(word)){
                            cout << "Instrument Number Is Out Of Count!" << endl;
                        }
                        instruments[instrumentCount]->instrumentNumber = instrumentCount;
                        while (getline(myfile, line)) {
                            std::istringstream iss2(line);
                            iss2 >> line;
                            std::transform(line.begin(), line.end(), line.begin(), ::tolower);
                            if(line.compare("waveform") == 0){
                                iss2 >> line;
                                instruments[instrumentCount]->waveform = line;
                            }else if(line.compare("volume") == 0){
                                iss2 >> line;
                                instruments[instrumentCount]->volume = strCon.getFloatFromString(line);
                            }else if(line.compare("attack") == 0){
                                iss2 >> line;
                                instruments[instrumentCount]->attack= strCon.getFloatFromString(line);
                            }else if(line.compare("decay") == 0){
                                iss2 >> line;
                                instruments[instrumentCount]->decay = strCon.getFloatFromString(line);
                            }else if(line.compare("sustain") == 0){
                                iss2 >> line;
                                instruments[instrumentCount]->sustain = strCon.getFloatFromString(line);
                            }else if(line.compare("release") == 0){
                                iss2 >> line;
                                instruments[instrumentCount]->release = strCon.getFloatFromString(line);
                            }else if(
                            	line.compare("score") == 0){
                                iss2 >> line;
                                getline(myfile, line);
                                getline(myfile, line);
                                instruments[instrumentCount]->score = line;
                                break;
                            }
                        }
                        instrumentCount++;
                    }
                }
            }
        }
        this->numberOfInstruments = instrumentCount;
        myfile.close();
    }else{
        cout << "Unable to open file\n";
    }
	//display();
}


void ABC229File::display(){
    cout << "--------------------ABC229 File--------------------" << endl;
    cout << "Filename:----------- " <<  this->filename << endl;
    cout << "File Type:---------- " <<  this->fileType << endl;
    cout << "Tempo:---------- " <<  this->tempo << endl;
    cout << "Number of Instruments: " <<  this->numberOfInstruments << endl;
    
    for (int i = 0; i < numberOfInstruments; i++) {
        cout << "_______________________________" << endl;
        cout << "        Instrument " << instruments[i]->instrumentNumber << endl;
        cout << "Waveform: " << instruments[i]->waveform << endl;
        cout << "Volume: " << instruments[i]->volume << endl;
        cout << "Attack: " << instruments[i]->attack<< endl;
        cout << "Decay: " << instruments[i]->decay << endl;
        cout << "Sustain: " << instruments[i]->sustain << endl;
        cout << "Release: " << instruments[i]->release << endl;
        cout << "Score: " << instruments[i]->score << endl;
    }
    
    cout << "---------------------------------------------------" << endl;
    cout << endl;
}




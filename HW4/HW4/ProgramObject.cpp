#include "ProgramObject.h"

ProgramObject::ProgramObject(){
    std::string filename;
    cout << "Please Enter A File Location"  << endl;
    cin >> filename;
   	sounds = new SoundFile*[fileCount];
    std::string type = createFileType(filename);
    std::string name = filename.c_str();
    if(type == ".cs229"){
        sounds[0] = new Cs229File(name, type);
    }else if(type == ".wav"){
        sounds[0] = new WavFile(name,type);
    } else if(type == ".ABC229"){
        sounds[0] = new ABC229File(name,type);
    }
}

ProgramObject::ProgramObject(int fileCount,char *filenames[], std::string programName,int startPoint){
    this->programName = programName;
    this->fileCount = fileCount;
    this->outputFile = "";
    this->startPoint = startPoint;
    if(programName.compare("sndmix") == 0){
        //Do nothing
    }else if(fileCount < 2){
        ProgramObject();
    }else{
        createFileArray(fileCount, filenames);
    }
}

//For every filename that is given to the program it creates a new sound file in the sounds array
void ProgramObject::createFileArray(int fileCount, char *filenames[]){
    sounds = new SoundFile*[fileCount];
    cout << fileCount - 1 << " Argument(s) Passed In To The Program " << programName << endl << endl;
    if(fileCount-1 == 0)exit(-1);
    int count = 0;
    for(int i = startPoint; i < fileCount; i++){
        std::string type = createFileType(filenames[i]);
        std::string name = filenames[i];
        if(type == ".cs229"){
            sounds[count] = new Cs229File(name, type);
            count++;
        }else if(type == ".wav"){
            sounds[count] = new WavFile(name,type);
            count++;
        } else if(type == ".ABC229"){
            sounds[count] = new ABC229File(name,type);
            count++;
        }
        type = "";
        name = "";
    }
}

Cs229File ProgramObject::concatinateSoundFiles(int filecount, char *filenames[]){
    int count = 0;
    vector<Cs229File> files;
    
    
    Cs229File newFile = *new Cs229File();
    newFile.filename = "Concated CS229 File";
    if(fileCount-1 < 2){
        exitWithError("Not Enough Files To Concatinate", -1);
    }
    
    //Get the first files information to be compared to
    Cs229File compareFile = *new Cs229File(filenames[startPoint],createFileType(filenames[startPoint]));
    newFile.bitDepth = compareFile.bitDepth;
    int currentChannelNumber = compareFile.numberOfChannels;
    
    for(int i = startPoint; i < fileCount; i++){
        std::string type = createFileType(filenames[i]);
        std::string name = filenames[i];
        if(type == ".cs229"){
            files.push_back(*new Cs229File(name,type));
            //Checks the validity of the new files else exits with error
            if(files[count].bitDepth != compareFile.bitDepth){
                exitWithError("Files Bit Depth Does Not Match", -1);
            }
            if(files[count].numberOfChannels != currentChannelNumber){
                exitWithError("Channels Do Not Match With Files", -1);
            }
            int x = files[count].numberOfSamples;

            for (int i = 0; i < x ; i++) {
                newFile.addSample(files[count].samples[i].channels, 1);
            }
            count++;
        }else{
            exitWithError("Wrong File Type Conversion", -1);
        }
        
    }
    newFile.numberOfChannels = currentChannelNumber;
    newFile.sampleRate = 1;
    int size =(int)(newFile.samples.size());
    newFile.numberOfSamples =size;
    newFile.lengthOfSound = (float)newFile.numberOfSamples/newFile.sampleRate;
    
    if(outputFile.compare("") != 0){
        writeToFile(newFile);
    }else{
        cout << newFile.createNewFile(programName) << endl;
    }
    return newFile;
}

Cs229File ProgramObject::mixSoundFiles(int filecount, vector<std::string> filenames, vector<int> fileMulti){
    vector<Cs229File> files;
    bool add = false;
    Cs229File newFile = *new Cs229File();
    newFile.filename = "Mixed CS229 File";
    
    //Get the first files information to be compared to
    Cs229File compareFile = *new Cs229File(filenames[0],createFileType(filenames[0]));
    newFile.bitDepth = compareFile.bitDepth;
    int currentChannelNumber = compareFile.numberOfChannels;
	
    //create the first generic sample
//    3	    6	 9
//    
//    12	15	 18
//    
//    21	24	 27
    
    for(int i = 0; i < (int)filenames.size(); i++){
        std::string type = createFileType(filenames[i]);
        std::string name = filenames[i];
        if(type == ".cs229"){
            files.push_back(*new Cs229File(name,type));
            
            //Checks the validity of the new files else exits with error
            if(files[i].bitDepth != compareFile.bitDepth){
                
                exitWithError("Files Bit Depth Does Not Match", -1);
            }
            if(files[i].numberOfChannels != currentChannelNumber){
                exitWithError("Channels Do Not Match With Files", -1);
            }
            files[i].numberOfSamples = compareFile.numberOfSamples;
            int x = files[i].numberOfSamples;
            
            for (int j = 0; j < x ; j++) {
               newFile.concatinateSamples(files[i].samples[j].channels, fileMulti[i], add);
               // newFile.addSample(files[i].samples[j].channels, fileMulti[i]);
            }
            newFile.rowCount = 0;
        }else{
            exitWithError("Wrong File Type Conversion", -1);
        }
         add = true;
    }
   
    newFile.numberOfChannels = currentChannelNumber;
    newFile.sampleRate = 1;
    int size =(int)(newFile.samples.size());
    newFile.numberOfSamples =size;
    newFile.lengthOfSound = (float)newFile.numberOfSamples/newFile.sampleRate;

    if(outputFile.compare("") != 0){
        writeToFile(newFile);
    }else{
        cout << newFile.createNewFile(programName) << endl;
    }
    return newFile;
}

void ProgramObject::display(){
    
    for(int i = 0; i < fileCount - 1; i++){
        cout << sounds[i]->getDisplay() << endl;
    }
}

void ProgramObject::writeToFile(Cs229File newFile){
    
    std::ofstream myfile(outputFile.c_str());
    myfile << newFile.createNewFile(programName).c_str();
    myfile.close();

}

std::string ProgramObject::createFileType(std::string filename){
    size_t i = filename.rfind('.', filename.length());
    if (i != std::string::npos) {
        return(filename.substr(i, filename.length() - i));
    }
    return "no file extension";
}

void ProgramObject::exitWithError(std::string errorMsg, int error){
    cout << errorMsg.c_str() << endl;
    exit(error);
}

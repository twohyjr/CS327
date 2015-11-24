#include "ProgramObject.h"

ProgramObject::ProgramObject(){
    std::string filename;
    cout << "Please Enter A File Location"  << endl;
    cin >> filename;
   	sounds = new SoundFile*[fileCount];
    std::string type = createFileType(filename);
    std::string name = filename;
    if(type == ".cs229"){
        sounds[0] = new Cs229File(name, type);
    }else if(type == ".wav"){
        sounds[0] = new WavFile(name,type);
    } else if(type == ".ABC229"){
        sounds[0] = new ABC229File(name,type);
    }
}

ProgramObject::ProgramObject(int fileCount,char *filenames[], std::string programName){
    this->programName = programName;
    if(fileCount < 2){
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
    for(int i = 1; i < fileCount; i++){
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

std::string ProgramObject::createFileType(std::string filename){
    size_t i = filename.rfind('.', filename.length());
    if (i != std::string::npos) {
        return(filename.substr(i, filename.length() - i));
    }
    return "no file extension";
}

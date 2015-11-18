#include "ProgramObject.hpp"

ProgramObject::ProgramObject(){
    //Executes command line insertion
}

ProgramObject::ProgramObject(int fileCount, const char *filenames[], string programName){
    this->programName = programName;
    if(fileCount < 1){
        ProgramObject();
    }else{
        createFileArray(fileCount, filenames);
    }
    
}

void ProgramObject::createFileArray(int fileCount, const char *filenames[]){
   
    sounds = new SoundFile*[fileCount];
    cout << fileCount << " Files Passed In From The Program " << programName << endl << endl;
    int count = 0;
    for(int i = 1; i < fileCount; i++){
        
        string type = createFileType(filenames[i]);
        string name = filenames[i];
        if(type == ".cs229"){
            Cs229File cs229 = *new Cs229File(name,type);
            sounds[count] = &cs229;
            count++;
            
        }else if(type == ".wav"){
            WavFile wav = *new WavFile(name,type);
            sounds[count] = &wav;
            count++;
        } else if(type == ".ABC229"){
            ABC229File abc = *new ABC229File(name,type);
            sounds[count] = &abc;
            count++;
        }
        type = "";
        name = "";
    }
}

string ProgramObject::createFileType(string filename){
    size_t i = filename.rfind('.', filename.length());
    if (i != string::npos) {
        return(filename.substr(i, filename.length() - i));
    }
    return "no file extension";
}
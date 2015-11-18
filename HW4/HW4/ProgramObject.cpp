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
    sounds[0]->display();
}

//For every filename that is given to the program it creates a new sound file in the sounds array
void ProgramObject::createFileArray(int fileCount, const char *filenames[]){
   
    sounds = new SoundFile*[fileCount];
    cout << fileCount - 1 << " Files Passed In From The Program " << programName << endl << endl;
    int count = 0;
    for(int i = 1; i < fileCount; i++){
        string type = createFileType(filenames[i]);
        string name = filenames[i];
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

string ProgramObject::createFileType(string filename){
    size_t i = filename.rfind('.', filename.length());
    if (i != string::npos) {
        return(filename.substr(i, filename.length() - i));
    }
    return "no file extension";
}
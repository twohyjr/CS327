#include "WavFile.h"

typedef int DWORD;

void WavFile::getDataFromFile(){
//    FILE *fp;
//    fp = fopen(filename.c_str(), "r");
//    if(!fp){
//        cout << "Wav File Error" << endl;
//    }
//    
//    //declarations
//    char type[4];
//    DWORD size, chunkSize;
//    short formatType, channels;
//    DWORD sampleRate, averageBytesPerSecond;
//    short bytesPerSample, bitsPerSample;
//    DWORD dataSize;
//    
//    //Reading line by line and setting each variable to the corrisponding value
//    
//    fread(type, sizeof(char), 4, fp);
//    if(!strcmp(type, "RIFF")){
//        cout << "Error : Not Riff Format" << endl;
//        exit(-1);
//    }
//    
//    fread(&size, sizeof(DWORD), 1, fp);
//    
//    fread(type, sizeof(char), 4, fp);
//    if(!strcmp(type, "WAVE")){
//        cout << "Error : Not WAVE Format" << endl;
//        exit(-1);
//    }
//    
//    fread(type, sizeof(char), 4, fp);
//    if(!strcmp(type, "fmt ")){
//        cout << "Error : Not fmt Format" << endl;
//        exit(-1);
//    }
//    
//    fread(&chunkSize, sizeof(DWORD), 1, fp);
//    fread(&formatType, sizeof(short), 1, fp);
//    fread(&channels, sizeof(short), 1, fp);
//    fread(&sampleRate, sizeof(DWORD),1,fp);
//    fread(&averageBytesPerSecond, sizeof(DWORD), 1, fp);
//    fread(&bytesPerSample, sizeof(short), 1, fp);
//    fread(&bitsPerSample, sizeof(short), 1, fp);
//    
//    fread(type, sizeof(char), 4, fp);
//    if(!strcmp(type, "data")){
//        cout << "Error : Missing Data" << endl;
//        exit(-1);
//    }
//    
//    fread(&dataSize,sizeof(DWORD),1,fp);
//
//    //if the file passes
//    this->chunkSize = chunkSize;
//    this->formatType = formatType;
//    this->channels = channels;
//    this->sampleRate = sampleRate;
//    this->averageBytesPerSecond = averageBytesPerSecond;
//    this->bytesPerSample = bytesPerSample;
//    this->bitsPerSample = bitsPerSample;
    
   //TODO CREATE/PRINT OUT SAMPLES

//    wchar_t p[8];
//    
//    while (!feof(fp)) {
//        fread(p, 8, 1, fp);
//        
//        wcout << p << endl;
//    }
//    fclose(fp);
}

std::string WavFile::getDisplay(){
    std::string outString;
    StringConversion con;
    outString.append("--------------------WAV FILE-----------------------\n");
    outString.append("Filename:-------------- " +  this->filename  + '\n');
    outString.append("File Type:------------- " +  this->fileType + '\n');
    outString.append("Chunk Size:------------ " +  con.getStringFromInt(chunkSize) + '\n');
    outString.append("Format Type:------------" + con.getStringFromInt(formatType) + '\n');
    outString.append("Channels:-------------- " + con.getStringFromInt(channels) + '\n');
    outString.append("Sample Rate:----------- " + con.getStringFromFloat(sampleRate) + '\n');
    outString.append("Avg Bytes Per Second:-- " + con.getStringFromFloat(averageBytesPerSecond) + '\n');
    outString.append("Bytes Per Sample:------ " + con.getStringFromInt(bytesPerSample) + '\n');
    outString.append("Bits Per Sample:------- " + con.getStringFromInt(bitsPerSample) + '\n');
    outString.append("---------------------------------------------------\n");
    
    return outString.c_str();
}


    



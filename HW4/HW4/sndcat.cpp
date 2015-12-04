#include "sndcat.h"

int main(int argc, char * argv[]) {
    int startPoint = 1;
    if(argc < 2)exit(-1);
    for (int i = 0; i < argc; i++) {
        std::string name;
        name = argv[i];
        if (name[0] == '-') {
            startPoint = i + 2;
        }
    }
    cout << "starting program sndcat" << endl;
    sndcat sound(argc,argv,"sndcat",startPoint);
    if(argc > 1 && sound.checkForFlags(argc, argv, &sound) == 0){
        sound.concatinateSoundFiles(argc, argv);
        
    }else{
        
        exit(0);
    }
    
    return 0;
}

int sndcat::checkForFlags(int argc, char *argv[], sndcat* sound){
    int tmp;
    int pass = 0;
    
    while((tmp = getopt(argc,argv,"h ,o:"))!=-1)
    {
        switch(tmp){
                /*option h show the help infomation*/
            case 'h':
                showHelpMenu();
                pass = 1;
                exit(0);
            case 'o':
                sound->outputFile = optarg;
                pass = 0;
                break;
            //case 'w':
            //TODO
                //--Create output as a wav file
            default:
                cout << "There was an error in the switch system" << endl;
                pass = 1;
        }
    }
    
    return pass;
}

void sndcat::showHelpMenu(){
    cout << "ABOUT:    sndcat is a program designed to concatinate multiple .cs229/.wav Files"	 << endl;
    cout << "USAGE:    To concatinate files"	 << endl;
    cout << "SWITCHES: -h (help menu)" << endl;
    cout << "          -o file(specifies output file)" << endl;
    cout << endl;
}
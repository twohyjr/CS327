#include "sndcat.h"

int main(int argc, char * argv[]) {
    sndcat sound(argc,argv,"sndcat");
    if(argc > 1 && sound.checkForFlags(argc, argv) == 0){
        //sound.sounds[1]->display();
        //sound.concatinateFiles();
        
    }else{
        exit(0);
    }
    return 0;
}

int sndcat::checkForFlags(int argc, char *argv[]){
    char tmp;
    int pass = 0;
    while((tmp = getopt(argc,argv,"h"))!=-1)
    {
        switch(tmp){
                /*option h show the help infomation*/
            case 'h':
                showHelpMenu();
                pass = 1;
                break;
            default:
                cout << "There was an error in the switch system" << endl;
                pass = 1;
        }
    }
    
    return pass;
}

void sndcat::showHelpMenu(){
    cout << "ABOUT:    sndinfo is a program designed to read different types of files (.ABC229, .cs229, .wav,etc...)"	 << endl;
    cout << "USAGE:    To get data from sound files"	 << endl;
    cout << "SWITCHES: -h (help menu)" << endl;
    cout << endl;
}
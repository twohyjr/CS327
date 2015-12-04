#include "sndinfo.h"

int main(int argc, char * argv[]) {
    int startPoint = 1;
    sndinfo sound(argc,argv,"sndinfo",startPoint);
    if(argc > 1 && sound.checkForFlags(argc, argv) == 0){
        sound.display();
    }else{
        exit(0);
    }
    return 0;
}

int sndinfo::checkForFlags(int argc, char *argv[]){
    int tmp;
    int pass = 0;
    
  
    while((tmp = getopt(argc,argv,"h"))!=-1)
    {
        switch(tmp){
            /*option h show the help infomation*/
            case 'h':
                showHelpMenu();
                pass = 1;
                exit(0);
            default:
                cout << "There was an error in the switch system" << endl;
                pass = 1;
        }
    }
    
    return pass;
}

void sndinfo::showHelpMenu(){
    cout << "ABOUT:    sndinfo is a program designed to read different types of files (.ABC229, .cs229, .wav,etc...)"	 << endl;
    cout << "USAGE:    To get data from sound files"	 << endl;
    cout << "SWITCHES: -h (help menu)" << endl;
    cout << endl;
}



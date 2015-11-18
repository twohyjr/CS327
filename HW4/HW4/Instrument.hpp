#ifndef Instrument_hpp
#define Instrument_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Instrument{
    
public:
    Instrument();
public:
    int instrumentNumber = 0;
    string waveform = "";
    double volume = 0;
    double attack = 0;
    double decay = 0;
    double sustain = 0;
    double release = 0;
    double pulsefrac = 0;
    string score = "";
};


#endif /* Instrument_hpp */

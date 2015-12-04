#ifndef Instrument_h
#define Instrument_h

#include <iostream>

class Instrument{
    
public:
    Instrument();
public:
    int instrumentNumber;
    std::string waveform;
    float volume;
    float attack;
    float decay;
    float sustain;
    float release;
    float pulsefrac;
    std::string score;
};

#endif

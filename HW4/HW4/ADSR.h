#ifndef ADRS_h
#define ADRS_h
#include <string>
#include <iostream>
using namespace std;
class ADSR {
public:
    ADSR();
    ADSR(float duration,float attackTime, float decayTime, float releaseTime, float peakV, float sustainV);
    void setAttackRate();
    void setDecayRate();
    void setReleaseRate();
    void setSustainLevel();
    void checkTimeConstraint(float currentTime, float startTime, float endTime);
    float getVolumeAtTime(float currentTime);
public:
    float peakVolume;
    float sustainVolume;
    float decayYint;
    float releaseYint;
    
    float output;
    float attackRate;
    float decayRate;
    float releaseRate;
    float sustainLevel;
    float totalDuration;
    
    float attackTime;
    float decayTime;
    float releaseTime;
    float sustainTime;
    
    float attackStart;
    float attackEnd;
    
    float decayStart;
    float decayEnd;
    
    float sustainStart;
    float sustainEnd;
    
    float releaseStart;
    float releaseEnd;
};

#endif

#include "ADSR.h"
#include <math.h>


ADSR::ADSR(float duration,float attackTime, float decayTime, float releaseTime, float peakV, float sustainV) {
    this->peakVolume = peakV;
    this->sustainVolume = sustainV;
    this->totalDuration = duration;
    this->attackTime = attackTime;
    this->decayTime = decayTime;
    this->releaseTime = releaseTime;
    this->sustainTime = totalDuration - attackTime - releaseTime - decayTime;
    this->attackStart = 0;
    this->attackEnd = attackTime;
    this->decayStart = attackEnd;
    this->decayEnd = attackEnd + decayTime;
    this->sustainStart = attackTime + decayTime;
    this->sustainEnd = attackTime + decayTime + sustainTime;
    this->releaseStart = attackTime + decayTime + sustainTime;
    this->releaseEnd = totalDuration;
    setAttackRate();
    setDecayRate();
    setSustainLevel();
    setReleaseRate();
}

void ADSR::setAttackRate() {
    attackRate  = (peakVolume - 0)/(attackTime - 0);
}

void ADSR::setDecayRate() {
    decayRate = (peakVolume - sustainVolume)/(attackEnd - decayEnd);
    decayYint = peakVolume - (decayRate * attackEnd);
}

void ADSR::setSustainLevel() {
    sustainLevel = sustainVolume;
}

void ADSR::setReleaseRate() {
    releaseRate = (sustainVolume - 0) / (sustainEnd - totalDuration);
    releaseYint = sustainVolume - (sustainEnd * releaseRate);
}

float ADSR::getVolumeAtTime(float currentTime){
    float volume = 0;
    if(currentTime < 0){
        cout << "YOU CAN'T ENTER A NEGATIVE TIME SILLY GOOSE!" << endl;
        //exit(-1);
    }else if(currentTime >= attackStart && currentTime < attackEnd){
        volume = attackRate * currentTime;
    }else if(currentTime >= decayStart && currentTime < decayEnd){
        volume = (decayRate * currentTime) + decayYint;
    }else if(currentTime >= sustainStart && currentTime < sustainEnd){
        volume = sustainLevel;
    }else if(currentTime >= releaseStart && currentTime < releaseEnd){
        volume =  (releaseRate * currentTime) + releaseYint;
    }else if(currentTime > totalDuration){
        cout << "TIME CANNOT BE GREATER THAT TOTAL DURATION" << endl;
        //exit(-1);
    }
    if(volume > 1){
        cout << "VOLUME CANNOT BE GREATER THAN 1" << endl;
        //exit(-1);
    }
    return volume;
}
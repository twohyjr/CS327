#include "Sample.h"

Sample::Sample(int frequency, int high, int low){
    this->frequency = frequency;
    this->high = high;
    this->low = low;
}

int Sample::getFrequency(){
    return this->frequency;
}

int Sample::getHigh(){
    return this->high;
}

int Sample::getLow(){
    return this->low;
}
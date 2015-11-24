#ifndef Sample_hpp
#define Sample_hpp

/*
 This class is used to create a sample object for the cs229File
 */

#include <stdio.h>

class Sample{
public:
    Sample(int frequecy, int high, int low);
private:
    int frequency;
    int high;
    int low;
public:
    int getFrequency();
    int getHigh();
    int getLow();
};

#endif /* Sample_hpp */

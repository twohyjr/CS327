#ifndef Sample_hpp
#define Sample_hpp

/*
 This class is used to create a sample object for the cs229File
 */

#include <stdio.h>
#include <vector>


class Sample{
public:
    Sample(std::vector<int> channels);
    Sample(std::vector<int> channels, int multi);
public:
    std::vector<int> channels;

};

#endif /* Sample_hpp */

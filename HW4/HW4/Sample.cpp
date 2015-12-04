#include "Sample.h"

Sample::Sample(std::vector<int> channels){
    for(int i = 0; i < (int)(channels.size()); i++){
        this->channels.push_back(channels[i]);
    }
}

Sample::Sample(std::vector<int> channels, int multi){
    for(int i = 0; i < (int)(channels.size()); i++){
        this->channels.push_back(channels[i] * multi);
    }
}

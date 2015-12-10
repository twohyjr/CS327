#ifndef sndgen_hpp
#define sndgen_hpp
#include "ProgramObject.h"
#include "ADSR.h"
#include <cmath>

/*
 (20 points)
 This program is a mess of switches.
 It produces a sound of a specified frequency and waveform (see Appendix C), using a simple ADSR envelope (see Appendix D).
 Note that the volume parameters are given as the percentage of the maximum volume.
 Note this program would benefit from several design patterns.
 
 SWITCHES
 1)  -h : show the help screen.
 2)  -o file : specify the output file name; if omitted, write to standard output.
 
 3)  -- bits n : useabitdepthofn
 4)  --sr n : useasamplerateofn
 
 5)  -f r : use a frequency of r Hz
 6)  -t r : total duration of r seconds
 7)  -v p : Peakvolume. 0 ≤ p ≤ 1
 
 8)  -a r : attack time of r seconds
 9) - d r : decay time of r seconds
 10) -s p : sustainvolume.0≤p≤1
 11) -r r : release time of r seconds
 
 12) --sine : generate a sine wave
 13) --triangle : generate a triangle wave
 14) --sawtooth : generate a sawtooth wave
 15) --pulse : generate a pulse wave
 16) --pf p : Fraction of the time the pulse wave is “up”
*/

using namespace std;
class sndgen : public ProgramObject{
public:
    sndgen();
    sndgen(int numberOfFiles,char *filenames[],std::string programName,int startPoint) : ProgramObject(numberOfFiles,filenames,programName,startPoint){}
public:
    int checkForFlags(int argCount, char *args[]);
    ADSR createADSR(sndgen gen);
    void showHelpMenu();
    void createWave(ADSR adsr);
    int checkSampleRangeValues(int channel);
public:
    std::string outputFile;
    int bits;
    int sampleRate;
    
    double frequency;
    double duration;
    double peakVolume;
    
    double attackTime;
    double decayTime;
    double sustainVolume;
    double releaseTime;
    
    bool sine;
    bool triangle;
    bool sawtooth;
    bool pulse;
    double pulseWaveUp;
    
    
};

#endif /* sndgen_hpp */

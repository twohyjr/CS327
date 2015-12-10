#include "sndgen.h"

using namespace std;

//./sndgen --bits 8 --sr 12 -f 1 -t 20 -v 1 -a 5 -d 5 -s .5 -r 5 —sine

int main(int argc, char * argv[]) {
    
    int startPoint = 1;
    sndgen sound(argc,argv,"sndgen",startPoint);
    sound.triangle = false;
    sound.sine = false;
    sound.sawtooth = false;
    sound.pulse = false;
    if(argc > 1 && sound.checkForFlags(argc, argv) == 0){
        ADSR adsr = sound.createADSR(sound);
        sound.createWave(adsr);
    }else{
        exit(0);
    }
    return 0;
}

int sndgen::checkForFlags(int argCount, char *args[]){
    StringConversion con;
    std::string check;
    int checkRequired = 0;
    for (int i = 1; i < argCount; i++) {
        check = args[i];
        if(check.compare("-o") == 0){
            outputFile = args[i + 1];
        	i += 1;
        }else if(check.compare("--bits") == 0){
            bits = con.getIntFromString(args[i + 1]);
            checkRequired += 1;
            i += 1;
        }else if(check.compare("--sr") == 0){
            sampleRate = con.getIntFromString(args[i + 1]);
            checkRequired += 1;
            i += 1;
        }else if(check.compare("-f") == 0){
            frequency = con.getFloatFromString(args[i + 1]);
            checkRequired += 1;
            i += 1;
        }else if(check.compare("-t") == 0){
            duration = con.getFloatFromString(args[i + 1]);
            checkRequired += 1;
            i += 1;
        }else if(check.compare("-v") == 0){
            peakVolume = con.getFloatFromString(args[i + 1]);
            checkRequired += 1;
            i += 1;
        }else if(check.compare("-a") == 0){
           attackTime = con.getFloatFromString(args[i + 1]);
            checkRequired += 1;
            i += 1;
        }else if(check.compare("-d") == 0){
            decayTime = con.getFloatFromString(args[i + 1]);
            checkRequired += 1;
            i += 1;
        }else if(check.compare("-s") == 0){
           sustainVolume = con.getFloatFromString(args[i + 1]);
            checkRequired += 1;
            i += 1;
        }else if(check.compare("-r") == 0){
            releaseTime = con.getFloatFromString(args[i + 1]);
            checkRequired += 1;
            i += 1;
        }else if(check.compare("--sine") == 0){
            if(triangle == true || sawtooth == true || pulse == true){
                cout << "Cannot use 2 wav forms" << endl;
                exit(-1);
            }
            sine = true;
        }else if(check.compare("--triangle") == 0){
            if(sine == true || sawtooth == true || pulse == true){
                cout << "Cannot use 2 wav forms" << endl;
                exit(-1);
            }
            triangle = true;
        }else if(check.compare("--sawtooth") == 0){
            if(triangle == true || sine == true || pulse == true){
                cout << "Cannot use 2 wav forms" << endl;
                exit(-1);
            }
            sawtooth = true;
        }else if(check.compare("--pulse") == 0){
            if(triangle == true || sawtooth == true || sine == true){
                cout << "Cannot use 2 wav forms" << endl;
                exit(-1);
            }
            pulse = true;
        }else if(check.compare("--pf") == 0){
           pulseWaveUp = con.getFloatFromString(args[i + 1]);
            i += 1;
        }
    }
    
    if(checkRequired != 9){
        cout << "Missing Parameters" << endl;
    }
    return 0;
}

ADSR sndgen::createADSR(sndgen gen){
    ADSR adsr(gen.duration,gen.attackTime, gen.decayTime, gen.releaseTime, gen.peakVolume, gen.sustainVolume);
    return adsr;
}

void sndgen::createWave(ADSR adsr){
   //cout << adsr.getVolumeAtTime(currentTime) << endl;
    std::string wavetype = " ";
    vector<int> waveform;
   	float numberOfSamples = duration * sampleRate;
    if(sine == true){
        for(int i=0;i<=numberOfSamples;i++) {
            double period = (double) i / sampleRate;
            float volume = adsr.getVolumeAtTime(period);
            waveform.push_back((int)((volume * checkSampleRangeValues(bits))*sin(frequency*period*2*M_PI)));
            wavetype = "SINE";
        }
    }else if(triangle == true){
        for(int i=0;i<=numberOfSamples;i++) {
            double period = (double) i / sampleRate;
            float volume = adsr.getVolumeAtTime(period);
			waveform.push_back((int)((2* (volume * checkSampleRangeValues(bits)))/M_PI) * asin(sin(((2 * M_PI)/ frequency) * period)));
       		wavetype = "TRIANGLE";
        }
    }else if(sawtooth == true){
        
        for(int i=0;i<=numberOfSamples;i++) {
            double period = (double) i / sampleRate;
            float volume = adsr.getVolumeAtTime(period);
            //int x = ((-2 * amplitude) / M_PI) * atan(1/tan(M_PI * frequency * sampleTime));
            waveform.push_back(((-2*(volume * 127))/M_PI) * atan(1/(tan((period * M_PI * frequency)))));
            wavetype = "SAWTOOTH";
        }
    }else if(pulse == true){
        
        
    }
    Cs229File file;
    file.addSample(waveform, 1);
    file.bitDepth = bits;
    file.sampleRate = sampleRate;
    //file.addSample(waveform, 1);
    for (int i = 0; i < (int)waveform.size(); i++) {
        file.samples[0].channels[i] = waveform[i];
    }
    file.numberOfSamples = 1;
    file.numberOfChannels = (int)waveform.size() - 1;
    if(outputFile.compare("") != 0){
        std::ofstream myfile(outputFile.c_str());
        myfile << file.printChannels(wavetype).c_str();
        myfile.close();
    }else{
        cout << file.printChannels(wavetype) << endl;
    }
}

int sndgen::checkSampleRangeValues(int bit){
    
    return (int)pow(2, bit-1)-1;
}

/*
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
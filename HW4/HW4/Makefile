OBJSCAT = sndcat.o ProgramObject.o SoundFile.o Cs229File.o WavFile.o ABC229File.o StringConversion.o Instrument.o Sample.o
OBJSINFO = sndinfo.o ProgramObject.o SoundFile.o Cs229File.o WavFile.o ABC229File.o StringConversion.o Instrument.o Sample.o
OBJSMIX = sndmix.o ProgramObject.o SoundFile.o Cs229File.o WavFile.o ABC229File.o StringConversion.o Instrument.o Sample.o
CC = g++
DEBUG = -g
CFLAGS = -pedantic -c $(DEBUG)
LFLAGS = -pedantic $(DEBUG)

All: sndinfo sndcat sndmix

sndcat : $(OBJSCAT)
	$(CC) $(LFLAGS) $(OBJSCAT) -o sndcat

sndinfo : $(OBJSINFO)
	$(CC) $(LFLAGS) $(OBJSINFO) -o sndinfo

sndmix : $(OBJSMIX)
	$(CC) $(LFLAGS) $(OBJSMIX) -o sndmix

sndmix.o : sndmix.h StringConversion.o
	$(CC) $(CFLAGS) sndmix.cpp

sndinfo.o : sndinfo.h
	$(CC) $(CFLAGS) sndinfo.cpp

sndcat.o : sndcat.h
	$(CC) $(CFLAGS) sndcat.cpp

ProgramObject.o : ProgramObject.h SoundFile.o
	$(CC) $(CFLAGS) ProgramObject.cpp

SoundFile.o : SoundFile.h StringConversion.o
	$(CC) $(CFLAGS) SoundFile.cpp

Cs229File.o : Cs229File.h SoundFile.o Sample.o
	$(CC) $(CFLAGS) Cs229File.cpp

WavFile.o : WavFile.h SoundFile.o
	$(CC) $(CFLAGS) WavFile.cpp

Instrument.o : Instrument.h
	$(CC) $(CFLAGS) Instrument.cpp

ABC229File.o : ABC229File.h SoundFile.o Instrument.o
	$(CC) $(CFLAGS) ABC229File.cpp

StringConversion.o : StringConversion.h
	$(CC) $(CFLAGS) StringConversion.cpp

Sample.o : Sample.h
	$(CC) $(CFLAGS) Sample.cpp

clean:
	\rm *.o -f sndifo sndcat sndmix

tar:
	tar cfv SoundInfo.tar sndinfo.h sndinfo.cpp sndcat.h sndcat.cpp sndmix.h sndmix.cpp ProgramObject.cpp ProgramObject.h SoundFile.h SoundFile.cpp Cs229File.cpp Cs229File.h ABC229File.cpp ABC229File.h WavFile.cpp WavFile.h Instrument.cpp Instrument.h StringConversion.cpp StringConversion.h Sample.h Sample.cpp

analyze.exe: analyze.o util.o
gcc analyze.o util.o -o analyze.exe

analyze.o: util.h util.c analyze.c
gcc -c analyze.c

util.o: util.h util.c structs.h
gcc -c util.c
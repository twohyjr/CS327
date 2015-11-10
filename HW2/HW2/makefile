testformat.exe: testformat.o weatherio.o utils.o exceptions.o
		gcc testformat.o utils.o  weatherio.o exceptions.o -o testformat.exe

testformat.o: weatherio.h testformat.c
	gcc -c testformat.c

weatherio.o: weatherio.h utils.h weatherio.c exceptions.h exceptions.c
		gcc -c weatherio.c

utils.o: utils.h utils.c exceptions.h	weatherio.h
		gcc -c utils.c

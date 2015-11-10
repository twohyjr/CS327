#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 5000
#define MAX_LINE_LENGTH 256

void myqsort(void **, int left, int right, int(*)(void*,void*));
int readlines(FILE *f,char** buff, int maxlines);
void writelines(FILE *f,char** buff, int nlines);

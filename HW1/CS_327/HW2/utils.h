#ifndef utils_h
#define utils_h
#include <stdio.h>
#endif

int check_all_columns(char* filename, int headerCount);

int check_duplicate_headers(char* filename);

int get_row_string(FILE* file,char **row);

int get_header_count(FILE* file, char** header);

int check_blank_row(char* filename);
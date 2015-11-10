#ifndef weatherio_h
#define weatherio_h
#define MAX_LINE_LENGTH 256
#endif

/*
 -Returns 0 if the file contains valid formatted weather data.
 -Returns the first line number where the error occured.
 -Validate the following:
 1) Not enough data in the row
 2) Invalid data format
 3) Invalid file or filename
 */
int validate_format(char* filename);

/*
 -Returns the number of data columns(header columns) in the filename
 specified in the first parameter.
 */
int header_columns(char* filename);

/*
    This function returns the number of data columns in the file, and in addition, returns the c-
    strings for those headers in an array that is passed as the second parameter. You may safely
    assume that no header string is greater than 64 characters.
*/
int read_header(char *filename, char ** headers);


/*
 This function returns a row of data in an open file and assumes that the file pointer is
 positionsed at a row passed the header file.
 PARAMETERS:
    1) FILE*  - type to open a file
    2) char** - The array of c-strings that are the headers, returned by the read_header
        function.
    3) char** - The array of pointers where each pointer points to the appropriate type
        for the item read in the column as defined by the header information.
 NOTE:
    -Need to dynamically allocate memory for this to work.
    -The single return value returns 0 if the row was read correctly.
    -Otherwise returns an integer that indicates the type of error.  I decide the error
        codes. They should be well documented and placed in the header(.h) file.
 */
int read_row( FILE * file, char **headers, void **);


#ifndef requestStructs_h
#define requestStructs_h

struct Date{
    int day;
    int month;
    int year;
    int hr;
    int min;
    int fullDateString;
    int timeString;
};

struct Range{
    int begRow;
    int endRow;
    int rowCount;
    int timeColumn;
    int dateColumn;
    int tempColumn;
    float highTemp;
    float lowTemp;
    char* header;
    int bins;
    float tempDifference;
    float tempDivider;
    float average;
};

struct Bin{
    float high;
    float low;
    int occurrences;
};



#endif /* requestStructs_h */
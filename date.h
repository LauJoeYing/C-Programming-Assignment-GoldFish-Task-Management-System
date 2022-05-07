#ifndef DATE_H
#define DATE_H 
#include <time.h>

typedef struct Dates {
    int day;
    int month;
    int year;
} Date;

Date dateValidation();
int printDateError();

#endif
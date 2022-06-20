#ifndef DATE_H
#define DATE_H 
#include <time.h>

typedef struct Dates {
    int day;
    int month;
    int year;
} Date;

int dateValidation(Date *dateTarget);
int printDateError();

#endif
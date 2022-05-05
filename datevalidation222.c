#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "date.h"

struct Dates dateValidation();
int checkIsNumber(char *target);

int main() {
    dateValidation();
};

struct Dates dateValidation() {
    while(1) {
        char dateInput[11], dateInputCopy[11];
        const char *delimiter = "/";
        int day, month, year;
        int invalidDay = 0;
        int invalidMonth = 0;
        int invalidYear = 0;
        printf("Please enter the date in (DD/MM/YYYY)\t: ");
        scanf("%s", &dateInput);
        strcpy(dateInputCopy, dateInput);
        if (strlen(dateInput) < 8 || strlen(dateInput) > 10) {
            printf("Invalid Date! Please Try Again!\n");
            continue;
        } else {
            char * token = strtok(dateInputCopy, delimiter);
            if (strlen(token) == strlen(dateInput)) {
                delimiter = "-";
                token = strtok(dateInput, delimiter);
            };
            if ((strlen(token) == 1 || strlen(token) == 2) && checkIsNumber(token) == 1) {
                day = atoi(token);
                token = strtok(NULL, delimiter);
                if ((strlen(token) == 1 || strlen(token) == 2) && checkIsNumber(token) == 1) {
                    month = atoi(token);
                    token = strtok(NULL, delimiter);
                    if (strlen(token) == 4 && checkIsNumber(token) == 1) {
                        year = atoi(token);
                        if(year >= 1900 && year <= 2022) {
                        //check month
                            if(month >= 1 && month <= 12) {
                                //check days
                                if( (day >= 1 && day <= 31) && (month >= 1 && month <= 7 && month % 2 == 1 || month >= 8 && month <= 12 && month % 2 == 0) || ((day >= 1 && day <= 30) && (month==4 || month ==6 || month == 9 || month == 11)) || ((day >= 1 && day <= 28) && (month == 2)) || (day == 29 && month == 2 && (year % 400 == 0 ||(year %4 == 0 && year %100 != 0)))) {
                                    struct Dates validatedDate = {
                                        day,
                                        month,
                                        year
                                    };
                                    return validatedDate;
                                } else {
                                    invalidDay = 1;
                                };
                            } else {
                                invalidMonth = 1;
                            };
                        } else {
                            invalidYear = 1;
                        };
                        if (invalidDay == 1 || invalidMonth == 1 || invalidYear == 1) {
                            printf("Invalid Date Input! Please Try Again!");
                            continue;
                        };
                    }; 
                };     
            }; 
        }
    };
};

int checkIsNumber(char * target)
{
    int targetLength = strlen(target), validatedLength = 0;
    for (int i = 0; i < strlen(target); i++) {
        if (isdigit(target[i]) == 1) {
            validatedLength++;
        };
    };
    if (targetLength == validatedLength) {
        return 1;
    };
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "date.h"
#include "menu.h"


//Function to Validate the User Date Input
int dateValidation(Date *dateTarget) {
    while(1) {
        char dateInput[11], dateInputCopy[11];
        const char *DELIMITER = "/";
        int day, month, year;
        fflush(stdin);
        printf("Please enter the date in (DD/MM/YYYY):\n");
        scanf("%[^\n]s", dateInput);
        strcpy(dateInputCopy, dateInput);
        if (strlen(dateInput) >= 8 && strlen(dateInput) <= 10) {
            char * token = strtok(dateInputCopy, DELIMITER);
            if (strlen(token) == strlen(dateInput)) {
                DELIMITER = "-";
                token = strtok(dateInput, DELIMITER);
            };
            if ((strlen(token) == 1 || strlen(token) == 2) && checkIsNumber(token) == 1) {
                day = atoi(token);
                token = strtok(NULL, DELIMITER);
                if ((strlen(token) == 1 || strlen(token) == 2) && checkIsNumber(token) == 1) {
                    month = atoi(token);
                    token = strtok(NULL, DELIMITER);
                    if (strlen(token) == 4 && checkIsNumber(token) == 1) {
                        year = atoi(token);
                        if(year >= 1900 && year <= 2022) {
                        //check month
                            if(month >= 1 && month <= 12) {
                                //check days
                                if( (day >= 1 && day <= 31) && (month >= 1 && month <= 7 && month % 2 == 1 || month >= 8 && month <= 12 && month % 2 == 0) || ((day >= 1 && day <= 30) && (month==4 || month ==6 || month == 9 || month == 11)) || ((day >= 1 && day <= 28) && (month == 2)) || (day == 29 && month == 2 && (year % 400 == 0 ||(year %4 == 0 && year %100 != 0)))) {
                                    dateTarget->day = day;
                                    dateTarget->month = month;
                                    dateTarget->year = year;
                                    break;
                                };
                            };
                        };
                    };
                };
            };
        };
        printf("Invalid Date Entry. Please Try Again.\n");
        continue;
    };

    return 0;
};
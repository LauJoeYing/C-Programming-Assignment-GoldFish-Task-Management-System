#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int checkIsNumber(char * target);

int dateValidation() {
    while(1) {
        char dateInput[11], dateInputCopy[11];
        const char *delimiter = "/";
        int day, month, year, invalidDay, invalidMonth, invalidYear;
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
                                    printf("Date is valid.\n");
                                    break;
                                } else {
                                    invalidDay = 1;
                                };
                            } else {
                                invalidMonth = 1;
                            };
                        } else {
                            invalidYear = 1;
                        };
                        if (invalidDay == 1) {
                            if (invalidMonth == 1) {
                                if (invalidYear == 1) {
                                    printf("Invalid day (%i), month (%i), and year (%i). Please try again.", day, month, year);
                                    continue;
                                } else {
                                    printf("Invalid day (%i) and month (%i) in year (%i). Please try again.", day, month, year);
                                    continue;
                                };
                            } else {
                                printf("Invalid day (%i) in month (%i) of year (%i). Please try again.", day, month, year);
                                continue;
                            };
                        };
                    } else {
                        printf("Invalid year format (%s). Please try again.\n", token);
                        continue;
                    };
                } else {
                    printf("Invalid month format (%s). Please try again.\n", token);       
                    continue;          
                };
            } else {
                printf("Invalid day format (%s). Please try again.\n", token);
                continue;
            };
            
        }
    };
};

int checkIsNumber(char * target) {
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
};

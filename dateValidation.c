#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int checkIsNumber(char * target);

void main() {
    while(1) {
        char dateInput[11];
        int day, month, year;
        printf("Please enter the date in (DD/MM/YYYY)\t: ");
        scanf("%s", &dateInput);
        if (strlen(dateInput) != 10) {
            printf("Invalid Date! Please Try Again!\n");
            continue;
        } else {
            char * token = strtok(dateInput, "/");
            if (strlen(token) == 2 && checkIsNumber(token) == 1) {
                day = atoi(token);
                token = strtok(NULL, "/");
                if (strlen(token) == 2 && checkIsNumber(token) == 1) {
                    month = atoi(token);
                    token = strtok(NULL, "/");
                    if (strlen(token) == 4 && checkIsNumber(token) == 1) {
                        year = atoi(token);
                        if(year >= 1900 && year <= 2022) {
                        //check month
                            if(month >= 1 && month <= 12) {
                                //check days
                                if((day >= 1 && day <= 31) && (month >= 1 && month <= 7 && month % 2 == 1 || month >= 8 && month <= 12 && month % 2 == 0)) {
                                    printf("Date is valid.\n");
                                    break;
                                } else if((day >= 1 && day <= 30) && (month==4 || month ==6 || month == 9 || month == 11)) {
                                    printf("Date is valid.\n");
                                    break;
                                } else if((day >= 1 && day <= 28) && (month == 2)){
                                    printf("Date is valid.\n");
                                    break;
                                } else if(day == 29 && month == 2 && (year % 400 == 0 ||(year %4 == 0 && year %100 != 0))){
                                    printf("Date is valid.\n");
                                    break;
                                } else{
                                    printf("Day is invalid.\n");
                                    continue;
                                }
                            } else {
                                printf("Month is not valid.\n");
                                continue;
                            }
                        } else {
                            printf("Year is not valid.\n");
                            continue;
                        }
                    } else {
                        printf("Invalid year format (%s). Please try again.\n", token);
                    }
                } else {
                    printf("Invalid month format (%s). Please try again.\n", token);                 
                }
            } else {
                printf("Invalid day format (%s). Please try again.\n", token);
                continue;
            }
            
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

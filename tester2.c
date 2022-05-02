#include <stdio.h>
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
            if (strlen(token) == 2) {
                token = strtok(NULL, "/");
                if (strlen(token) == 2) {
                    token = strtok(NULL, "/");
                    if (strlen(token) == 4) {
                        printf("Validated date!");
                    } else {
                        printf("Invalid year format (%s). Please try again", token);
                    }
                } else {
                    printf("Invalid month format (%s). Please try again", token);                 
                }
            } else {
                printf("Invalid day format (%s). Please try again", token);
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
    }
    return 0;
};

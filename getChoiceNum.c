#include<stdio.h> // define the header file 
#include<string.h>
#include<stdbool.h>  
#include<ctype.h>
#include<stdlib.h>

void user_menu();
void admin_menu();
int getChoiceNum(int maxChoice);

void main() {  
    printf("\nWelcome to the Main Menu of Goldfish Personal Task Management System!\n");
    getChoiceNum(6);
}

void user_menu() {
    printf("[ 1 ] - Add New Task\n");
    printf("[ 2 ] - Upadate or Delete Task\n");
    printf("[ 3 ] - Search and View Task\n");
    printf("[ 4 ] - Generate Productivity Report\n");
    printf("[ 5 ] - Change Password\n");
    printf("[ 6 ] - Contact Admin\n");
    printf("[ X ] - Exit\n");
} 

void admin_menu() {
    printf("[ 1 ] - Check Message From Users\n");
    printf("[ 2 ] - Recover User's Account\n");
    printf("[ 3 ] - Update Admin Details\n");
    printf("[ 4 ] - Change Password\n");
    printf("[ X ] - Exit\n");
}

int getChoiceNum(int maxChoice) {
    char userInput[256], *eptr;
    int validatedInput_length = 0, userInput_length;
    long choice;

    while (1) {
        userInput_length = validatedInput_length = 0;
        printf("\nSelect a choice\t: ");
        scanf("%s",&userInput);
        userInput_length = strlen(userInput);
        for (int i=0; i < userInput_length; i++) {
            if (isdigit(userInput[i]) == 1) {
                validatedInput_length++;
            }
        }
        if (validatedInput_length == userInput_length) {
            choice = strtol(userInput, &eptr, 10);
            if (choice > 0 && choice <= maxChoice) {
                printf("%i is in menu selection.", choice);
                return choice;
            } else if (choice == 2147483647) {
                printf("%s is not in menu selection.", userInput);
            }else {
                printf("%i is not in menu selection.", choice);
                continue;
            }
        } else {
            if (userInput_length == 1 && tolower(userInput[0]) == 'x') {
                    char userExitInput[256];
                    int userExitInput_length;
                    printf("\nConfirm exit? [X - To Confirm Exit]\n");
                    scanf("%s",&userExitInput);
                    userExitInput_length = strlen(userExitInput);
                    if (userExitInput_length == 1 && tolower(userExitInput[0]) == 'x') {
                        break;
                    } else {
                        continue;
                    };
            } else {
                printf("%s is not a validated number.", userInput);
                continue;
            };
        };
    };
};
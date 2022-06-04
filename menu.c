#include<stdio.h> // define the header file 
#include<string.h>
#include<stdbool.h>  
#include<ctype.h>
#include<stdlib.h>

void user_menu();
void admin_menu();
int getChoiceNum(int maxChoice, int minChoice);
int checkIsNumber(char * target);

// void main() {  
//     printf("\nWelcome to the Main Menu of Goldfish Personal Task Management System!\n");
//     getChoiceNum(6, 0);
// }

void user_menu() {
    printf("[ 1 ] - Add New Task\n");
    printf("[ 2 ] - Sort and View Tasks\n");
    printf("[ 3 ] - View All Tasks\n");
    printf("[ 4 ] - Update Task\n");
    printf("[ 5 ] - Delete Task\n");
    printf("[ 6 ] - Search Task\n");
    printf("[ 7 ] - Change Password\n");
    printf("[ 8 ] - Edit Personal Info\n");
    printf("[ X ] - Exit\n");
} 

void admin_menu() {
    printf("[ 1 ] - Recover User's Account\n");
    printf("[ 2 ] - Search User Tasks");
    printf("[ 3 ] - View All User Tasks");
    printf("[ 2 ] - Update Admin Details\n");
    printf("[ 3 ] - Change Admin Password\n");
    printf("[ X ] - Exit\n");
}

int getChoiceNum(int maxChoice, int minChoice) {
    char userInput[256];
    int userInput_length, choice;

    while (1) {
        printf("\nSelect a choice\t: ");
        scanf("%s",&userInput);
        if (checkIsNumber(userInput)) {
            choice = atoi(userInput);
            if (choice >= minChoice && choice <= maxChoice) {
                return choice;
            } else {
                printf("%s is not in available selection range.", userInput);
                continue;
            };
        } else {
            if (userInput_length == 1 && tolower(userInput[0]) == 'x') {
                    char userExitInput[256];
                    int userExitInput_length;
                    printf("\nConfirm exit? [X - To Confirm Exit]\n");
                    scanf("%s",&userExitInput);
                    userExitInput_length = strlen(userExitInput);
                    if (userExitInput_length == 1 && tolower(userExitInput[0]) == 'x') {
                        exit(1);
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


int toLower(char *str) {
    for(int i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
    return 0;
};
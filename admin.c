
#include <stdio.h>
#include <string.h>
#include "date.h"
#include "menu.h"
#include "task.h"
#include "account.h"
#include "menu.c"
#include "fileHandling.c"



int update_details() {
    int continueAdminChoice = 1;
    do {
        printf("\n===================================");
        printf("\n\tWelcome to Admin Page!\n");
        printf("\n===================================");
        printf("\n[ 1 ] - Recover User's Account");
        printf("\n[ 2 ] - Update Admin Details");
        printf("\n[ 3 ] - View All Tasks");
        printf("\n[ 4 ] - Change Admin Account Password");
        printf("[ 0 ] - Back to the Main Page\n");

        int adminChoice = getChoiceNum(4, 0);
        switch (adminChoice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                continueAdminChoice = 0;
                break;
        }
    } while (continueAdminChoice);

    return 0;
};


int recoverUserAcct() {
    char searchKey[21], searchSource[21], lastSixDigits[7];
    Account acct;
    char lastSixDigit[7];
    FILE *acctFileReader;
    int found = 0;

    fflush(stdin);
    printf("\nPlease Enter the Account Username that You Would Like to Recover:\t");
    scanf("%[^\n]s", searchKey);
    toLower(searchKey);

    acctFileReader = checkFileExistence("user.txt", "r", 0);
    while(fread(&acct, sizeof(Account), 1, acctFileReader)) {
        strcpy(searchSource, acct.username);
        toLower(searchSource);
        if (strcmp (searchSource, searchKey) == 0 ) {
            printf("\nRecovering %c's account...", acct.name);
            sprintf(lastSixDigit, acct.username + strlen(acct.contact_num) -6);
            char newPass[50];
            strcpy()
        };
    };
    fclose(acctFileReader);
    if (!found) {
        printf("\nNo Username Found. Please Ensure Your Entered A Correct Username.");
    };
    return 0;
};

int printNewPassword(char*username) {
    char num[] = "60126900655";
    char last6[7];
    sprintf(last6, num + strlen(num) - 6);
    char newPass[50];
    strcpy(newPass, username);
    strcat(newPass, last6);
    printf("%s\n", last6);
    printf("%s", newPass);

    return 0;
}

int main() {
    printNewPassword("angniuniu");
}


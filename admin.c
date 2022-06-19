
#include <stdio.h>
#include <string.h>
#include "date.h"
#include "menu.h"
#include "task.h"
#include "account.h"
#include "menu.c"
#include "login.c"
#include "fileHandling.c"
#include "taskManagement.c"

int admPage(char * username);
int recoverUserAcct();
int updateAdmDetail(char*username);
int displayAdmDetail(Account* acct);



int main() {
    int admPage(char * username);
};


int admPage(char * username) {
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
                recoverUserAcct();
                break;
            case 2:
                updateAdmDetail("weoyyang00");
                break;
            case 3:
                readAllTask();
                break;
            case 4:
                changePassword();
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
    FILE *acctFileReader, *acctFileWriter;
    int found = 0;

    fflush(stdin);
    printf("\nPlease Enter the Account Username that You Would Like to Recover:\t");
    scanf("%[^\n]s", searchKey);
    toLower(searchKey);

    acctFileReader = checkFileExistence("usertry.txt", "r", 0);
    acctFileWriter = fopen("temp_user_try.txt", "w");
    while(fread(&acct, sizeof(Account), 1, acctFileReader)) {
        strcpy(searchSource, acct.username);
        toLower(searchSource);
        if (strcmp (searchSource, searchKey) == 0 ) {
            found ++;
            printf("\nRecovering %c's account...", acct.name);
            sprintf(lastSixDigits, acct.contactNum + strlen(acct.contactNum) -6);
            char newPass[50];
            strcpy(newPass, acct.username);
            strcat(newPass, lastSixDigits);

            printf("Congratulations! The Account Has Been Recovered!\n");
            printf("The New Password of %s is %s", acct.username, newPass);
        };
        fwrite(&acct, sizeof(Account), 1, acctFileWriter);
    };
    fclose(acctFileReader);
    fclose(acctFileWriter);
    printf("\nDone!\n");
    remove("usertry.txt");
    rename("temp_user_try.txt", "usertry.txt");
    if (!found) {
        printf("\nNo Username Found. Please Ensure Your Entered A Correct Username.");
    };
    return 0;
};


int updateAdmDetail(char*username) {
    Account acct;
    FILE *acctFileReader, *acctFileWriter;
    acctFileReader = checkFileExistence("usertry.txt", "r", 0);
    acctFileWriter = fopen("temp_usertry.txt", "w");
    while (fread(&acct, sizeof(Account), 1, acctFileReader)) {
        displayAdmDetail(&acct);

    };
    fwrite (&acct, sizeof(Account), 1, acctFileWriter);
    fclose(acctFileReader);
    fclose(acctFileWriter);
    printf("\nDone!\n");
    remove("usertry.txt");
    rename("temp_usertry.txt", "usertry.txt");
    
    return 0;
}


int displayAdmDetail(Account* acct) {
    printf("\n[ 1 ]- Username\t\t: %s", acct -> username);
    printf("\n[ 2 ]- Admin Name\t\t: %s", acct -> name);
    printf("\n[ 3 ]- Contact Number\t\t: %s", acct -> contactNum);
    printf("\n[ 4 ]- Date of Birth\t\t: %s", acct -> dateOfBirth);
    printf("\n[ 5 ]- Email Address\t\t: %s", acct -> email);
    fflush(stdin);
    int editChoice = getChoiceNum(5, 1);
    switch (editChoice) {
        case 1:
            register_username(acct->username);
            break;
        case 2:
            register_name(acct->name);
            break;
        case 3:
            register_contactNum(acct->contactNum);
            break;
        case 4:
            register_dateOfBirth(acct->dateOfBirth);
            break;
        case 5:
            register_email(acct->email);
            break;

    }
    
    return 0;
};





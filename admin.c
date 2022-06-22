#include "admin.h"

//Function of Admin Main Page
int adminPage(char *adminUsername, char *adminPassword) {
    int continueAdminChoice = 1;

    do {
        printf("\n===================================");
        printf("\n\tWelcome to Admin Page!\n");
        printf("\n===================================");
        admin_menu();

        int adminChoice = getChoiceNum(3, 0);
        switch (adminChoice) {
            case 1:
                recoverUserAcct();
                break;
            case 2:
                updateUserDetail(adminUsername);
                break;
            case 3:
                changePassword(adminUsername, adminPassword);
                break;
            case 0:
                continueAdminChoice = 0;
                break;
        }
    } while (continueAdminChoice);

    return 0;
};


//Function to Recover User Account In the Case of Forgot Password
//Autogenerate New Default Password for the Users
//Format of New Password: Username + Last Six Characters of the Contact Number
int recoverUserAcct() {
    char searchKey[21], searchSource[21], lastSixDigits[7];
    Account user;
    FILE *userFileReader, *userFileWriter;
    int found = 0;

    fflush(stdin);
    printf("\nPlease Enter the Account Username that You Would Like to Recover:\t");
    scanf("%[^\n]s", searchKey);
    toLower(searchKey);

    userFileReader = checkFileExistence("user.txt", "r", 0);
    userFileWriter = fopen("temp_user.txt", "w");
    while(fread(&user, sizeof(Account), 1, userFileReader)) {
        strcpy(searchSource, user.username);
        toLower(searchSource);
        if (strcmp (searchSource, searchKey) == 0 ) {
            found = 1;
            printf("\nRecovering %s's account...", user.name);
            sprintf(lastSixDigits, user.contactNum + strlen(user.contactNum) -6);
            char newPass[50];
            strcpy(newPass, user.username);
            strcat(newPass, lastSixDigits);
            strcpy(user.password, newPass);
            printf("Congratulations! The Account Has Been Recovered!\n");
            printf("The New Password of %s has been set to \"[Username][Last 6 Digits Of Contact Number]\"", user.username);
        };
        fwrite(&user, sizeof(Account), 1, userFileWriter);
    };
    fclose(userFileReader);
    fclose(userFileWriter);
    printf("\nDone!\n");
    remove("user.txt");
    rename("temp_user.txt", "user.txt");
    if (!found) {
        printf("\nNo Username Found. Please Ensure Your Entered A Correct Username.");
    };
    return 0;
};





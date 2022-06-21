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
                updateAdmDetail(adminUsername);
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
    Account acct;
    FILE *userFileReader, *userFileWriter;
    int found = 0;

    fflush(stdin);
    printf("\nPlease Enter the Account Username that You Would Like to Recover:\t");
    scanf("%[^\n]s", searchKey);
    toLower(searchKey);

    userFileReader = checkFileExistence("user.txt", "r", 0);
    userFileWriter = fopen("temp_user.txt", "w");
    while(fread(&acct, sizeof(Account), 1, userFileReader)) {
        strcpy(searchSource, acct.username);
        toLower(searchSource);
        if (strcmp (searchSource, searchKey) == 0 ) {
            found = 1;
            printf("\nRecovering %s's account...", acct.name);
            sprintf(lastSixDigits, acct.contactNum + strlen(acct.contactNum) -6);
            char newPass[50];
            strcpy(newPass, acct.username);
            strcat(newPass, lastSixDigits);

            printf("Congratulations! The Account Has Been Recovered!\n");
            printf("The New Password of %s is %s", acct.username, newPass);
        };
        fwrite(&acct, sizeof(Account), 1, userFileWriter);
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


//Function to Update Admin Details
int updateAdmDetail(char *username) {
    Account acct;
    FILE *userFileReader, *userFileWriter;
    userFileReader = checkFileExistence("user.txt", "r", 0);
    userFileWriter = fopen("temp_user.txt", "w");
    while (fread(&acct, sizeof(Account), 1, userFileReader)) {
        displayAdmDetail(acct);

    };
    fwrite (&acct, sizeof(Account), 1, userFileWriter);
    fclose(userFileReader);
    fclose(userFileWriter);
    printf("\nDone!\n");
    remove("user.txt");
    rename("temp_user.txt", "user.txt");
    
    return 0;
};



//Function to Display Admin's Current Details
int displayAdmDetail(Account acct) {
    printf("\n[ 1 ]- Username\t\t: %s", acct.username);
    printf("\n[ 2 ]- Admin Name\t\t: %s", acct.name);
    printf("\n[ 3 ]- Contact Number\t\t: %s", acct.contactNum);
    printf("\n[ 4 ]- Date of Birth\t\t: %02d/%02d-%04d", acct.dateOfBirth.day, acct.dateOfBirth.month, acct.dateOfBirth.year);
    printf("\n[ 5 ]- Email Address\t\t: %s", acct.email);
    fflush(stdin);
    int editChoice = getChoiceNum(5, 1);
    switch (editChoice) {
        case 1:
            register_username(acct.username);
            break;
        case 2:
            register_name(acct.name);
            break;
        case 3:
            register_contactNum(acct.contactNum);
            break;
        case 4:
            register_dateOfBirth(&acct.dateOfBirth);
            break;
        case 5:
            register_email(acct.email);
            break;

    }
    
    return 0;
};



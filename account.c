#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "account.h"
#include "fileHandling.c"
#include "menu.c"

Account loginUser();
int registerUser(Account user);
int getUserData();
int changePassword(char * username, char * password);

int main() {
    Account user = loginUser();
    // registerUser(user);
    getUserData();
    changePassword(user.username, user.password);
    return 0;
}

int registerUser(Account user) {
    char *userTypeDisplay = user.userType == 'a' ? "Admin" : "User";
    FILE *fileAppender;
    fileAppender = checkFileExistence("usertry.txt", "a", 1);
    fwrite(&user, sizeof(Account), 1, fileAppender);
    if (fwrite != 0) {
        printf("%s has been registered successfully !\n", userTypeDisplay);
    } else {
        printf("Error registering %s!\n", userTypeDisplay);
    };

    return 0;
};

Account loginUser() {
    int found = 0;

    do {
        char username[256], password[256];
        Account user;
        FILE *taskFileReader = checkFileExistence("usertry.txt", "r", 0);    
        fflush(stdin);
        printf("\nUsername : ");
        scanf("%[^\n]s", username);
        toLower(username);

        fflush(stdin);
        printf("\nPassword : ");
        scanf("%[^\n]s", password);

        while(fread(&user, sizeof(Account), 1, taskFileReader)) {
            toLower(user.username);
            if ((strcmp(user.username, username) == 0) && (strcmp(user.password, password) == 0)) {
                printf("\nWelcome back, %s!", user.name); 
                fclose(taskFileReader);
                found++;
                return user;
            };
        };
        if (!found) {
            printf("\nNo user account found. Please try again :)\n");
        };
    } while (!found);
    
};

int getUserData() {
    Account user;
    FILE *fileReader = checkFileExistence("usertry.txt", "r", 0);
    while(fread(&user, sizeof(Account), 1, fileReader)) {
        printf ("username = %s password = %s\n", user.username, user.password);
    }
   fclose(fileReader);

   return 0;
};

int changePassword(char * username, char * password) {
    Account user;
    char confirmPassword[256], newPassword[21];
    FILE *taskFileReader, *taskFileWriter;
    taskFileReader = checkFileExistence("usertry.txt", "r", 0); 
    taskFileWriter = fopen("temp_usertry.txt", "w");
    int passwordCorrect, found = 0;
    
    do {
        fflush(stdin);
        printf("\nEnter old password to continue : ");
        scanf("%[^\n]s", confirmPassword);
        if (strcmp(confirmPassword, password) == 0) {
            passwordCorrect ++;
            break;
        } else {
            printf("\nIncorrect Password! Please Try Again!");
        };
    } while (!passwordCorrect);
    

    fflush(stdin);
    printf("\nEnter new password to change : ");
    scanf("%[^\n]s", newPassword);

    while(fread(&user, sizeof(Account), 1, taskFileReader)) {
        if (strcmp(user.username, username) == 0) {
            strcpy(user.password, newPassword); 
        };
        fwrite(&user, sizeof(Account), 1, taskFileWriter);
    };
    fclose(taskFileReader);
    fclose(taskFileWriter);
    printf("\nDone!\n");
    remove("usertry.txt");
    rename("temp_usertry.txt", "usertry.txt");
    
    return 0;
};

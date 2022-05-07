#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "account.h"

int loginUser(Account user, char *userType);
int registerUser(Account user, char userType);
int getUserData();
FILE *checkFileExistence(char *fileName, char *fileHandling_method);

int main() {
    Account user = {
        "joeeeyyy",
        "Lj071209y",
        "Lau Joe Ying",
        "+60 18 362 6989",
        "12/07/2022",
        "joeying0712@gmail.com"
    };
    getUserData();
    return 0;
}

int registerUser(Account user, char userType) {
    char *userTypeDisplay = userType == 'a' ? "Admin" : "User";
    char *fileName = userType == 'a' ? "admintry.txt" : "usertry.txt";
    FILE *fileAppender;
    fileAppender = checkFileExistence(fileName, "a");
    fwrite(&user, sizeof(Account), 1, fileAppender);
    if (fwrite != 0) {
        printf("%s has been registered successfully !\n", userTypeDisplay);
    } else {
        printf("Error registering %s!\n", userTypeDisplay);
    };
    if (userType == 'u') {
        FILE *taskFileAppender;
        taskFileAppender = checkFileExistence("taskTry.txt", "a");

    };
    fclose(fileAppender);
    return 0;
};

int getUserData() {
    Account user;
    FILE *fileReader = checkFileExistence("usertry.txt", "r");
    while(fread(&user, sizeof(Account), 1, fileReader)) {
        printf ("username = %s password = %s\n", user.username, user.password);
    }
   fclose(fileReader);
   return 0;
};



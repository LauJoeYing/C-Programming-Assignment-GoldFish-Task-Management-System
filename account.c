#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "account.h"
#include "fileHandling.c"

int loginUser(Account user, char userType);
int registerUser(Account user, char userType);
int getUserData(char userType);

int main() {
    Account user = {
        "niuniu",
        "Lj071209y",
        "Ang Niu Niu",
        "+60 12 690 0655",
        "25/12/2019",
        "angniuniu@gmail.com"
    };
    // registerUser(user, 'u');
    getUserData('u');
    return 0;
}

int registerUser(Account user, char userType) {
    char *userTypeDisplay = userType == 'a' ? "Admin" : "User";
    char *fileName = userType == 'a' ? "admintry.txt" : "usertry.txt";
    FILE *fileAppender;
    fileAppender = checkFileExistence(fileName, "a", 1);
    fwrite(&user, sizeof(Account), 1, fileAppender);
    if (fwrite != 0) {
        printf("%s has been registered successfully !\n", userTypeDisplay);
    } else {
        printf("Error registering %s!\n", userTypeDisplay);
    };

    return 0;
};

int loginUser(Account user, char userType) {

    return 0;
};

int getUserData(char userType) {
    Account user;
    FILE *fileReader = checkFileExistence("usertry.txt", "r", 0);
    while(fread(&user, sizeof(Account), 1, fileReader)) {
        printf ("username = %s password = %s\n", user.username, user.password);
    }
   fclose(fileReader);

   return 0;
};



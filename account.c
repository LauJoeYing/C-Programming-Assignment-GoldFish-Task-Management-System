#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Account {
    char username[21];
    char password[51];
    char name[256];
    char contact_num[21];
    char date_of_birth[11];
    char email[321];
};

struct Task {
    char username[21];
    char status
};

int loginUser(struct Account user, char *userType);
int registerUser(struct Account user, char userType);
int getUserData();
FILE *checkFileExistence(char *fileName, char *fileHandling_method);

int main() {
    struct Account user = {
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

int registerUser(struct Account user, char userType) {
    char *userTypeDisplay = userType == 'a' ? "Admin" : "User";
    char *fileName = userType == 'a' ? "admintry.txt" : "usertry.txt";
    FILE *fileAppender = checkFileExistence(fileName, "a");
    fwrite(&user, sizeof(struct Account), 1, fileAppender);
    if (fwrite != 0) {
        printf("%s has been registered successfully !\n", userTypeDisplay);
    } else {
        printf("Error registering %s!\n", userTypeDisplay);
    };
    fclose(fileAppender);
    return 0;
};

int getUserData() {
    struct Account user;
    FILE *fileReader = checkFileExistence("usertry.txt", "r");
    while(fread(&user, sizeof(struct Account), 1, fileReader)) {
        printf ("username = %s password = %s\n", user.username, user.password);
    }
   fclose(fileReader);
   return 0;
};

//To Check Whether the Target File is in Correct Directory
FILE *checkFileExistence(char *fileName, char *fileHandling_method) {
    while (1) {
        FILE *filePointer;
        filePointer = fopen(fileName, fileHandling_method);
        if (filePointer == NULL) {
            char choice[256];
            printf("\nTarget file does not exist. Enter any key to continue after relocating the file.\n");
            printf("[X] - To Exit\n\n");
            fgets(choice, 256, stdin);
            if (strlen(choice) == 2 && tolower(choice[0]) == 'x') {
                exit(0);
                break;
            } else {
                continue;
            };
        } else {
            return filePointer;
        };
    };
};

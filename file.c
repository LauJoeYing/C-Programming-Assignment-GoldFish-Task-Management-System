#include "file.h"


//File Handling Function to Check the Existence of the File
FILE *checkFileExistence(char *fileName, char *fileHandling_method, int createFileIfNotExist) {
    while (1) {
        FILE *filePointer;
        filePointer = fopen(fileName, fileHandling_method);
        if (filePointer == NULL) {
            if (createFileIfNotExist) {
                FILE *filePointer1 = fopen(fileName, "w");
                fclose(filePointer1);
                continue;
            };
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

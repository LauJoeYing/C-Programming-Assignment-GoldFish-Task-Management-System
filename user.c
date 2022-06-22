#include "user.h"

//Function of User Main Page
int userPage(char *userUsername, char *userPassword) {
    int continueUserChoice = 1;

    do {
        printf("\n===================================");
        printf("\n\tWelcome to User Page!\n");
        printf("\n===================================");
        user_menu();

        int userChoice = getChoiceNum(8, 0);
        switch (userChoice) {
            case 1:
                addTask(userUsername);
                break;
            case 2:
                sortTask(userUsername);
                break;
            case 3:
                readTask(userUsername);
                break;
            case 4:
                readTask(userUsername);
                updateTask(userUsername);
                break;
            case 5:
                deleteTask(userUsername);
                break;
            case 6:
                searchTask(userUsername);
                break;
            case 7:
                updateUserDetail(userUsername);
                break;
            case 8:
                changePassword(userUsername, userPassword);
                break;
            case 0:
                continueUserChoice = 0;
                break;
        }
    } while (continueUserChoice);

    return 0;
};
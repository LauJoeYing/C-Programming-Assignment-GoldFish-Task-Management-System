//Lau_Joe_Ying
//TP066760
//Personal_task_management_system:Goldfish

#include <stdio.h>
#include "account.h"
#include "menu.h"
#include "file.h"
#include "userDataInjection.h"
#include "user.h"
#include "admin.h"

Account welcomePage();

int main() {

    while (1) {
        FILE *filePointer;
        filePointer = fopen("user.txt", "r");
        if (filePointer == NULL) {
            userDataInjection();
        }
        fclose(filePointer);

        Account currentUser = welcomePage();
        switch (currentUser.userType) {
            case 'u':
                userPage(currentUser.username, currentUser.password);
                break;
            case 'a':
                adminPage(currentUser.username, currentUser.password);
                break;
        }
    };

    return 0;
}



//The Welcome Page for Both Users and Admin
//They Can Select Either Want to login or Register
Account welcomePage()
{
    int option;

    do {
        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
        printf("\n\n\tWelcome to Goldfish Task Management System!\n\n");
        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
        printf("\n[ 1 ] - Login");
        printf("\n[ 2 ] - Register");
        printf("\n[ 0 ] - Exit\n\n");
    
        option = getChoiceNum(2, 0);
        Account userOne;

        switch (option) {
            case 1:
                userOne = loginUser();
                return userOne;
                break;

            case 2:
                registration();
                break;

            case 0:
                exit(0);
                break;
        }   
    } while (option == 2);
};
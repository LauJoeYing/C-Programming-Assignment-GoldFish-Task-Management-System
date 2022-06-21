//Lau_Joe_Ying
//TP066760
//Personal_task_management_system:Goldfish

#include <stdio.h>
#include "account.h"
#include "menu.h"
#include "file.h"
#include "userDataInjection.h"

Account welcomePage();

int main() {

    FILE *filePointer;
    filePointer = fopen("user.txt", "r");
    if (filePointer == NULL) {
        userDataInjection();
    }
    fclose(filePointer);

    Account currentUser = welcomePage();
    switch (currentUser.userType) {
        case 'u':
            user_menu();
            break;
        case 'a':
            admin_menu();
            break;
    }

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
        printf("\n[ 2 ] - Register\n\n");
        
        printf("Please Enter Your Choice Number:\t\n");
        option = getChoiceNum(2, 1);
        Account userOne;

        switch (option) {
            case 1:
                userOne = loginUser();
                return userOne;
                break;

            case 2:
                registration();
                break;
        }   
    } while (option == 2);
};
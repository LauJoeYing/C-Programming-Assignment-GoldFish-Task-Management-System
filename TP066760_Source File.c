//Lau_Joe_Ying
//TP066760
//Personal_task_management_system:Goldfish

#include <stdio.h>

int user_menu(){
    printf("Welcome to the Main Menu of Goldfish Personal Task Management System!");
    printf("[ 1 ] - Add New Task");
    printf("[ 2 ] - Upadate or Delete Task");
    printf("[ 3 ] - Search and View Task");
    printf("[ 4 ] - Generate Productivity Report");
    printf("[ 5 ] - Change Password");
    printf("[ 6 ] - Contact Admin");
    printf("[ X ] - Exit");
}

int admin_menu(){
    printf("Welcome to the Main Menu of Goldfish Personal Task Management System!");
    printf("[ 1 ] - Check Message From Users");
    printf("[ 2 ] - Recover User's Account");
    printf("[ 3 ] - Update Admin Details");
    printf("[ 4 ] - Change Password");
    printf("[ X ] - Exit");
}

int choice_num(choice){
    printf("Please select your choice\t:");
    scanf('%i', choice);
    return choice;
}


int process_num(maxchoice){
    int true,choice;
    while(true){
        choice_num();
        if (choice=='x' || choice=='X'){
            printf("\nConfirm Exit?");
            printf("[X] - Confirm Exit");
            printf("[Any Key] - Continue");
            choice_num();
            if (choice=='X' || choice=='x'){
                exit();
            } else {
                continue;
            }

        } else {
            const char error_message=printf("Out of Menu Selection! Please Try Again!");
            if (choice<= maxchoice && choice> 0) {
                    return choice;
                } else {
                    printf(error_message);
                    continue;
                }
            }

        }
    }
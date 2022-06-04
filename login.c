
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "date.h"
#include "dateValidation.c"

int login ();
int register_username();
int register_password();
int register_name();
int register_contactNum();
int register_dateOfBirth();
int register_email();
Account registration();

// int main (void)
// {
//     int option;
//     printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
//     printf("\n\n\tWelcome to Goldfish Task Management System!\n\n");
//     printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
//     printf("\n[ 1 ] - Register\n[ 2 ] - Login\n\n");
    
//     printf("Please Enter Your Choice Number:\t");
//     scanf("%d",&option);

//     switch (option){
//         case 1:
//             registration();

//         case 2:
//             login();
//     }         
// }

int login ()
{
    char username[21], password[20];
    FILE *filePointer;

    filePointer = fopen("user.txt","r");
    if (filePointer == NULL) {
        perror("Error at opening File!");
        exit(1);
    } else{
        Account user;
        printf("\nPlease Enter Your Login Credentials Below:\n\n");
        printf("Username:\t");
        // scanf and fgets 
        scanf("%s", username);
        fgets(username, 21, filePointer);
        printf("\nPassword:\t");
        scanf("%s", password);
        fgets(password, 20, filePointer);
        while(fread(&user, sizeof(Account), 1, filePointer)) {
            if(!(strcmp(username, user.username)) && !(strcmp(password, user.password))) {   
                printf("\nSuccessful Login\n, Welcome %s", user.username);
            } else {
                printf("\nIncorrect Login Details\nPlease enter the correct credentials!\n");
                continue;
            }
        }
        fclose(filePointer);
        return 0;
    }
}




Account registration()
{
    printf("\n\n\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\n\n\t\tWelcome to New User Registration Page!\n\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

    Account user;
    
    register_username(user.username);
    register_password(user.password);
    register_name(user.name);
    register_contactNum(user.contact_num);
    register_dateOfBirth(user.dateOfBirth);
    register_email(user.email);
    user.userType = 'u';

    printf("\n--------------------------------------------------------------------------\n");
    printf("\nConfirming details...");
    printf("\n\nWelcome, %s : D !\n\n",user.name);
    FILE * fileWriter = checkFileExistence("user.txt","w",0);
    fwrite(&user, sizeof(Account), 1, fileWriter);
    fclose(fileWriter);
    printf("\nRegistration Successful!\n");
    login();
}

int register_username(char * usernameTarget)
{
    char username[21];
    printf("--------------------------------------------------------------------------");
    fflush(stdin);
    printf("\nPlease Enter Your New Username:\n");
    scanf("%[^\n]s", username);
    strcpy(usernameTarget, username);

    return 0;
}

int register_password(char * passwordTarget)
{
    char password[21];
    char confirmPassword[21];
    printf("--------------------------------------------------------------------------");
    while (1){
        fflush(stdin);
        printf("\nPlease Enter Your New Password (8-20 characters):\n");
        scanf("%[^\n]s", password);
        if (strlen(password) < 8 || strlen(password) > 20){
            printf("\nInvalid Password! Please Ensure Your New Password have 8-20 Characters");
            continue;
        }
        fflush(stdin);
        printf("\nPlease Enter Your New Password Again:\n");
        scanf("%[^\n]s", confirmPassword); 

        if(strcmp(confirmPassword, password)) {
            printf("\nInvalid Input! Please Ensure That You Have Entered the Same Password!");
            continue;
        }   
        
        printf("\nCorrect Password Format!\nCongrats! Your New Password has been Verified!");
        strcpy(passwordTarget, password);

        return 0;            
    }
}


int register_name(char * nameTarget)
{
    char name[256];
    printf("\n--------------------------------------------------------------------------");
    fflush(stdin);
    printf("\nPlease Enter Your Name:\n");
    scanf("%[^\n]s", name);
    strcpy(nameTarget, name);

    return 0;
}

int register_contactNum(char * contactNumTarget)
{
    char contactNum[11];
    printf("\n--------------------------------------------------------------------------");
    while(1) {
        fflush(stdin);
        printf("\nPlease Enter Your Contact Number (without'-'): \n60");
        scanf("%[^\n]s", contactNum);
        if(checkIsNumber(contactNum)) {
            if (contactNum[1] != '1' && strlen(contactNum) < 9 || contactNum[1] == '1' && strlen(contactNum) > 10){
                printf("\nInvalid Phone Number! Please Ensure Your Registered Phone Number have correct length!");
                continue;
            }
            printf("\nCorrect Phone Number Format!\nCongrats! Your Phone Number has been Verified!");
            strcpy(contactNumTarget, contactNum);
            break;
        } else {
            printf("\nInvalid Phone Number! Please Ensure Your Registered Phone Number contains only number!");
            continue;
        }   
    }

    return 0;
}

int register_dateOfBirth(Date dateOfBirthTarget)
{
    printf("\n--------------------------------------------------------------------------");
    printf("\n\nDate of Birth\n");
    Date dateOfBirth = dateValidation();
    printf("Congrats! Your Date of Birth has been Verified!");
    dateOfBirthTarget = dateOfBirth;
    return 0;
}

int register_email(char * emailTarget)
{
    char email[321];
    printf("\n--------------------------------------------------------------------------");
    while(1) {
        printf("\n\nPlease Enter Your Email:\n");
        fflush(stdin);
        scanf("%[^\n]s", email);
        if(strstr(email, "@") && strstr(email, ".com")) {   //To Check the Occurrence of '@' and '.com'
            printf("Congrats! Your Email has been Verified!");
            strcpy(emailTarget, email);
            break;
        }   
        printf("Wrong Email Format! Please Try Again!");
        continue;
    }

    return 0;
}
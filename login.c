
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "date.h"
#include "dateValidation.c"
#include "menu.c"
#include "fileHandling.c"


int userlogin();

struct User_data {
    char username[21];
    char password[20];
    char name[256];
    char contact_num[21];
    Date date_of_birth;
    char email[321];
}user;


int login ();
int registration ();

int main (void)
{
    int option;
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\n\n\tWelcome to Goldfish Task Management System!\n\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\n[ 1 ] - Register\n[ 2 ] - Login\n\n");
    
    printf("Please Enter Your Choice Number: ");
    scanf("%d",&option);

    switch (option){
        case 1:
            system("CLS");
            registration();

        case 2:
            system("CLS");
            login();
    }         
}

int login ()
{
    char username[21],password[20];
    FILE *filePointer;

    filePointer = fopen("user.txt","r");
    if (filePointer == NULL)
    {
        perror("Error at opening File!");
        exit(1);
    } else{
    struct User_data user;

    printf("\nPlease Enter Your Login Credentials Below:\n\n");
    printf("Username:\t");
    // scanf and fgets 
    scanf("%s",username);
    fgets(username, 21, filePointer);
    printf("\nPassword:\t");
    scanf("%s",password);
    fgets(password, 20, filePointer);

    while(fread(&user,sizeof(user),1,filePointer))
        {
        if(strcmp(username,user.username)==0 && strcmp(password,user.password)==0)

            {   
                printf("\nSuccessful Login\n, Welcome %s",user.username);
            }
        else 
            {
                printf("\nIncorrect Login Details\nPlease enter the correct credentials!\n");
                continue;
            }
        }

    fclose(filePointer);
    return 0;
    }
}




int registration()
{
    char firstname[15];
    char user_password[21];
    struct User_data user;

    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\n\n\t\tWelcome to New User Registration Page!\n\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\n--------------------------------------------------------------------------");
    fflush(stdin);
    printf("\nPlease Enter Your Name:\n");
    scanf("%[^\n]s",user.name);
    
    printf("--------------------------------------------------------------------------");
    fflush(stdin);
    printf("\nPlease Enter Your New Username:\n");
    scanf("%[^\n]s",user.username);
    
    printf("--------------------------------------------------------------------------");
    while (1){
        fflush(stdin);
        printf("\nPlease Enter Your New Password (8-20 characters):\n");
        scanf("%[^\n]s",user.password);
        if (strlen(user.password)<8 || strlen(user.password)>20){
            printf("\nInvalid Password! Please Ensure Your New Password have 8-20 Characters");
            continue;}
        fflush(stdin);
        printf("\nPlease Enter Your New Password Again:\n");
        scanf("%[^\n]s",user_password); 

        if (strcmp(user.password, user_password) != 0){
            printf("\nInvalid Input! Please Ensure That You Have Entered the Same Password!");
            continue;
        }   
        
        printf("\nCorrect Password Format!\nCongrats! Your New Password has been Verified!");
        break;    
    }
    

    printf("\n--------------------------------------------------------------------------");
    while (1){
        fflush(stdin);
        printf("\nPlease Enter Your Contact Number (without'-'):");
        scanf("%[^\n]s",user.contact_num);
        if (checkIsNumber(user.contact_num)){
            if (strlen(user.contact_num)<10 || strlen(user.contact_num)>11){
                printf("\nInvalid Phone Number! Please Ensure Your Registered Phone Number have 10 or 11 digits!");
                continue;
            }   printf("\nCorrect Phone Number Format!\nCongrats!Your Phone Number has been Verified!");
                break;
        }   
    }

    printf("\n--------------------------------------------------------------------------");
    printf("\n\nDate of Birth-");
    user.date_of_birth = dateValidation();
    printf("Congrats! Your Date of Birth has been Verified!");

    printf("\n--------------------------------------------------------------------------");
    while (1){
        printf("\n\nPlease Enter Your Email:\n");
        fflush(stdin);
        scanf("%[^\n]s",user.email);
        if (strstr(user.email,"@") && strstr(user.email,".com")){   //To Check the Occurance of '@' and '.com'
            printf("Congrats! Your Email has been Verified!");
            break;
        }   
        printf("Wrong Email Format! Please Try Again!");
        continue;
    }

    printf("\n--------------------------------------------------------------------------\n");
    printf("\nConfirming details...");
    printf("\n\nWelcome, %s : D !\n\n",user.name);
    FILE * fileWriter = checkFileExistence("user.txt","w",0);
    fwrite(&user, sizeof(struct User_data), 1, fileWriter);
    fclose(fileWriter);
    printf("\nRegistration Successful!\n");
    login();
 
}

// int verify_password()
// int verify_email()
// int verify_
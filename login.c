
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int userlogin();

struct User_data {
    char username[21];
    char password[20];
    char name[256];
    char contact_num[21];
    char date_of_birth[11];
    char email[321];
}user;


int login ();
int registration ();

int main (void)
{
    int option;
    printf("Welcome to Goldfish Task Management System : )");
    printf("\n[ 1 ] - Register\n[ 2 ] - Login\n\n");
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

    printf("\nPlease Enter your login credentials below\n\n");
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
                printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
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
    FILE *filePointer;

    filePointer=fopen("user.txt","w");
    if (filePointer == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }


    struct User_data user;

    printf("\nWelcome to Goldfish Task Management System. \n\n");
    printf("\nEnter Your Name:\n");
    scanf("%s",user.name);
    
    printf("\nEnter Username:\n");
    scanf("%s",user.username);
    while (1){
    printf("\nEnter Password (8-20 characters): \n");
    scanf("%s",user.password);
    if (strlen(user.password)<=8 || strlen(user.password>=20)){
        printf("Invalid Password! Please Ensure Your New Password have 8-20 Characters");
    }
    }


    fwrite(&user,sizeof(user),1,filePointer);
    fclose(filePointer);

    printf("\nConfirming details...\n...\nWelcome, %s!\n\n",user.name);
    printf("\nRegistration Successful!\n");
    printf("Press any key to continue...");
        getchar();
    system("CLS");
    login();
}


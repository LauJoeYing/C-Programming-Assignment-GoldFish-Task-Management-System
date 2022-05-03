#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1000

void readFile(FILE * fPtr);

void main(){
    FILE *user_fPtr;

    char username[50];
    printf("Please Enter Your Account Username:\t");
    scanf("%s",&username);
    char user_password[] = "niuniu071209";
    char user_name[] = "Ang Niu Niu";
    char user_contact_num[] = "+60 12 690 0655";
    char user_date_of_birth[] = "25/12/2019";
    char user_email[] = "angniuniu@gmail.com";
    char userData[1000] = "";

    strcat(userData, username);
    strcat(userData, " | ");
    strcat(userData, user_password);
    strcat(userData, " | ");
    strcat(userData, user_name);
    strcat(userData, " | ");
    strcat(userData, user_contact_num);
    strcat(userData, " | ");
    strcat(userData, user_date_of_birth);
    strcat(userData, " | ");
    strcat(userData, user_email);
    
    user_fPtr = fopen("users.txt", "a");
    
    // /* Input data to append from user */
    // printf("\nEnter data to append: ");
    // fflush(stdin);          // To clear extra white space characters in stdin
    // fgets(dataToAppend, BUFFER_SIZE, stdin);

    /* Append data to file */
    fprintf(user_fPtr, "\n%s", userData); 

    /* Reopen file in read mode to print file contents */
    user_fPtr = freopen("users.txt", "r", user_fPtr);

    /* Print file contents after appending string */
    printf("\nSuccessfully appended data to file. \n");
    printf("Changed file contents:\n\n");         
    readFile(user_fPtr);

    /* Done with file, hence close file. */
    fclose(user_fPtr);
};


//EOF= End of File
void readFile(FILE * f_user)
{
    char ch;
    do 
    {
        ch = fgetc(f_user);

        putchar(ch);

    } while (ch != EOF);
};
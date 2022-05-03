#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 1000

//EOF= End of File
void readFile(FILE * f_user)
{
    char ch;
    do 
    {
        ch = fgetc(f_user);

        putchar(ch);

    } while (ch != EOF);
}


char main(){
    char username,user_password,user_name,user_contact_num,user_email;
    char user_details[6];
    char dataToAppend[BUFFER_SIZE];
    FILE*f_user;
    user_details[1] = username;
    user_details[2] = user_password;
    user_details[3] = user_name;
    user_details[5] = user_contact_num;
    user_details[6] = user_email;

    f_user = fopen("users.txt", "r");
    
    /* Input data to append from user */
    printf("\nEnter data to append: ");
    fflush(stdin);          // To clear extra white space characters in stdin
    fgets(dataToAppend, BUFFER_SIZE, stdin);

    /* Append data to file */
    fputs(dataToAppend, f_user);

    /* Reopen file in read mode to print file contents */
    f_user = freopen(user_details, "r", f_user);

    /* Print file contents after appending string */
    printf("\nSuccessfully appended data to file. \n");
    printf("Changed file contents:\n\n");
    readFile(f_user);

    /* Done with file, hence close file. */
    fclose(f_user);

    return 0;
}
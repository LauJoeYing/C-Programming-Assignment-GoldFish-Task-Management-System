#include <string.h>
#include <time.h>
#include <stdio.h>


//To Print Current Date & Time
void date(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

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








void add_file(){
  char str[256];
  FILE*pUser;
  pUser = fopen("user.txt", "a");
  printf("Please Enter Your Task Description:\t");
  gets(str);
  fprintf(pUser,"%s",str);
  printf("Your message is appended in data.txt file.");
  fclose(pUser);
}

//To Validate Date Input From User
int main(day,month,year) {
    int dd,mm,yy;

    //check year
    while (1){
        printf("Enter date (DD/MM/YYYY format): ");
        scanf("%d/%d/%d",&dd,&mm,&yy);
        if(yy>=1900 && yy<=2022) {
        //check month
            if(mm>=1 && mm<=12) {
                //check days
                if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)) {
                    printf("Date is valid.\n");
                    break;
                } else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11)) {
                    printf("Date is valid.\n");
                    break;
                } else if((dd>=1 && dd<=28) && (mm==2)){
                    printf("Date is valid.\n");
                    break;
                } else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0))){
                    printf("Date is valid.\n");
                    break;
                } else{
                    printf("Day is invalid.\n");
                    continue;
                }
            } else {
                printf("Month is not valid.\n");
                continue;
            }
        } else {
            printf("Year is not valid.\n");
            continue;
        }
        return 0;    
    }
}







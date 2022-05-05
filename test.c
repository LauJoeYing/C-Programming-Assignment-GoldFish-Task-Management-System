#include <string.h>
#include <time.h>
#include <stdio.h>


//To Print Current Date & Time
int date(){
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  return 0;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// #include <stdio.h>
// #include <stdlib.h>
// #define BUFFER_SIZE 1000

// int readFile(FILE * fPtr);

// //Display at the First Page For New User to Sign Up.
// int signup(){
//     FILE *user_fPtr;

//     char username[20];
//     printf("Please Enter Your Account Username (8-20 Characters):\t");
//     scanf("%s",&username);

//     char user_password[50];
//     printf("Please Enter Your Account Password (8-20 Characters):\t");
//     scanf("%s",&user_password);

//     char user_name[256];
//     printf("Please Enter Your Name:\t");
//     scanf("%s",&user_name);

//     char user_contact_num[20];
//     printf("Please Enter Your Contact Number (With +Country Code):\t");
//     scanf("%s",&user_contact_num);

//     char user_dob[10];
//     printf("Please Enter Your Date of Birth:\t");
//     scanf("%s",&user_dob);

//     char user_email[320];
//     printf("Please Enter Your Email for Registration:\t");
//     scanf("%s",&user_email);

//     char userData[1000] = "";
    

//     strcat(userData, username);
//     strcat(userData, " | ");
//     strcat(userData, user_password);
//     strcat(userData, " | ");
//     strcat(userData, user_name);
//     strcat(userData, " | ");
//     strcat(userData, user_contact_num);
//     strcat(userData, " | ");
//     strcat(userData, user_dob);
//     strcat(userData, " | ");
//     strcat(userData, user_email);
    
//     user_fPtr = fopen("users.txt", "a");

//     /* Append data to file */
//     fprintf(user_fPtr, "\n%s", userData); 

//     /* Reopen file in read mode to print file contents */
//     user_fPtr = freopen("users.txt", "r", user_fPtr);

//     /* Print file contents after appending string */
//     printf("\nSuccessfully appended data to file. \n");
//     printf("Changed file contents:\n\n");         
//     readFile(user_fPtr);

//     /* Done with file, hence close file. */
//     fclose(user_fPtr);
//     return 0;
// };


// EOF= End of File
int readFile(FILE * f_user)
{
    char ch;
    do 
    {
        ch = fgetc(f_user);

        putchar(ch);

    } while (ch != EOF);
    return 0;
};
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



#include <string.h>
#include <time.h>
#include <stdio.h>
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
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
                    char date_record[20] = "";
                    strcat(date_record, dd);
                    strcat(date_record, "/");
                    strcat(date_record, mm);
                    strcat(date_record, "/");
                    strcat(date_record, yy);
                    printf("Date is valid.\n",date_record);
                    break;
                } else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11)) {
                    printf("Date is valid.\n");
                    return (dd,mm,yy);
                    break;
                } else if((dd>=1 && dd<=28) && (mm==2)){
                    printf("Date is valid.\n");
                    return (dd,mm,yy);
                    break;
                } else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0))){
                    printf("Date is valid.\n");
                    return (dd,mm,yy);
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
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++





//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int create_task_confirmation(date, new_title, new_task){
    int choice;
    do{
      printf("Is all the details entered correctly and can be saved into the database?");
      choice = twoChoices("1","Completed and Proceed","2", "Modify");
      switch (choice){
        case "X" || "x" : return;        
        case 1:
        case 2:
          for (int loop = 0; loop<=75; loop++){
            printf("-");
          } 

          printf("======= Section that you would like to modify =======");
          printf("[ 1 ] - Deadline of the Task");
          printf("[ 2 ] - New Task Category");
          printf("[ 3 ] - New Task Title");
          printf("[ 4 ] - New Task Description");
          printf("[ 5 ] - New Task Status");
          printf("[ 5 ] - New Task Priority");
          printf("[ X ] - Back");
          choice = process_num(3);
          switch (choice){
            case "X" || "x": continue;
            case 1:
              printf("\nPrevious Entered Deadline\t\t:",add_task(date))
          }
      }
    }
    while (1){

    }
    //progress and status

}

int add_new_task()
{
    char task_title[50];
    char task_description, task_category, task_status,task_priority, task_deadline;
    int block;
    printf("===*===*===*== Welcome to Add Task Section ==*===*===*===*");
    printf("\nNew task of");
    printf("\nPlease Enter the Deadline of the Task ");
    //date validation

    printf("\n===== Please Select the New Task Category =====");
    printf("[ 1 ] - Personal");
    printf("[ 2 ] - Work");
    printf("[ 3 ] - Social");
    printf("[ 4 ] - Create New Category");
    switch (block)
    {
        case 1: 
          task_category = "Personal";
        case 2:
          task_category = "Work";
        case 3:
          task_category = "Social";
        case 4:
          printf("Please Enter Your New Task Category:");
          scanf("%s",&task_category);
    }

    printf("\nPlease Enter the New Task Title ");
    scanf("%s",task_title);

    printf("\nPlease Enter the New Task Description (Max 1000 Characters");
    scanf("%s",task_description);

    printf("\n===== Please Select the New Task Status: =====");
    printf("[ 1 ] - Not Started");
    printf("[ 2 ] - In Progress");
    printf("[ 3 ] - Done");
    printf("[ 4 ] - Canceled");
    switch (block)
    {
        case 1: 
          task_status = "Not Started";
        case 2:
          task_status= "In Progress";
        case 3:
          task_status = "Done";
        case 4:
          task_status = "Canceled";
    }

    printf("\n===== Please Select the New Task Priority: =====");
    printf("[ 1 ] - Low");
    printf("[ 2 ] - Normal");
    printf("[ 3 ] - Slightly Urgent");
    printf("[ 4 ] - Urgent");
    switch (block)
    {
        case 1: 
          task_priority = "Low";
        case 2:
          task_priority= "Normal";
        case 3:
          task_priority = "Slightly Urgent";
        case 4:
          task_priority = "Urgent";
    }

    char task_record[1000] = "";
    
    strcat(task_record, username);
    strcat(task_record, " | ");
    strcat(task_record, user_password);
    strcat(task_record, " | ");
    strcat(task_record, user_name);
    strcat(task_record, " | ");
    strcat(task_record, user_contact_num);
    strcat(task_record, " | ");
    strcat(task_record, user_dob);
    strcat(task_record, " | ");
    strcat(task_record, user_email);
    
    user_fPtr = fopen("users.txt", "a");

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
    return 0;
  };

  
}


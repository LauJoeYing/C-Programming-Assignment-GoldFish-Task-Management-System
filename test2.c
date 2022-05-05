

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "dateValidation.c"
//#include "date.h"

struct Tasks
{
    //struct Dates date;
    char category[100];
    char title[100];
    char description[1000];
    char status[10];
    char priority[20];

} task;


int main()
{
    struct Tasks task;
    int block;
    FILE *checkFileExistence(char *fileName, char *fileHandling_method);

    printf("\n\n===*===*===*== Welcome to Add Task Section ==*===*===*===*");
    printf("\nNew task of");
    // printf("\nPlease Enter the Deadline of the Task (DD/MM/YYYY):\t");
    // scanf("%d/%d/%d",&task.date.day,&task.date.month,&task.date.year);
    // printf("Deadline: %d/%d/%d", task.date.day, task.date.month, task.date.year);
    //struct Dates date = dateValidation();

    printf("\n\n===== New Task Category =====");
    printf("\n[ 1 ] - Personal\n");
    printf("[ 2 ] - Work\n");
    printf("[ 3 ] - Social\n");
    printf("[ 4 ] - Create New Category\n");
    printf("\nPlease Select the New Task Category:\t");
    scanf("%i",block);
    switch (block)
    {
        case 1: 
          strcpy(task.category,"Personal");
        case 2:
          strcpy(task.category,"Work");
        case 3:
          strcpy(task.category,"Social");
        case 4:
          printf("\nPlease Enter Your New Task Category:\t");
          scanf("%s",&task.category);
    }

    printf("\nPlease Enter the New Task Title:\t");
    scanf("%s",task.title);

    printf("\nPlease Enter the New Task Description (Max 1000 Characters):\t");
    scanf("%s",task.description);

    printf("\n\n====== New Task Status: ======");
    printf("\n[ 1 ] - Not Started");
    printf("\n[ 2 ] - In Progress\n");
    printf("[ 3 ] - Done\n");
    printf("[ 4 ] - Canceled\n");
    printf("\nPlease Select the New Task Status:\t");
    scanf("%i",block);
    switch (block)
    {
        case 1: 
          strcpy(task.status,"Not Started");
        case 2:
          strcpy(task.status,"In Progress");
        case 3:
          strcpy(task.status,"Done");
        case 4:
          strcpy(task.status,"Canceled");
    }

    printf("\n\n====== New Task Priority: ======");
    printf("\n[ 1 ] - Low\n");
    printf("[ 2 ] - Normal\n");
    printf("[ 3 ] - Slightly Urgent\n");
    printf("[ 4 ] - Urgent\n");
    printf("\nPlease Select the New Task Priority:\t");
    scanf("%i",block);
    switch (block)
    {
        case 1: 
          strcpy(task.priority,"Low");
        case 2:
          strcpy(task.priority,"Normal");
        case 3:
          strcpy(task.priority,"Slightly Urgent");
        case 4:
          strcpy(task.priority,"Urgent");
    }

    struct Tasks data ={
      task.category,task.title,task.description,task.status,task.priority
    };
    return 0;
    FILE*fileAppender = fopen("joeying.txt","a");
    fprintf(fileAppender,"\n%s | %s | %s | %s | %s",task.category,task.title,task.description,task.status,task.priority);
    fwrite(&data,sizeof(struct Tasks),1,fileAppender);
    fclose(fileAppender);
    printf("bye");
    return 0;
}


//example
#include <stdio.h>
#include <string.h>

int main () {
   char str1[15];
   char str2[15];

   strcpy(str1, "tutorialspoint");
   strcpy(str2, "compileonline");

   puts(str1);
   puts(str2);
   
   return(0);
}



#include <stdio.h>
#include <string.h>

//Add New Task

int add_task()
{
    char new_task,new_title,user_data,date;
    char date[10];
    int deadline_day, deadline_month, deadline_year,day,month,year;
    FILE*fp=FOPEN("users","r");

    printf("Please Enter the Deadline of the Task (DD/MM/YY):\n");
    scanf("%d/%d/%d",&deadline_day,&deadline_month,&deadline_year);
    date_validation(day,month,year);
    sprintf(date,"%i/%i/%i",day,year,month);

    printf("Please Enter Your New Task Title:\n");
    scanf("%s", &new_title);

    printf("Please Enter Your New Task Description:\n");
    scanf("%s", &new_task);

    return date, new_title, new_task;
    create_task_confirmation();
}


  


    


//To Validate Date Input From User
int date_validation(day,month,year) {
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
 
    
int twoChoices(choice1, choice1Action, choice2, choice2Action){
  printf(choice1, "-", choice1Action);
  printf( choice2, "-",choice2Action);
  if (choice2 == "X"){
    return process_num(1);
  } else{
    return process_num(2);
  }
}



    

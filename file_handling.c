
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
          printf("[ 2 ] - New Task Title");
          printf("[ 3 ] - New Task Description");
          printf("[ X ] - Back");
          choice = process_num(3);
          switch (choice){
            case "X" || "x": continue;
            case 1:
              printf("\nPrevious Entered Deadline\t\t:",add_task(date))
          }
      }
    }
    while (true){

    }
    //progress and status

}


    


void date_validation(day,month,year)
{

if ((day>30) && (month == (2||4||6|9||11))){
  printf("Invalid Date!, The Month Given Only Have 30 Days");
  add_task();
}

if ((day>31) && (month ==(1||2||3||5||7||8||10||12))){
  printf("Invalid Date!, The Month Given Only Have 31 Days!");
  add_task();
}

if ((day>29 && month == 2)){
  printf("Invalid Date!, February Have Maximum 29 days Only!");
  add_task();
}

if (year<0 || year>2022){
  printf ("Invalid Date!, Please Try Again!");
  add_task();
}

if (month<1 || month>12){
  printf("Invalid Input for Month!, Please Try Again!");
  add_task();
}}
 
    
int twoChoices(choice1, choice1Action, choice2, choice2Action){
  printf(choice1, "-", choice1Action);
  printf( choice2, "-",choice2Action);
  if (choice2 == "X"){
    return process_num(1);
  } else{
    return process_num(2);
  }
}



    

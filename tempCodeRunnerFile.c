#include <stdio.h>

void main(){


  while (1){
    int day,month,year;
    printf ("Please Enter the date in (DD/MM/YY):\t");
    scanf("%d/%d/%d",&day,&month,&year);

    if ((day>30) && (month == (2||4||6|9||11))){
      printf("Invalid Date!, The Month Given Only Have 30 Days");
      continue;
    //add_task();
    }

    if ((day>31) && (month ==(1||2||3||5||7||8||10||12))){
      printf("Invalid Date!, The Month Given Only Have 31 Days!");
      continue;
      //add_task();
    }

    if ((day>29) && (month == 2)){
      printf("Invalid Date!, February Have Maximum 29 days Only!");
      continue;
      //add_task();
    }

    if ((year<0) || (year>2022)){
      printf ("Invalid Date!, Please Try Again!");
      continue;
      //add_task();
    }

    if ((month<1) ||(month>12)){
      printf("Invalid Input for Month!, Please Try Again!");
      continue;
      //add_task();
    }
  }
  return 0;
}
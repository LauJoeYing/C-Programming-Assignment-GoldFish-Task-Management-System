#include <stdio.h>
int main() {
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
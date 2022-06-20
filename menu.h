#ifndef MENU_H
#define MENU_H 

#include <stdio.h> // define the header file 
#include <string.h>
#include <stdbool.h>  
#include <ctype.h>
#include <stdlib.h>

int user_menu();
int admin_menu();
int getChoiceNum(int maxChoice, int minChoice);
int checkIsNumber(char *target);
int toLower(char *str);

#endif
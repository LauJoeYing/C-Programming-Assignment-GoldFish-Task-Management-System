#ifndef ACCOUNT_H
#define ACCOUNT_H 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "account.h"
#include "file.h"
#include "menu.h"
#include "date.h"

typedef struct Accounts {
    char email[321];
    char name[256];
    char username[21];
    char password[21];
    char contactNum[11];
    Date dateOfBirth;
    char userType;
} Account;

int welcomePage();
//int registerUser(Account user);
int registration();
int register_username(char *usernameTarget);
int register_password(char *passwordTarget);
int register_name(char *nameTarget);
int register_contactNum(char *contactNumTarget);
int register_dateOfBirth(Date *dateOfBirthTarget);
int register_email(char *emailTarget);
Account loginUser();
int getUserData();
int changePassword(char *username, char *password);

#endif
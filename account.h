#ifndef ACCOUNT_H
#define ACCOUNT_H 
#include "date.h"

typedef struct Accounts {
    char username[21];
    char password[21];
    char name[256];
    char contact_num[11];
    Date dateOfBirth;
    char email[321];
    char userType;
} Account;

#endif
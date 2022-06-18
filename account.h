#ifndef ACCOUNT_H
#define ACCOUNT_H 

typedef struct Accounts {
    char username[21];
    char password[21];
    char name[256];
    char contact_num[21];
    char date_of_birth[11];
    char email[321];
    char userType;
} Account;

#endif
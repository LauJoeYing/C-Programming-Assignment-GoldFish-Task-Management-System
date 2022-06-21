#ifndef ADMIN_H
#define ADMIN_H 

#include <stdio.h>
#include <string.h>
#include "date.h"
#include "menu.h"
#include "task.h"
#include "account.h"
#include "file.h"

int adminPage(char *adminUsername, char *adminPassword);
int recoverUserAcct();

#endif
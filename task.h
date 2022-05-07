#ifndef TASK_H
#define TASK_H 
#include "date.h"

typedef struct Tasks {
    int taskId;
    char username[21];
    struct tm datetime_of_creation;
    Date deadline;
    char title[256];
    char description[1001];
    char category[256];
    int status_code;
    int priority_code;
} Task;

#endif
#ifndef TASK_H
#define TASK_H 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task.h"
#include "date.h"
#include "menu.h"
#include "file.h"

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

int addTask(char *username);
int readTask(char *username);
int updateTask(char *username);
int searchTask(char *username);
int sortTask();
int sortByStatusCode(int taskCount, Task *task, Task taskCopy, int ascendingOrder);
int sortByPriorityCode(int taskCount, Task *task, Task taskCopy, int ascendingOrder);
int sortByTitle(int taskCount, Task *task, Task taskCopy, int ascendingOrder);
int sortByDeadline(int taskCount, Task *task, Task taskCopy, int ascendingOrder);
int sortByDatetimeOfCreation(int taskCount, Task *task, Task taskCopy, int ascendingOrder);
int deleteTask(char *username);
int readAllTask();
int appendTask(char *username, Task task);
int confirmTask(char *username, Task *task);
int setTaskCategory(Task *task);
int setTaskTitle(Task *task);
int setTaskDescription(Task *task);
int setTaskStatusCode(Task *task);
int setTaskPriorityCode(Task *task);
int setTaskDeadline(Task *task);
int displayTask(Task *task);
int displayDatetime(struct tm datetime);
char *displayStatusCode(int statusCode);
char *displayPriorityCode(int priorityCode);

#endif

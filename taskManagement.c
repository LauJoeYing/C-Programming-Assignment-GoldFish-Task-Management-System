#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "task.h"
#include "date.h"
#include "menu.h"
#include "dateValidation.c"
#include "menu.c"
#include "fileHandling.c"

int addTask(char *username);
int readTask(char *username);
int editTask(char *username);
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


int main() {
    char username[] = "angniuniu";
    int continueTaskManagement = 1;
    do {
        printf("\nTask Management");
        printf("\n[ 1 ] - View All Tasks");
        printf("\n[ 2 ] - Add Task");
        printf("\n[ 3 ] - Edit Task");
        printf("\n[ 4 ] - Search Task");
        printf("\n[ 5 ] - Sort Tasks");
        printf("\n[ 6 ] - Delete Task");
        printf("\n[ 0 ] - Back");
        int taskManagementChoice = getChoiceNum(6, 0);
        switch (taskManagementChoice) {
            case 1:
                readTask(username);
                break;
            case 2:
                addTask(username);
                break;
            case 3:
                editTask(username);
                break;
            case 4:
                searchTask(username);
                break;
            case 5:
                sortTask();
                break;
            case 6:
                deleteTask(username);
                break;
            case 0:
                continueTaskManagement = 0;
                break;
        }
    } while (continueTaskManagement);

    return 0;
};

int addTask(char *username) {
    Task *tasks;
    int numberOfTasks;

    printf("\n===*===*===*== Welcome to Add Task Section ==*===*===*===*");

    printf("\nEnter the number of new tasks to be added: ");
    numberOfTasks = getChoiceNum(10, 0);

    // if (!numberOfTasks)

    tasks = (Task*)calloc(numberOfTasks, sizeof(Task));

    for (int i = 0; i < numberOfTasks; i++) {
        printf("\n-New task (%i) to be added-", i + 1);
        //Record username of new task
        strcpy(tasks[i].username, username);
        //Enter category of new task
        setTaskCategory(&tasks[i]);
        //Enter title of new task
        setTaskTitle(&tasks[i]);
        //Enter description of new task
        setTaskDescription(&tasks[i]);
        //Enter status of new task
        setTaskStatusCode(&tasks[i]);
        //Enter priority of new task
        setTaskPriorityCode(&tasks[i]);
        //Enter deadline of new task
        setTaskDeadline(&tasks[i]);
        //Confirm new task details
        confirmTask(username, &tasks[i]);
        appendTask(username, tasks[i]);
    };
    
    return 0;
};

int setTaskCategory(Task *task) {
    
    printf("\n===== Please Select the New Task Category =====");
    printf("\n[ 1 ] - Personal");
    printf("\n[ 2 ] - Work");
    printf("\n[ 3 ] - Social");
    printf("\n[ 4 ] - Create New Category\n");

    int categoryChoice = getChoiceNum(4, 1);
    switch(categoryChoice) {
        case 1:
            strcpy(task -> category, "Personal");
            break;
        case 2:
            strcpy(task -> category, "Work");
            break;
        case 3:
            strcpy(task -> category, "Social");
            break;
        case 4:
            fflush(stdin);
            printf("Please Enter Your New Task Category :\n");
            scanf("%[^\n]s", task -> category);
            break;
    };
    return 0;
};

int setTaskTitle(Task *task) {
    fflush(stdin);
    printf("\nPlease Enter the New Task Title :\n");
    scanf("%[^\n]s", task -> title);

    return 0;
};

int setTaskDescription(Task *task) {
    fflush(stdin);
    printf("\nPlease Enter the New Task Description (Max 1000 Characters) :\n");
    scanf("%[^\n]s", task -> description);

    return 0;
};

int setTaskStatusCode(Task *task) {
    printf("\n===== Please Select the New Task Status =====");
    printf("\n[ 1 ] - Not Started");
    printf("\n[ 2 ] - In Progress");
    printf("\n[ 3 ] - Done");
    printf("\n[ 4 ] - Canceled\n");

    // status_code 1 = Not Started
    // status_code 2 = In Progress
    // status_code 3 = Done
    // status_code 4 = Canceled
    task -> status_code = getChoiceNum(4, 1);

    return 0;
};

int setTaskPriorityCode(Task *task) {
    printf("\n===== Please Select the New Task Priority =====");
    printf("\n[ 1 ] - Low");
    printf("\n[ 2 ] - Normal");
    printf("\n[ 3 ] - Slightly Urgent");
    printf("\n[ 4 ] - Urgent\n");
    
    // status_code 1 = Low
    // status_code 2 = Normal
    // status_code 3 = Slightly Urgent
    // status_code 4 = Urgent
    task -> priority_code = getChoiceNum(4, 1);

    return 0;
};

int setTaskDeadline(Task *task) {
    printf("\nPlease Enter the Deadline of the Task : \n");
    task -> deadline = dateValidation();   

    return 0;
};

int confirmTask(char *username, Task *task) {
    int continueLoop = 1;
    do {
        printf("\nTask Confirmation");
        displayTask(task);
        int confirmChoice;
        printf("\nConfirm task details? ");
        printf("\n[ 1 ] - Confirm");
        printf("\n[ 2 ] - Modify\n");
        confirmChoice = getChoiceNum(2, 1);
        switch (confirmChoice) {
            case 1:
                continueLoop = 0;
                break;
            case 2:
                printf("\nPlease Select the Task Field to be Modified: ");
                printf("\n[ 1 ] - Category");
                printf("\n[ 2 ] - Title");
                printf("\n[ 3 ] - Description");
                printf("\n[ 4 ] - Status");
                printf("\n[ 5 ] - Priority");
                printf("\n[ 6 ] - Deadline");
                printf("\n[ 0 ] - Back\n");

                int modifyChoice = getChoiceNum(6, 0);
                switch (modifyChoice) {
                    case 1:
                        setTaskCategory(task);
                        break;
                    case 2:
                        setTaskTitle(task);
                        break;
                    case 3:
                        setTaskDescription(task);
                        break;
                    case 4:
                        setTaskStatusCode(task);
                        break;
                    case 5:
                        setTaskPriorityCode(task);
                        break;
                    case 6:
                        setTaskDeadline(task);
                        break;
                    case 0:
                        break;
                }
        };
    } while (continueLoop);

    printf("\nRecording your task....");
    
    return 0;
};

int appendTask(char *username, Task task) {
    int taskId = 1;
    Task readTask;
    FILE *taskFileAppenderPlus;
    taskFileAppenderPlus = checkFileExistence("task_recordtry.txt", "a+", 1);
    while (fread(&readTask, sizeof(Task), 1, taskFileAppenderPlus)) {
        if (strcmp(readTask.username, username) ==  0) {
            taskId++;
        } 
    };
    task.taskId = taskId;
    time_t now;
    now = time(NULL);
    task.datetime_of_creation = *localtime(&now);
    fwrite(&task, sizeof(Task), 1, taskFileAppenderPlus);
    fclose(taskFileAppenderPlus);
    printf("\nDone!\n");
    return 0;
};

int readTask(char *username) {
    Task task;
    FILE *taskFileReader;
    int found = 0;
    taskFileReader = checkFileExistence("task_recordtry.txt", "r", 0);    
    while(fread(&task, sizeof(Task), 1, taskFileReader)) {
        if (strcmp(task.username, username) == 0) {
            printf("\nTask ID\t\t\t: %03d", task.taskId);
            printf("\nDatetime of Creation\t: ");
            displayDatetime(task.datetime_of_creation);
            displayTask(&task);
            found++;
        };
    };
    fclose(taskFileReader);
    printf("\nNumber of Task(s) Created : %i\n", found);
    if (!found) {
        printf("\nNo record found. Add new task now :)\n");
    };
    return 0;
};

int readAllTask() {
    Task task;
    FILE *taskFileReader;
    taskFileReader = checkFileExistence("task_recordtry.txt", "r", 0);    
    while(fread(&task, sizeof(Task), 1, taskFileReader)) {
        printf("\nUsername\t\t: %s", task.username);
        printf("\nTask ID\t\t\t: %03d", task.taskId);
        printf("\nDatetime of Creation\t: ");
        displayDatetime(task.datetime_of_creation);
        displayTask(&task);
    };
    fclose(taskFileReader);
    return 0;
};

int displayTask(Task *task) {
    printf("\nCategory\t\t: %s", task -> category);
    printf("\nTitle\t\t\t: %s", task -> title);
    printf("\nDescription\t\t: %s", task -> description);
    printf("\nStatus\t\t\t: %s", displayStatusCode(task -> status_code));
    printf("\nPriority\t\t: %s", displayPriorityCode(task -> priority_code));
    printf("\nDeadline (DD/MM/YYYY)\t: %02d/%02d/%04d\n", task -> deadline.day, task -> deadline.month, task -> deadline.year);

    return 0;
};

//To Print Current Date & Time
int displayDatetime(struct tm datetime) {
    printf("%02d/%02d/%04d %02d:%02d:%02d", datetime.tm_mday, datetime.tm_mon + 1, datetime.tm_year + 1900, datetime.tm_hour, datetime.tm_min, datetime.tm_sec);
    
    return 0;
};

char *displayStatusCode(int statusCode) {
    switch(statusCode) {
        case 1:
            return "Not Started";
            break;
        case 2:
            return "In Progress";
            break;
        case 3:
            return "Done";
            break;
        case 4:
            return "Canceled";
            break;
    };
};

char *displayPriorityCode(int priorityCode) {
    switch(priorityCode) {
        case 1:
            return "Low";
            break;
        case 2:
            return "Normal";
            break;
        case 3:
            return "Slightly Urgent";
            break;
        case 4:
            return "Urgent";
            break;
    };
};

int editTask(char *username) {
    char searchKey[256];
    Task task;
    FILE *taskFileReader, *taskFileWriter;
    int found = 0;

    fflush(stdin);
    printf("\nTask ID to be edited : ");
    scanf("%[^\n]s", searchKey);
    int taskId = atoi(searchKey);

    taskFileReader = checkFileExistence("task_recordtry.txt", "r", 0); 
    taskFileWriter = fopen("temp_task_recordtry.txt", "w");   
    while(fread(&task, sizeof(Task), 1, taskFileReader)) {
        if ((strcmp(task.username, username) == 0) && (task.taskId == taskId)) {
            found = 1;
            printf("\nTask ID\t\t\t: %03d", task.taskId);
            printf("\nDatetime of Creation\t: ");
            displayDatetime(task.datetime_of_creation);
            confirmTask(username, &task);
            
        };
        fwrite(&task, sizeof(Task), 1, taskFileWriter);
    };
    fclose(taskFileReader);
    fclose(taskFileWriter);
    printf("\nDone!\n");
    remove("task_recordtry.txt");
    rename("temp_task_recordtry.txt", "task_recordtry.txt");
    if (!found) {
        printf("\nNo record found with the task id. Please try again.\n");
    };
    return 0;
};

int searchTask(char *username) {
    char searchKey[256], searchSource[1256];
    Task task;
    FILE *taskFileReader;
    int found = 0;

    fflush(stdin);
    printf("\nSearch : ");
    scanf("%[^\n]s", searchKey);
    toLower(searchKey);

    taskFileReader = checkFileExistence("task_recordtry.txt", "r", 0);    
    while(fread(&task, sizeof(Task), 1, taskFileReader)) {
        strcpy(searchSource, task.title);
        strcat(searchSource, task.description);
        toLower(searchSource);
        if ((strcmp(task.username, username) == 0) && strstr(searchSource, searchKey)) {
            printf("\nTask ID\t\t\t: %03d", task.taskId);
            printf("\nDatetime of Creation\t: ");
            displayDatetime(task.datetime_of_creation);
            displayTask(&task);
            found++;
        };
    };
    fclose(taskFileReader);
    printf("\nNumber of Task(s) Found : %i\n", found);
    if (!found) {
        printf("\nNo record found. Add new task now :)\n");
    };
    
    return 0;
};

int sortTask() {
    printf("\nSort By\n");
    printf("\n[ 1 ] - Title");
    printf("\n[ 2 ] - Status");
    printf("\n[ 3 ] - Priority");
    printf("\n[ 4 ] - Deadline");
    printf("\n[ 5 ] - Datetime of Creation");
    printf("\n[ 0 ] - Back\n");

    int sortChoice = getChoiceNum(5, 0);
    int orderChoice;
    if (sortChoice) {
        printf("\nOrder By\n");
        printf("\n[ 1 ] - Descending");
        printf("\n[ 2 ] - Ascending");
        orderChoice = getChoiceNum(2, 1);

        Task *task, taskCopy;
        FILE *taskFileReader = checkFileExistence("task_recordtry.txt", "r", 0);
        fseek(taskFileReader, 0 ,SEEK_END);
        int taskCount = ftell(taskFileReader)/sizeof(Task);
        task = (Task*)calloc(taskCount, sizeof(Task));
        rewind(taskFileReader);

        for(int i = 0; i < taskCount; i++) 
            fread(&task[i], sizeof(Task), 1, taskFileReader);

        switch(sortChoice) {
            case 1:
                sortByTitle(taskCount, task, taskCopy, orderChoice-1);
                break;
            case 2:
                sortByStatusCode(taskCount, task, taskCopy, orderChoice-1);
                break;
            case 3:
                sortByPriorityCode(taskCount, task, taskCopy, orderChoice-1);
                break;
            case 4:
                sortByDeadline(taskCount, task, taskCopy, orderChoice-1);
                break;
            case 5:
                sortByDatetimeOfCreation(taskCount, task, taskCopy, orderChoice-1);
                break;
            case 0:
                break;
        }

        for (int i = 0; i < taskCount; i++) {
            printf("\nTask ID\t\t\t: %03d", task[i].taskId);
            printf("\nDatetime of Creation\t: ");
            displayDatetime(task[i].datetime_of_creation);
            displayTask(&task[i]);
        };
        
        fclose(taskFileReader);
    };

    return 0;
};

int sortByStatusCode(int taskCount, Task *task, Task taskCopy, int ascendingOrder) {
    for(int i = 0; i < taskCount; i++) {
        for(int j = (i+1); j < taskCount; j++) {
            if(ascendingOrder ? (task[i].status_code > task[j].status_code) : (task[i].status_code < task[j].status_code)) {
                taskCopy = task[i];
                task[i] = task[j];
                task[j] = taskCopy;
            };
        };
    };

    return 0;
};

int sortByPriorityCode(int taskCount, Task *task, Task taskCopy, int ascendingOrder) {
    for(int i = 0; i < taskCount; i++) {
        for(int j = (i+1); j < taskCount; j++) {
            if(ascendingOrder ? (task[i].priority_code > task[j].priority_code) : (task[i].priority_code < task[j].priority_code)) {
                taskCopy = task[i];
                task[i] = task[j];
                task[j] = taskCopy;
            };
        };
    };

    return 0;
};

int sortByTitle(int taskCount, Task *task, Task taskCopy, int ascendingOrder) {
    for(int i = 0; i < taskCount; i++) {
        for(int j = (i+1); j < taskCount; j++) {
            if(ascendingOrder ? (strcmp(task[i].title, task[j].title) > 0) : (strcmp(task[i].title, task[j].title) < 0)) {
                taskCopy = task[i];
                task[i] = task[j];
                task[j] = taskCopy;
            };
        };
    };

    return 0;
};

int sortByDeadline(int taskCount, Task *task, Task taskCopy, int ascendingOrder) {
    for(int i = 0; i < taskCount; i++) {
        for(int j = (i+1); j < taskCount; j++) {
            Date date_i = task[i].deadline;
            Date date_j = task[j].deadline;
            if (ascendingOrder ? 
            ((date_i.day + date_i.month * 100 + date_i.year * 1000) > (date_j.day + date_j.month * 100 + date_j.year * 1000)) : 
            ((date_i.day + date_i.month * 100 + date_i.year * 1000) < (date_j.day + date_j.month * 100 + date_j.year * 1000))) {
                taskCopy = task[i];
                task[i] = task[j];
                task[j] = taskCopy;
            }
        };
    };


    return 0;
};

int sortByDatetimeOfCreation(int taskCount, Task *task, Task taskCopy, int ascendingOrder) {
    for(int i = 0; i < taskCount; i++) {
        for(int j = (i+1); j < taskCount; j++) {
            time_t time_i = mktime(&task[i].datetime_of_creation);
            time_t time_j = mktime(&task[j].datetime_of_creation);
            if(ascendingOrder ? (difftime(time_i, time_j) > 0) : (difftime(time_i, time_j) < 0)) {
                taskCopy = task[i];
                task[i] = task[j];
                task[j] = taskCopy;
            };
        };
    };

    return 0;
};

int deleteTask(char *username) {
    char searchKey[256];
    Task task;
    FILE *taskFileReader, *taskFileWriter;
    int found = 0;

    fflush(stdin);
    printf("\nTask ID to be deleted : ");
    scanf("%[^\n]s", searchKey);
    int taskId = atoi(searchKey);

    taskFileReader = checkFileExistence("task_recordtry.txt", "r", 0); 
    taskFileWriter = fopen("temp_task_recordtry.txt", "w");   
    while(fread(&task, sizeof(Task), 1, taskFileReader)) {
        if (strcmp(task.username, username) == 0) {
            if (task.taskId == taskId) {
                found = 1;
                printf("\nTask ID\t\t\t: %03d", task.taskId);
                printf("\nDatetime of Creation\t: ");
                displayDatetime(task.datetime_of_creation);
                displayTask(&task);
                printf("\nConfirm Delete ?\n");
                printf("[ 1 ] - Delete\n");
                printf("[ 0 ] - Back\n");
                int deleteChoice = getChoiceNum(1, 0);
                if (deleteChoice) {
                    printf("Deleting task...");
                    continue;
                };
            } else {
                if (task.taskId > taskId) {
                    task.taskId--;
                }
            }
            
        };
        fwrite(&task, sizeof(Task), 1, taskFileWriter);
    };
    fclose(taskFileReader);
    fclose(taskFileWriter);
    printf("\nDone!\n");
    remove("task_recordtry.txt");
    rename("temp_task_recordtry.txt", "task_recordtry.txt");
    if (!found) {
        printf("\nNo record found with the task id. Please try again.\n");
    };
    return 0;
};

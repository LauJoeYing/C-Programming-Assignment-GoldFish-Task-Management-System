#include "account.h"

int welcomePage()
{
    int option;
    Account user;
    do {
        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
        printf("\n\n\tWelcome to Goldfish Task Management System!\n\n");
        printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
        printf("\n[ 1 ] - Register");
        printf("\n[ 2 ] - Login\n\n");
        
        printf("Please Enter Your Choice Number:\t\n");
        scanf("%d",&option);

        switch (option) {
            case 1:
                registration();
                break;

            case 2:
                user = loginUser();
                break;

            default:
                option = 0;
                break;
        }   
    } while (option == 0);  

    return 0;
};

int registerUser(Account user) {
    char *userTypeDisplay = user.userType == 'a' ? "Admin" : "User";
    FILE *fileAppender;
    fileAppender = checkFileExistence("usertry.txt", "a", 1);
    fwrite(&user, sizeof(Account), 1, fileAppender);
    if (fwrite != 0) {
        printf("%s has been registered successfully!\n", userTypeDisplay);
    } else {
        printf("Error registering %s!\n", userTypeDisplay);
    };

    return 0;
};

int registration()
{
    printf("\n\n\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\n\n\t\tWelcome to New User Registration Page!\n\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

    Account user;
    
    FILE * fileAppender;
    fileAppender = checkFileExistence("usertry.txt", "a", 1);
    register_username(user.username);
    register_password(user.password);
    register_name(user.name);
    register_contactNum(user.contactNum);
    register_dateOfBirth(&user.dateOfBirth);
    register_email(user.email);
    user.userType = 'u';

    printf("\n--------------------------------------------------------------------------\n");
    printf("\nConfirming details...");
    printf("%s, %s, %s, %c, %s, %i, %i, %i, %s", user.username, user.password, user.contactNum, user.userType, user.name, user.dateOfBirth.day, user.dateOfBirth.month, user.dateOfBirth.year, user.email);
    printf("\n\nWelcome, %s :)\n", user.name);
    fwrite(&user, sizeof(Account), 1, fileAppender);
    fclose(fileAppender);
    printf("Registration Successful!\n");
    printf("\n--------------------------------------------------------------------------\n\n\n");

    return 0;
};

int register_username(char *usernameTarget)
{
    int validated = 0;
    do {
        int match = 0;
        char username[21], usernameCopy[21];
        printf("\n--------------------------------------------------------------------------\n\n");
        fflush(stdin);
        printf("\nPlease Enter Your New Username:\n");
        scanf("%[^\n]s", username);
        strcpy(usernameCopy, username);
        toLower(usernameCopy);

        Account existingUser;
        FILE *userFileReader;
        userFileReader = checkFileExistence("usertry.txt", "r", 0);    
        while(fread(&existingUser, sizeof(Account), 1, userFileReader)) {
            toLower(existingUser.username);
            if(strcmp(existingUser.username, usernameCopy) == 0) {
                printf("\nUsername \"%s\" is occupied! Please use another username.", username);
                match = 1;
                break;
            };
        };
        fclose(userFileReader);
        if (!match) {
            validated = 1;
            strcpy(usernameTarget, username);
        }
    } while (!validated);

    return 0;
};

int register_password(char *passwordTarget)
{
    char password[21];
    char confirmPassword[21];
    printf("\n--------------------------------------------------------------------------\n");
    while (1){
        fflush(stdin);
        printf("\nPlease Enter Your New Password (8-20 characters):\n");
        scanf("%[^\n]s", password);
        if (strlen(password) < 8 || strlen(password) > 20){
            printf("\nInvalid Password! Please Ensure Your New Password have 8-20 Characters");
            continue;
        }
        fflush(stdin);
        printf("\nPlease Enter Your New Password Again:\n");
        scanf("%[^\n]s", confirmPassword); 

        if(strcmp(confirmPassword, password)) {
            printf("\nInvalid Input! Please Ensure That You Have Entered the Same Password!");
            continue;
        }   
        
        printf("\nCorrect Password Format!\nCongrats! Your New Password has been Verified!");
        strcpy(passwordTarget, password);

        return 0;            
    }
};

int register_name(char *nameTarget)
{
    char name[256];
    printf("\n--------------------------------------------------------------------------\n");
    fflush(stdin);
    printf("\nPlease Enter Your Name:\n");
    scanf("%[^\n]s", name);
    strcpy(nameTarget, name);

    return 0;
};

int register_contactNum(char *contactNumTarget)
{
    char contactNum[11];
    printf("\n--------------------------------------------------------------------------\n");
    while(1) {
        fflush(stdin);
        printf("\nPlease Enter Your Contact Number (without'-'): \n60");
        scanf("%[^\n]s", contactNum);
        if(checkIsNumber(contactNum)) {
            if (contactNum[1] != '1' && strlen(contactNum) < 9 || contactNum[1] == '1' && strlen(contactNum) > 10){
                printf("\nInvalid Phone Number! Please Ensure Your Registered Phone Number have correct length!");
                continue;
            }
            printf("\nCorrect Phone Number Format!\nCongrats! Your Phone Number has been Verified!");
            strcpy(contactNumTarget, contactNum);
            break;
        } else {
            printf("\nInvalid Phone Number! Please Ensure Your Registered Phone Number contains only number!");
            continue;
        }   
    }

    return 0;
};

int register_dateOfBirth(Date *dateOfBirthTarget)
{
    printf("\n--------------------------------------------------------------------------");
    printf("\n\nDate of Birth\n");
    dateValidation(dateOfBirthTarget);
    printf("Congrats! Your Date of Birth has been Verified!");

    return 0;
};

int register_email(char *emailTarget)
{
    char email[321];
    printf("\n--------------------------------------------------------------------------");
    while(1) {
        printf("\n\nPlease Enter Your Email:\n");
        fflush(stdin);
        scanf("%[^\n]s", email);
        if(strstr(email, "@") && strstr(email, ".com")) {   //To Check the Occurrence of '@' and '.com'
            printf("Congrats! Your Email has been Verified!");
            strcpy(emailTarget, email);
            break;
        }   
        printf("Wrong Email Format! Please Try Again!");
        continue;
    }

    return 0;
};


Account loginUser() {
    int found = 0;

    printf("\n\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\n\n\t\t\t   Login Page\n\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\nPlease Enter Your Login Credentials Below:\n\n");

    do {
        char username[256], password[256];    
        Account user;
        FILE *taskFileReader;
        taskFileReader = checkFileExistence("usertry.txt", "r", 0);    
        fflush(stdin);
        printf("Username:\t");
        scanf("%[^\n]s", username);
        toLower(username);

        fflush(stdin);
        printf("\nPassword:\t");
        scanf("%[^\n]s", password);

        while(fread(&user, sizeof(Account), 1, taskFileReader)) {
            toLower(user.username);
            if ((strcmp(user.username, username) == 0) && (strcmp(user.password, password) == 0)) {
                printf("\nWelcome back, %s!", user.name); 
                fclose(taskFileReader);
                found = 1;
                return user;
            };
        };
        if (!found) {
            printf("\nIncorrect Login Details\nPlease enter the correct credentials!\n");
        };
    } while (!found);
    
};

int getUserData() {
    Account user;
    FILE *fileReader;
    fileReader = checkFileExistence("usertry.txt", "r", 0);
    while(fread(&user, sizeof(Account), 1, fileReader)) {
        printf ("username = %s password = %s\n", user.username, user.password);
    }
    fclose(fileReader);
    
    return 0;
};

// int changePassword(char * username, char * password) {
//     Account user;
//     char confirmPassword[256], newPassword[21];
//     FILE *taskFileReader, *taskFileWriter;
//     taskFileReader = checkFileExistence("usertry.txt", "r", 0); 
//     taskFileWriter = fopen("temp_usertry.txt", "w");
//     int passwordCorrect, found = 0;
    
//     do {
//         fflush(stdin);
//         printf("\nEnter old password to continue : ");
//         scanf("%[^\n]s", confirmPassword);
//         if (strcmp(confirmPassword, password) == 0) {
//             passwordCorrect++;
//             break;
//         } else {
//             printf("\nIncorrect Password! Please Try Again!");
//         };
//     } while (!passwordCorrect);
    
// }

int changePassword(char *username, char *password) {
    Account user;
    char confirmPassword[256], * newPassword;
    FILE *taskFileReader, *taskFileWriter;
    taskFileReader = checkFileExistence("usertry.txt", "r", 0); 
    taskFileWriter = fopen("temp_usertry.txt", "w");
    int passwordCorrect, found = 0;
    
    do {
        fflush(stdin);
        printf("\nPlease Enter Your Current Password:\t");
        scanf("%[^\n]s", confirmPassword);
        if (strcmp(confirmPassword, password) == 0) {
            passwordCorrect ++;
            break;
        } else {
            printf("\nIncorrect Password! Please Try Again!");
            continue;
        };
    } while (!passwordCorrect);
    

    fflush(stdin);
    register_password(newPassword);
     ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    scanf("%[^\n]s", newPassword);
    
    while(fread(&user, sizeof(Account), 1, taskFileReader)) {
        if (strcmp(user.username, username) == 0) {
            strcpy(user.password, newPassword); 
        };
        fwrite(&user, sizeof(Account), 1, taskFileWriter);
    };
    fclose(taskFileReader);
    fclose(taskFileWriter);
    printf("\nDone!\n");
    remove("usertry.txt");
    rename("temp_usertry.txt", "usertry.txt");
    
    return 0;
};

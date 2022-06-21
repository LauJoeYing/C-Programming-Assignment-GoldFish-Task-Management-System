#include "account.h"

//Registration Page for Both User and Admin
int registration()
{
    printf("\n\n\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\n\n\t\tWelcome to New User Registration Page!\n\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

    Account user;
    
    FILE * fileAppender;
    fileAppender = checkFileExistence("user.txt", "a", 1);
    register_username(user.username);
    register_password(user.password);
    register_name(user.name);
    register_contactNum(user.contactNum);
    register_dateOfBirth(&user.dateOfBirth);
    register_email(user.email);
    user.userType = 'u';

    printf("\n--------------------------------------------------------------------------\n");
    printf("\nConfirming details...");
    printf("\n\nWelcome, %s :)\n", user.name);
    fwrite(&user, sizeof(Account), 1, fileAppender);
    fclose(fileAppender);
    printf("Registration Successful!\n");
    printf("\n--------------------------------------------------------------------------\n\n\n");

    return 0;
};


//Function To Register the Username
//Data Validation: If the Same Username Has Been Registered, Then The System Will Request the User to Use Another Username
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
        userFileReader = checkFileExistence("user.txt", "r", 0);    
        while(fread(&existingUser, sizeof(Account), 1, userFileReader)) {
            toLower(existingUser.username);
            if(strcmp(existingUser.username, usernameCopy) == 0) {
                printf("\nUsername \"%s\" is occupied! Please Use Another Username.", username);
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

//Function To Register User Password
//Data Validation: Length of Password Must Greater Than 8, Lesser Than 20
//Data Validation: Type the New Password Twice to Ensure User Entered the Correct One
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



//Function To Register User's Name
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


//Function To Register User's Contact Number
//Prepared '60' for the Users
//Data Validation: If the 2nd Character of Contact Number Does Not Contain 1,  Total Length Must Be 10       
//Data Validation: If the 2nd Character of Contact Number Contain 1, Total Length Must Be 11 or 10
//Data Validation: "checkIsNumber" Has Been Used to Ensure Input From User are Solely Numbers
int register_contactNum(char *contactNumTarget)
{
    char contactNum[11];
    printf("\n--------------------------------------------------------------------------\n");
    while(1) {
        fflush(stdin);
        printf("\nPlease Enter Your Contact Number (without'-'): \n60");
        scanf("%[^\n]s", contactNum);
        if(checkIsNumber(contactNum)) {
            if (contactNum[0] = '1' && (contactNum[1] != '1' && strlen(contactNum) == 9 || contactNum[1] == '1' && strlen(contactNum) == 10)){       
                printf("\nCorrect Phone Number Format!\nCongrats! Your Phone Number has been Verified!");
                strcpy(contactNumTarget, contactNum);
                break;  
            }
            printf("\nInvalid Phone Number! Please Ensure Your Registered Phone Number have correct length!");
            continue;
        } else {
            printf("\nInvalid Phone Number! Please Ensure Your Registered Phone Number contains only number!");
            continue;
        }   
    }

    return 0;
};


//Function To Register User's Date of Birth
//Data Validation: Use "dateValidation" Function to Validate User Date Input is Correct
int register_dateOfBirth(Date *dateOfBirthTarget)
{
    printf("\n--------------------------------------------------------------------------");
    printf("\n\nDate of Birth\n");
    dateValidation(dateOfBirthTarget);
    printf("Congrats! Your Date of Birth has been Verified!");

    return 0;
};



//Function To Register User's Email Address
//Data Validation: To Validete If the Email Input Contain '@' and '.com'
int register_email(char *emailTarget)
{
    char email[321];
    printf("\n--------------------------------------------------------------------------");
    while(1) {
        fflush(stdin);
        printf("\n\nPlease Enter Your Email:\n");
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


//Login Page for Both User and Admin
//Data Validation: To Validate Username and Password Input From the User is Correct
Account loginUser() {
    int found = 0;

    printf("\n\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\n\n\t\t\t   Login Page\n\n");
    printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    printf("\nPlease Enter Your Login Credentials Below:\n\n");

    do {
        char username[256], password[256];    
        Account user;
        FILE *userFileReader;
        userFileReader = checkFileExistence("user.txt", "r", 0);    
        fflush(stdin);
        printf("Username:\t");
        scanf("%[^\n]s", username);
        toLower(username);

        fflush(stdin);
        printf("\nPassword:\t");
        scanf("%[^\n]s", password);

        while(fread(&user, sizeof(Account), 1, userFileReader)) {
            toLower(user.username);
            if ((strcmp(user.username, username) == 0) && (strcmp(user.password, password) == 0)) {
                printf("\nWelcome back, %s!", user.name); 
                fclose(userFileReader);
                found = 1;
                return user;
            };
        };
        if (!found) {
            printf("\nIncorrect Login Details\nPlease enter the correct credentials!\n");
        };
    } while (!found);
    
};

//Function to Change Password
int changePassword(char *username, char *password) {
    Account user;
    char confirmPassword[256], *newPassword;
    FILE *userFileReader, *userFileWriter;
    userFileReader = checkFileExistence("user.txt", "r", 0); 
    userFileWriter = fopen("temp_user.txt", "w");
    int passwordCorrect, found = 0;
    
    do {
        fflush(stdin);
        printf("\nPlease Enter Your Current Password:\t");
        scanf("%[^\n]s", confirmPassword);
        if (strcmp(confirmPassword, password) == 0) {
            passwordCorrect = 1;
            break;
        } else {
            printf("\nIncorrect Password! Please Try Again!");
            continue;
        };
    } while (!passwordCorrect);
    

    fflush(stdin);
    register_password(newPassword);
    scanf("%[^\n]s", newPassword);
    
    while(fread(&user, sizeof(Account), 1, userFileReader)) {
        if (strcmp(user.username, username) == 0) {
            strcpy(user.password, newPassword); 
        };
        fwrite(&user, sizeof(Account), 1, userFileWriter);
    };
    fclose(userFileReader);
    fclose(userFileWriter);
    printf("\nDone!\n");
    remove("user.txt");
    rename("temp_user.txt", "user.txt");
    
    return 0;
};

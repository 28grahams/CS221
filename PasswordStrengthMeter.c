//
// Created by Theodore Graham on 10/11/19.
//
// PASSWORD STRENGTH METER

#include <stdio.h>
#include <string.h>

typedef int bool;
#define false 0
#define true 1

int characters, uCase=0, lCase=0, numb=0;

bool isStrongPassword(const char* username, const char* password){
    const char *pwPtr = password;
    unsigned long passwordLen = strlen(password);
    if (passwordLen <= 8){
        printf("Password must contain at least eight characters.\n");
        characters = 1;
    }
    while (*pwPtr != '\0') {
        if (*pwPtr >= 'A' && *pwPtr <= 'Z'){
            uCase++;
        }
        if (*pwPtr >=  'a' && *pwPtr <= 'z') {
            lCase++;
        }
        if (*pwPtr >=  '0' && *pwPtr <= '9') {
            numb++;
        }
        pwPtr++;

    }
    if (uCase == 0){
        printf("Password must contain at least one uppercase letter.\n");
    }
    if (lCase == 0){
        printf("Password must contain at least one lowercase letter.\n");
    }
    if (numb == 0){
    printf("Password must contain at least one number.\n");
    }
    if ((characters+uCase+lCase+numb) < 3) {
        printf("Enter a password fulfilling the requirements.\n");
    }
    // if (string =< 4) lowercase/uppercase/numbers

    // if (doesn't contain username)
    return false;
}

int main(void){
    char username[] = {""};
    char password[] = {""};
    printf("Enter username:\n");
    scanf("%s", username);
    printf("Enter new password:\n");
    scanf("%s", password);
    isStrongPassword(username, password);
    return 0;
}


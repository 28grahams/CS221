//
// Created by Theodore Graham on 10/11/19.
//
// PASSWORD STRENGTH METER

#include <stdio.h>
#include <string.h>
//#include <stdbool.h>
// can't get stdbool.h to work

typedef int bool;
#define false 0
#define true 1

bool isStrongPassword(const char* username, const char* password){
    int uCase=0, lCase=0, numb=0, consecLC=0, consecUC=0, consecN=0;
    const char *pwPtr = password;
    const char *pwPtr2 = password;
    unsigned long passwordLen = strlen(password);

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
    for (unsigned long i=0; i < passwordLen; i++) {
        if (*(pwPtr2+i) >= 'A' && *(pwPtr2+i) <= 'Z'){
            if ((*(pwPtr2+i+1) >= 'A' && *(pwPtr2+i+1) <= 'Z') && (*(pwPtr2+i+2) >= 'A' && *(pwPtr2+i+2) <= 'Z')&& (*(pwPtr2+i+3) >= 'A' && *(pwPtr2+i+3) <= 'Z')){
                consecUC++;
            }
        }
        if (*(pwPtr2+i) >= 'a' && *(pwPtr2+i) <= 'z'){
            if ((*(pwPtr2+i+1) >= 'a' && *(pwPtr2+i+1) <= 'z') && (*(pwPtr2+i+2) >= 'a' && *(pwPtr2+i+2) <= 'z')&& (*(pwPtr2+i+3) >= 'a' && *(pwPtr2+i+3) <= 'z')){
                consecLC++;
            }
        }
        if (*(pwPtr2+i) >= 'A' && *(pwPtr2+i) <= 'z'){
            if ((*(pwPtr2+i+1) >= 'A' && *(pwPtr2+i+1) <= 'z') && (*(pwPtr2+i+2) >= 'A' && *(pwPtr2+i+2) <= 'z')&& (*(pwPtr2+i+3) >= 'A' && *(pwPtr2+i+3) <= 'z')){
                consecN++;
            }
        }
    }
    if (passwordLen <= 8){
        printf("Password must contain at least eight characters.\n");
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
    if (((consecLC==0) || (consecUC==0)) && (consecN==0)){
        printf("Password must have 4 uppercase, lowercase, or numbers in a row");
    }
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


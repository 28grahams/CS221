//
// Created by Theodore Graham on 10/11/19.
//
// PASSWORD STRENGTH METER

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
//#include <stdbool.h>
// can't get stdbool.h to work

typedef int bool;
#define false 0
#define true 1

bool isStrongPassword(const char* username, const char* password){
    int uCase=0, lCase=0, numb=0, consec=0, success=0, specChar=0;
    const char *pwPtr = password, *pwPtr2 = password, *pwPtr3 = password, *unPtr = username;
    unsigned long passwordLen = strlen(password);

    while (*pwPtr != '\0') { // Validates whether there's at least 1 number, uppercase, and lowercase character
        if (*pwPtr >= 'A' && *pwPtr <= 'Z') {
            uCase++;
        }
        if (*pwPtr >= 'a' && *pwPtr <= 'z') {
            lCase++;
        }
        if (*pwPtr >= '0' && *pwPtr <= '9') {
            numb++;
        }
        pwPtr++;
    }
    for (unsigned long i=0; i < passwordLen; i++) { // Validates whether password string has four in a row of uppercase or lowercase letters
        if (*(pwPtr2 + i) >= 'A' && *(pwPtr2 + i) <= 'z') {
            if ((*(pwPtr2 + i + 1) >= 'A' && *(pwPtr2 + i + 1) <= 'z') &&
                (*(pwPtr2 + i + 2) >= 'A' && *(pwPtr2 + i + 2) <= 'z') &&
                (*(pwPtr2 + i + 3) >= 'A' && *(pwPtr2 + i + 3) <= 'z')) {
                consec++;
            }
        }
    }
    for (unsigned long i=0; i < passwordLen; i++) {
        if(*(pwPtr3+i) >= '0' && *(pwPtr3+i) <= 'z'){
            specChar++;
        }
    }
    printf("Password requirements:\n");

    if (specChar !=0){ // Validates no special characters
        printf("[ ] No special characters\n");
    }
    else{
        printf("[\xE2\x9C\x93] No special characters \n");
        success++;
    }
    if (passwordLen < 8){ // Validates password length is at least 8 characters
        printf("[ ] Eight characters\n");
    }
    else{
        printf("[\xE2\x9C\x93] Eight characters \n");
        success++;
    }
    if (uCase == 0){
        printf("[ ] One uppercase letter\n");
    }
    else {
        printf("[\xE2\x9C\x93] One uppercase letter\n");
        success++;
    }
    if (lCase == 0){
        printf("[ ] One lowercase letter\n");
    }
    else {
        printf("[\xE2\x9C\x93] One lowercase letter\n");
        success++;
    }
    if (numb == 0){
        printf("[ ] One number\n");
    }
    else {
        printf("[\xE2\x9C\x93] One number\n");
        success++;
    }
    if (consec==0){
        printf("[ ] Four letters in a row\n");
    }
    else{
        printf("[\xE2\x9C\x93] Four letters in a row\n");
        success++;
    }
    if (strcmp(username, password)==0){ // Validation for password containing usernames
        printf("[ ] Password doesn't contain username\n");
    }
    else{
        printf("[\xE2\x9C\x93] Password doesn't contain username \n");
        success++;
    }
    if (success>=6){
        return true;
    }
    else {
        return false;
    }
}
char randN(void){
    srand(time(0));
    char randomN = '0' + (rand() % 10);
    return randomN;
}
char randUC(void){
    srand(time(0));
    char randomUC = 'A' + (rand() % 26);
    return randomUC;
}
char randLC(void){
    srand(time(0));
    char randomLC = 'a' + (rand() % 26);
    return randomLC;
}
int randNum(void){
    srand(time(0));
    int randNum = (rand() % 3);
    return randNum;
}
char generateDefaultPassword(const char* username, const char* password){
    char randPassword[20] = {""};
    srand(time(NULL));
    int randLen = (rand() % 7);
    randLen+=8;
    for (int i=0; i<randLen; i++) {
        int randNum = (rand() % 3);
        int choice = randNum;
        if (choice == 0) {
            char rand1 = '0' + (rand() % 10);
            printf("%c",rand1);
            randPassword[i] = rand1;
        }
        if (choice == 1) {
            char rand2 = 'a' + (rand() % 26);
            printf("%c",rand2);
            randPassword[i] = rand2;
        }
        if (choice == 2) {
            char rand3 =  'A' + (rand() % 26);
            printf("%c",rand3);
            randPassword[i] = rand3;
        }
    }
    return randPassword;
}

int main(void){
    char username[20] = {""};
    char password[20] = {""};
    printf("Enter username:\n");
    scanf("%s", username);
    printf("Enter new password:\n");
    scanf("%s", password);
    printf("%d\n", isStrongPassword(username, password));
    printf("s", generateDefaultPassword(username, password));
    return 0;
}
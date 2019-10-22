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
    for (unsigned long i=0; i < passwordLen; i++) { // Validates whether special characters are contained
        if((*(pwPtr3+i) <= 47) ||
           (*(pwPtr3+i) >= 58 && *(pwPtr3+i) <= 64) ||
           (*(pwPtr3+i) >= 91 && *(pwPtr3+i) <= 96) ||
           (*(pwPtr3+i) >= 123)){
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
        printf("[ ] Doesn't contain username\n");
    }
    else{
        printf("[\xE2\x9C\x93] Doesn't contain username \n");
        success++;
    }
    if (success>=6){
        printf("Strong password!\n\n");
        return true;
    }
    else {
        printf("Your password is weak. Try again!\n\n");
        return false;
    }
}

void generateDefaultPassword(const char* default_password, const char* username){
    printf("Generating a default password. . .\n");
    char randPassword[20] = {""};
    srand(time(NULL));
    int randLen = (rand() % 7); // For some reason this always is 15, but the way it's coded there shouldn't be a problem I believe
    randLen+=8;
    for (int i=0; i<randLen; i++) { // For as long as the password length is randomly chosen to be,
                                    // this for loop randomly chooses between numbers/uppercase/lowercase characters
        int randNum = (rand() % 3);
        int choice = randNum;
        if (choice == 0) {
            char rand1 = '0' + (rand() % 10); //random digit
            randPassword[i] = rand1;
        }
        if (choice == 1) {
            char rand2 = 'a' + (rand() % 26); //random lowercase letter
            randPassword[i] = rand2;
        }
        if (choice == 2) {
            char rand3 =  'A' + (rand() % 26); // random uppercase letter
            randPassword[i] = rand3;
        }
    }
    printf("Generated default password: %s\n", randPassword);
    int uCase=0, lCase=0, numb=0, consec=0, success=0, specChar=0;
    const char *pwPtr = randPassword, *pwPtr2 = randPassword, *pwPtr3 = randPassword, *unPtr = username;
    unsigned long passwordLen = strlen(randPassword);

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
    for (unsigned long i=0; i < passwordLen; i++) { // Validates whether special characters are contained
        if((*(pwPtr3+i) <= 47) ||
           (*(pwPtr3+i) >= 58 && *(pwPtr3+i) <= 64) ||
           (*(pwPtr3+i) >= 91 && *(pwPtr3+i) <= 96) ||
           (*(pwPtr3+i) >= 123)){
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
    if (strcmp(username, randPassword)==0){ // Validation for password containing usernames
        printf("[ ] Doesn't contain username\n");
    }
    else{
        printf("[\xE2\x9C\x93] Doesn't contain username \n");
        success++;
    }
    if (success>=6){
        printf("Strong password!\n");
    }
    else {
        printf("Your password is weak. Try again!\n");
    }
}

int main(void){
    char username[20] = {""};
    char password[20] = {""};
    printf("Enter username:\n");
    scanf("%s", username);
    printf("Enter new password:\n");
    scanf("%s", password);
    isStrongPassword(username, password);
    generateDefaultPassword(password, username);
    return 0;
}
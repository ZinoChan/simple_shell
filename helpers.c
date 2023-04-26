#include "shell.h"

char* intToString(int num) {
    int i = 0, j = 0, isNeg = 0, digitCount = 0, temp;
    char* str;

    if (num < 0) {
        isNeg = 1;
        num *= -1;
        digitCount++;
    }
    temp = num;
    while (temp > 0) {
        digitCount++;
        temp /= 10;
    }

    str = (char*)malloc(sizeof(char) * (digitCount + 1));


    do {
        str[i++] = (num % 10) + '0';
        num /= 10;
    } while (num);


    if (isNeg) {
        str[i++] = '-';
    }

    j = i - 1;
    i = 0;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }


    str[digitCount] = '\0';

    return str;
}






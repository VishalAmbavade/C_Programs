#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replaceSpaces(char str[]) {
    int n = strlen(str);
    for(int i = 0; i < n; i++) {
        if(str[i] == ' ') {
            str[i] = '%';
            str[i + 1] = '2';
            str[i + 2] = '0';
        } else {
            str[i] = str[i];
        }
    }
    return str;
}

int main() {
    char str[] = "Mr Vishal Ambavade";
    printf("%s", replaceSpaces(str));
    return 0;
}
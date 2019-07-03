#include <stdio.h>
#include <string.h>
#define MAX 50

void printString(int n) {
    char str[MAX];
    int i = 0;

    while(n > 0) {
        int rem = n % 26;
        if(rem == 0) {
            str[i++] = 'Z';
            n = (n / 26) - 1;
        } else {
            str[i++] = (rem - 1) + 'A';
            n = n / 26;
        }
    }
    str[i] = '\0';

    //strrev(str, str + strlen(str));
    strrev(str);
    printf("%s", str);
    return;
}

int main() {
    printString(705);
    return 0;
}
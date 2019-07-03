#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(char str[]) {
    int n = strlen(str);
    for(int i = 0; i < n; i++) {
        int count = 1;
        while(i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }
        printf("%c%d", str[i], count);
    }
}

int main() {
    char str[] = "wwwwaaadexxxxxxywww";
    encode(str);
    return 0;
}
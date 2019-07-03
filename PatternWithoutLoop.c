#include <stdlib.h>
#include <stdio.h>

void printPattern(int n) {
    if(n == 0 || n < 0) {
        printf("%d ", n);
        return;
    }
    printf("%d ", n);
    printPattern(n - 5);
    printf("%d ", n);
}

int main() {
    int n = 16;
    printPattern(n);
    return 0;
}
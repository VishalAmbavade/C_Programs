#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if(n == 0)
        return 0;
    while(n != 1) {
        if(n % 2 != 0)
            return 0;
        n = n / 2;
    }
    return 1;
}

int main() {
    isPowerOfTwo(128) ? printf("Yes") : printf("No");
    return 0;
}
#include <stdio.h>
#include <stdbool.h>

bool isKthBitSet(long x, unsigned int k) {
    return (x & (1 << (k - 1))) ? true : false;
}

bool isPalindrome(long x) {
    int l = 1;
    int r = sizeof(unsigned int) * 8;
    while(l < r) {
        if(isKthBitSet(x, 1) != isKthBitSet(x, r))
            return false;
        l++, r--;
    }
    return true;
}

int main() {
    long x = 1 << 15 + 1 << 16;
    int y = isPalindrome(x);
    printf("%d", y);
    return 0;
}
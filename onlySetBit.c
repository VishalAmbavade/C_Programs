#include <stdio.h>

int isPowerOfTwo(unsigned n) {
    return n && (!(n & (n - 1)));
}

int findPosition(unsigned n) {
    if(!isPowerOfTwo(n))
        return -1;
    unsigned i = 1, pos = 1;

    while(!(i &n)) {
        i = i << 1;
        pos++;
    }
    return pos;
}
int main() {
    int n = 16;
    int pos = findPosition(n);
    (pos == -1)? printf("Invalid no.") : printf("Position: %d", pos);
    return 0;
}
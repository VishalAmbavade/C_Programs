/*#include <stdio.h>

void bin(unsigned n) {
    unsigned i;
    for(i = 1 << 31; i > 0; i = i / 2) {
        (n & i)? printf("1"): printf("0");
    }
}

int main() {
    bin(7);
    return 0;
}*/

/*Method II* : Recursive*/

/*#include<stdio.h>
void bin(unsigned n) {
    if(n > 1)
        bin(n / 2);
    printf("%u", (n % 2));
}
int main() { 
    bin(7);
    return 0;
}*/

/*Method III : Recursive using Bitwise Operator*/

#include <stdio.h>
void bin(unsigned n) {
    if(n > 1)
        bin(n >> 1);
    printf("%u", n & 1);
}

int main() {
    bin(7);
    return 0;
}
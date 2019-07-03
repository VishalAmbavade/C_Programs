#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    //printf("Enter m: ");
    //scanf("%d", &m);
    m = 6;
    n = -15;
    if(m == 0) {
        exit(1);
    }
    //printf("Enter n: ");
    //scanf("%d", &n);

    int q, res;
    q = n / m;
    printf("%d \n", q);

    if(n * m >= 0) {
        res = q * m;
    } else if(n < 0 && q > 0) {
        res = (q - 1) * m;
    } else {
        res = (q - 1) * m;
    }
    printf("Closest Value: %d", res);
    return 0;
}
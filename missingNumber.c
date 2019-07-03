#include <stdio.h>

int missing(int arr[], int n) {
    int i, total;
    total = (n + 1) * (n + 2) / 2;
    for(i = 0; i < n; i++) {
        total -= arr[i];
    }
    return total;
}
int main() {
    int arr[] = {1, 2, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int miss = missing(arr, n);
    printf("%d", miss);
    return 0;
}
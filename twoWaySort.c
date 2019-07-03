#include <stdio.h>
#include <stdlib.h>

void twoWaySort(int arr[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] & 1) {
            arr[i] *= -1;
        }
    }
    qsort(arr, arr + n);
    for(int i = 0; i < n; i++) {
        if(arr[i] & 1) {
            arr[i] *= -1;
        }
    }
}

int main() {
    int arr[] = {5, 4, 7, 8, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    twoWaySort(arr, n);
    return 0;
}
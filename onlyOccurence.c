/*#include <stdio.h>
#define INT_SIZE 32

int getSingle(int arr[], int n) {
    int result = 0;
    int x, sum;

    for(int i = 0; i < INT_SIZE; i++) {
        sum = 0;
        x = (1 << i);
        for(int j = 0; j < n; j++) {
            if(arr[j] & x) {
                sum++;
            }
        }
        if(sum % 3) {
            result |= x;
        }
    }
    return result;
}

int main() {
    int arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 2, 2, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", getSingle(arr, n));
    return 0;
}*/

#include <stdio.h>
#define int_size 32

int getSIngle(int arr[], int n) {
    int result = 0;
    int x, sum;

    for(int i = 0; i < int_size; i++) {
        sum = 0;
        x = (1 << i);
        for(int j = 0; j < n; j++) {
            if(arr[j] & x) {
                sum++;
            }
        }
        if(sum % 3) {
            result |= x;
        }
    }
    return result;
}
int main() {
    int arr[] = {12, 1, 12, 3, 4, 1, 3, 4, 1, 12, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", getSIngle(arr, n));
    return 0;
}
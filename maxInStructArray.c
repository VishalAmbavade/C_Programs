#include <stdio.h>
#include <limits.h>

struct Height
{
    int feet;
    int inches;
};

int findMax(struct Height arr[], int n) {
    int mx = INT_MIN;
    for(int i = 0; i < n; i++) {
        int temp = 12 * (arr[i].feet) + (arr[i].inches);
        if(temp > mx) {
            mx = temp;
        }
    }
    return mx;
}
int main() {
    struct Height arr[] = {{1, 3}, {10, 10}, {6, 8}, {3, 7}, {5, 9}}; 
    int res = findMax(arr, 5);
    printf("%d", res);
    return 0;
}

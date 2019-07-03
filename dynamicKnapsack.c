#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int i, weigh;
    int k[n + 1][W + 1];

    for(i = 0; i <= n; i++) {
        for(weigh = 0; weigh <= W; weigh++) {
            if(i == 0 || weigh == 0)
                k[i][weigh] = 0;
            else if(wt[i - 1] <= weigh)
                k[i][weigh] = max(val[i - 1] + k[i - 1][weigh - wt[i - 1]], k[i - 1][weigh]);
            else
                k[i][weigh] = k[i - 1][weigh];
        }
    }
    return k[n][W];
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("%d", knapsack(W, wt, val, n));
    return 0;
}
#include <bits/stdc++.h>
#define R 4
#define C 4
using namespace std;

int rowWithMaxOnes(bool mat[R][C]) {
    int i, index;

    int max_row_index = 0;
    int max = first(mat[0], 0, C - 1);

    for(i = 1; i < R; i++) {
        if(max != -1 && mat[i][C - max - 1] == 1) {
            index = first(mat[i], 0, C - max);

            if(index != - 1 && C - index > max) {
                max = C - index;
                max_row_index = i;
            }
        } else {
            max = first(mat[i], 0, C - 1);
        }
    }
    return max_row_index;
}

int main() {
    bool mat[R][C] = { {0, 0, 0, 1},
                       {0, 1, 1, 1},
                       {1, 1, 1, 1},
                       {0, 0, 0, 0}};
    cout << "Index of row with max: " << rowWithMaxOnes(mat);
    return 0;
}
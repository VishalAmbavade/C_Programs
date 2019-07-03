#include <stdio.h>
#include <stdbool.h>

struct Point {
    int x, y;
};

bool overlap (struct Point l1, struct Point r1, struct Point l2, struct Point r2) {
    if(l1.x > r2.x || l2.x > r1.x) {
        return false;
    }
    if(l1.y < r2.y || l2.y < r1.y) {
        return false;
    }
    return true;
}
int main() {
    struct Point l1 = {0, 2}, r1 = {2, 0};
    struct Point l2 = {4, 3}, r2 = {6, 2};
    if(overlap(l1, r1, l2, r2)) {
        printf("Rectangles Overlap");
    } else {
        printf("Rectangles don't overlap");
    }
    return 0;
}
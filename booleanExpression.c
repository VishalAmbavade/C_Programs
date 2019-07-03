#include <stdio.h>
#include <string.h>

int evaluateBoolExpr(char s[]) {
    int n = strlen(s);

    for(int i = 0; i < n; i += 2) {
        if(s[i + 1] == 'A') {
            if(s[i] == '0' || s[i + 2] == '0')
                s[i + 2] = '0';
            else
                s[i + 2] = '1';
        }
        else if(s[i + 1] == 'B') {
            if(s[i] == '1' || s[i + 2] == '1')
                s[i + 2] = '1';
            else
                s[i + 2] = '0';
        }
        else {
            if(s[i + 2] == s[i])
                s[i + 2] = '0';
            else
                s[i + 2] = '1';
        }
    }
    return s[n - 1] - '0';
}

int main() {
    char s[] = "1C1B1B0A0";
    printf("%d", evaluateBoolExpr(s));
    return 0;
}
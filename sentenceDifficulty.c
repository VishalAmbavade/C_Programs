#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isVowel(char ch) {
    return(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
} 

int calcDiff(char str[]) {
    int countVowels = 0, countCons = 0;
    int hardWords = 0, easyWords = 0;
    int consecCons = 0;

    for(int i = 0; i < strlen(str); i++) {
        if((*str + i) != ' ' && isVowel(tolower(str[i]))) {
            countVowels++;
            consecCons = 0;
        }
        else if(str[i] != ' '){
            countCons++;
            consecCons++;
        }
        if(consecCons == 4) {
            hardWords++;
            while(i < strlen(str) && str[i] != ' ')
                i++;
            countCons = 0;
            countVowels = 0;
            consecCons = 0;
        }
        else if(i < strlen(str) && (str[i] == ' ' || i == strlen(str) - 1)) {
            countCons > countVowels ? hardWords++ : easyWords++;

            countCons = 0;
            countVowels = 0;
            consecCons = 0;
        }
    }
    return 5 * hardWords + 3 * easyWords;
}
int main() {
    char str[] = "Philonthropist are great";
    int val = calcDiff(str);
    printf("%d", val);
    return 0;
}
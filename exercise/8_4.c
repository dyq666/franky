#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    bool flag;
    int ch;
    int letters = 0, words = 0;

    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            letters ++;
            flag = 1;
        }
        else {
            // `flag` 等于 1 代表上一个字符是字母, 0 代表上一个字符是空格.
            // 因此当 1 -> 0 时代表读完了一个单词了.
            if (flag == 1) {
                words ++;
            }
            flag = 0;
        }
    }
    
    if (words == 0) {
        printf("There are not words\n");
    }
    else {
        printf("average: %f\n", (double) letters / (double) words);
    }

    return 0;
}

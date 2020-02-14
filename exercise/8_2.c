#include <stdio.h>

int main(void) {
    int ch;
    int count = 0;

    while ((ch = getchar()) != EOF) {
        // 如果是 \n 则, 开启新的一行, 并重置 count.
        if (ch == '\n') {
            printf("\\n %d\n", ch);
            count = 0;
        } 
        else if (ch == '\t') {
            printf("\\t %d ", ch);
        }
        else if (ch <= ' ') {
            printf("^%c %d ", ch + 64, ch);
        }
        else {
            printf("%c %d ", ch, ch);
        }

        // 每读 10 个字符开启新行.
        count ++;
        if (count == 10) {
            printf("\n");
            count = 0;
        }
    }

    return 0;
}
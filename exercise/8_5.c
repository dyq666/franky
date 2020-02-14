#include <stdio.h>

void discard_chars(void);

int main(void) {
    int ch;
    int l = 0, r = 100;

    printf("Uh...is your number %d? (0: high, 1: low, 2: correct) \n", (l + r) / 2);
    ch = getchar();
    discard_chars();

    while (ch != '2') {
        if (ch == '0') {
            r = (l + r) / 2;
        }
        else {
            l = (l + r) / 2;
        }

        printf("Well, then, is it %d (0: high, 1: low, 2: correct) \n", (l + r) / 2);
        ch = getchar();
        discard_chars();
    }

    printf("I knew I could do it!\n");

    return 0;
}

void discard_chars(void) {
    /* 丢弃当前行所有字符. */
    while (getchar() != '\n') {
        ;
    }
}

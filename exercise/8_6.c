#include <ctype.h>
#include <stdio.h>

void discard_chars(void);

int main(void) {
    int ch;

    while (isspace(ch = getchar())) {
        ;
    }
    discard_chars();

    putchar(ch);

    return 0;
}

void discard_chars(void) {
    /* 丢弃当前行所有字符. */
    while (getchar() != '\n') {
        ;
    }
}

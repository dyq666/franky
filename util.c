#include <stdio.h>

void discard_chars(void);

int main(void){
    return 0;
}

void discard_chars(void) {
    /* 丢弃当前行所有字符. */
    while (getchar() != '\n') {
        ;
    }
}

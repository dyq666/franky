#include <stdio.h>
#define PROMPT "Please enter a char and a integer (newline to quit): "

int main(void) {
    int i, ch, times;

    printf("%s", PROMPT);
    while ((ch = getchar()) != '\n') {
        scanf("%d", &times);
        while (getchar() != '\n') {
            continue;
        }

        for (i = 0; i < times; i ++) {
            putchar(ch);
        }
        printf("\n");

        printf("%s", PROMPT);
    }

    return 0;
}

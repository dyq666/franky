#include <stdio.h>

int main(void) {
    int i, ch, times;

    printf("Please enter a char and a integer: ");
    while ((ch = getchar()) != '\n') {
        scanf("%d", &times);

        for (i = 0; i < times; i ++) {
            putchar(ch);
        }
        printf("\n");

        printf("Please enter a char and a integer (newline to quit): ");
    }

    return 0;
}

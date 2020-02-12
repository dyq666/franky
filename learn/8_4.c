#include <stdio.h>

int main(void) {
    int guess = 0;

    printf("Uh...is your number %d?\n", guess);
    while (getchar() != 'y') {
        printf("Well, then, is it %d\n", ++ guess);
    }

    printf("I knew I could do it!\n");

    return 0;
}

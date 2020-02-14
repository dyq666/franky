#include <ctype.h>
#include <stdio.h>

int main(void) {
    int ch;
    int lower_count = 0, upper_count = 0, other_count = 0;

    while ((ch = getchar()) != EOF) {
        if (islower(ch)) {
            lower_count ++;
        }
        else if (isupper(ch)) {
            upper_count ++;
        }
        else {
            other_count ++;
        }
    }

    printf("lower: %d, upper: %d, other: %d\n", lower_count, upper_count, other_count);

    return 0;
}

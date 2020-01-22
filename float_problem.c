// 大浮点数会遇到的一些问题.

#include <stdio.h>

int main(void) {
    float overflow = 3.4E38 * 100.0f,
          big = 2.0e20 + 1.0;

    printf("The value of `overflow` is too large, so it display: '%f'\n", overflow);
    printf("The value of `big` is too large, so the result of minus is not 1.0, real is: %f\n", big - 2.0e20);

    return 0;
}

#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>

void discard_chars(void);
long get_long(void);
long sum_squares(long a, long b);

int main(void) {
    // 和书上不太一样的是这里少了个 0, 因为按书上的数值 sum_squares 中计算的值大于 long (8 bytes) 了. 
    const long MIN = -1000000L, MAX = 1000000L;
    long start, stop, answer;

    start = get_long();
    stop = get_long();

    while (start != 0 or stop != 0) {
        if (start > stop or start < MIN or start > MAX
                or stop < MIN or stop > MAX) {
            printf("Try again.\n");
        } 
        else {
            answer = sum_squares(start, stop);
            printf("The answer is %ld\n", answer);
        }

        start = get_long();
        stop = get_long();
    }
    printf("Bye!\n");

    return 0;
}

void discard_chars(void) {
    /* 丢弃当前行所有字符. */
    while (getchar() != '\n') {
        ;
    }
}

long get_long(void) {
    /* 读取一个 `long`, 如果错误, 则让用户重复输入. */
    long input;

    printf("Please enter an integer: ");
    while (scanf("%ld", &input) != 1) {
        discard_chars();
        printf("Please enter an integer: ");
    }
    discard_chars();

    return input;
}

long sum_squares(long a, long b) {
    long i;
    long total = 0;

    for (i = a; i < b + 1; i ++) {
        total += i * i;
    }

    return total;
}

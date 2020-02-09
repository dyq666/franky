// p190 和 p192 代码的组合, 一种通用的 `scanf` + `while` 的使用方式.

#include <stdio.h>

#define PROMPT "Please enter an integer to be summed (q to quit): "

int main(void) {
    long num;
    long sum = 0L;

    printf(PROMPT);
    // 当 `scanf` 返回 1 时, 代表输入内容是一个整数 (更准确的说是输入内容与 `%ld` 匹配).
    // 当 `scanf` 返回 0 时, 代表输入内容不与 `%ld` 匹配, 例如字符 q.
    // 当 `scanf` 返回 -1 时, 代表出现其他情况, 这个 -1 实际上是 EOF.
    while (scanf("%ld", &num) == 1) {
        sum += num;
        printf(PROMPT);
    }

    printf("Those integer sum to %ld\n", sum);

    return 0;
}

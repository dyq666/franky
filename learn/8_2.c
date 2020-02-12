#include <stdio.h>

int main(void) {
    int ch;

    // 第一次 Ctrl + D 会触发输出缓存的内容, 第二次 Ctrl + D 才传递 EOF.
    // 也可以说, 只有缓存中没有内容时, Ctrl + D 才会传递 EOF. 
    // 书上的也是说明需要在行的开头使用 Ctrl + D.
    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }

    return 0;
}

/* 第八章笔记.
1. 最初输入输出相关的函数并不是 C 标准定义的, 而是有具体的实现完成. 因而有许多相关的函数, 其中
   某些函数只能用于特定的系统. 文件和输入输出同理.
2. 虽然一次读很多字符也是很简单的, 但读一个字符 (`getchar`) 更贴近于计算机底层.
3. 输入分为 unbuffered, lined-buffered, fully-buffered.
   C 语言标准库中不提供 unbuffered, 这个功能够依赖于具体的操作系统.
   lined-buffered 通常用于键盘输入, 当遇到 \n 时, buffered 的内容将清空.
   fully-buffered 通常用于文件, 当 buffer 的内容满了之后再清空.
4. C 语言标准库中用统一的方法处理不同系统的输入输出, 并且将键盘, 各种设备, 文件
   都用统一的流的方式就行处理. 例如跟键盘和屏幕相关的流叫做 stdin, stdout.
5. 文件需要一个方式告知系统到末尾了. 古老的方式是用一个字符标记末尾, 现在是计算字节数,
   当字节都读完了就相当于到末尾了. C 语言会返回一个常量 `EOF` 标记到末尾, 因此输入流
   也需要统一的 `EOF` 处理.
*/

#include <stdio.h>

void discard_chars(void);
int get_int(void);

int main(void){
    return 0;
}

void discard_chars(void) {
    /* 丢弃当前行所有字符. */
    while (getchar() != '\n') {
        ;
    }
}

int get_int(void) {
    /* 读取一个整数, 如果错误, 则让用户重复输入. 
    可以作为读取其他类型的参考, 需要注意的是在使用 `scanf` 后, 要合理的清除 stream 中剩余的字符.    
    */
    int input;

    printf("Please enter an integer: ");
    while (scanf("%d", &input) != 1) {
        discard_chars();
        printf("Please enter an integer: ");
    }
    discard_chars();

    return input;
}

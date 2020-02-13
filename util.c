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


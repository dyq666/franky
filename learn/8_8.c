#include <iso646.h>
#include <stdio.h>

void count();
void discard_chars(void);
int get_choice(void);
int get_int(void);

int main(void) {
    int choice;

    while ((choice = get_choice()) != 'q') {
        switch (choice) {
            case 'a': printf("Buy low, sell high.\n");
                      break;
            case 'b': putchar('\a');
                      break;
            case 'c': count();
                      break;
            defaut:   printf("Program error!\n");
                      break;
        }
    }
    printf("Bye!\n");

    return 0;
}

void count() {
    /* 从 1 开始数数. */
    int i, input;

    input = get_int();

    for (i = 1; i < input + 1; i ++) {
        printf("%d\n", i);
    }
}

void discard_chars(void) {
    /* 丢弃当前行所有字符. */
    while (getchar() != '\n') {
        ;
    }
}

int get_choice(void) {
    /* 提供一个 menu, 并且只返回 menu 中的合法选项 */ 
    int ch;

    printf("Enter the letter of your choice:\n"
           "a. advice             b. bell\n"
           "c. count              q. quit\n");
    
    ch = getchar();
    discard_chars();
    while ((ch < 'a' or ch > 'c') and ch != 'q') {
        printf("Please respond with a, b, c, q: ");
        ch = getchar();
        discard_chars();
    }

    return ch;
}

int get_int(void) {
    /* 读取一个整数, 如果错误, 则让用户重复输入. */
    int input;

    printf("Please enter an integer: ");
    while (scanf("%d", &input) != 1) {
        discard_chars();
        printf("Please enter an integer: ");
    }
    discard_chars();

    return input;
}

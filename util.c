#include "util.h"

void discard_rest_input_line(void) {
    /* 丢弃当前行所有剩余字符 */
    while (getchar() != '\n')
        continue;
}

int get_first(void) {
    /* 返回一行中的第一个字符, 并丢弃剩下所有字符. */
    int ch = getchar();
    discard_rest_input_line();
    return ch;
}

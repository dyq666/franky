#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

void clean_list_node(ListNode * node);
int compare_int(const void *a, const void *b);
void discard_chars(void);
int get_int(void);
void print_int_array(const int array[], const int count);
void print_list_node(const ListNode * node);

void clean_list_node(ListNode * node) {
    /* 清理动态分配给链表的内存. */
    ListNode *clean;
    while (node != NULL) {
        clean = node;
        node = node -> next;
        free(clean);
    }
}

int compare_int(const void *a, const void *b) {
    /* 用于 `qsort` 中升序排序 int. (本函数可作为其他类型的参考)

    函数参考: https://devdocs.io/c/algorithm/qsort#Example

    此外函数不能简化为 `return aa - bb;`, 因为当 bb 是最小的负整数且 aa 是一个整数时,
    aa - bb 将超过最大整数, 变为一个负数, 导致 aa < bb.
    */
    const int *aa = a;
    const int *bb = b;

    if (*aa < *bb) {
        return -1;
    } else if (*aa > *bb) {
        return 1;
    }
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

void print_int_array(const int array[], const int count) {
    /* 按如下格式打印整数数组. (本函数可作为其他类型的参考)
    ```
    array = [
        0, 1, 2, 3, 4, 5,
        6, 7, ...
    ]
    ```
    */
    printf("array = [");
    for (int i = 0; i < count; i ++) {
        if (i % 6 == 0) {
            printf("\n    ");
        }
        printf("%d, ", array[i]);
    }
    puts("\n]");
}

void print_list_node(const ListNode * node) {
    /* 打印链表. */
    int i = 0;
    while (node != NULL) {
        if (i != 0) {
            printf(" -> ");
        }
        printf("%d", node -> val);

        node = node -> next;
        i ++;
    }
    putchar('\n');
};

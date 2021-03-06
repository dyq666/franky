# Chapter 8 Input / Output and Input Validation

## stream 与 EOF

在 C 中, 所有输入输出都会转为 stream 提供给程序员, 例如 C 程序运行时会自动创建 stdin, stdout 用于和终端交互, 打开文件时, C 也会创建一个 stream 关联到该文件.

EOF (end of file) 标记了 stream 的终止位置. 

对于终端来说, 类 Unix 系统在一行的开头输入 Ctrl+D 来标记终止位置, 此时就可以从 stdin 中读取到 EOF.

```c
/* 编号: 1
   功能: 一个使用 EOF 简单的例子 */
#include <stdio.h>
int main(void) {
    // 这里使用 int 而不是 char 的原因如下:
    // 1. EOF 的值通常为 -1, 而 char 在规范中没有说明必须是 signed char, 因而也能是 unsigned char, unsigned char 类型无法表达 -1.
    // 2. getchar 的返回值就是 int. 因而使用 int 是百分百没错的.
    int ch;
    while ((ch = getchar()) != EOF)
        putchar(ch);
    return 0;
}
```

对于文件来说, 有两种常见的方式标记终止位置. 第一种, 在终止位置放置特殊字符 (例如 Ctrl+Z). 第二种, 比较已读取的字节和文件本身的字节. 前者是较老的方法, 后者是目前操作系统常用的方式. 无论哪种方式, 都可以在 C 中的相关函数中读取到 EOF.

## 重定向 stdin / stdout

在 **编号 1 代码** 中, `getchar` 和 `putchar` 分别使用 stdin 和 stdout, 而 stdin / stdout 默认对应终端输入输出. 而操作系统为我们提供了重定向 stdin / stdout 的方法.

假设现在有一个文件 word.txt, **编号 1 代码** 编译后的文件叫 out.o. 那么 `./out.o < word.txt` 就会把 stdin 重定向到 word.txt, 最终结果就是终端上显示 word.txt 中的内容.

而 `./out.o > word.txt` 则会把 stdout 重定向到 word.txt, 最终结果就是终端中输入的内容存到文件中. 注意重定向 stdout 会覆盖文件内容, 这个操作第一步就是清空 word.txt 的内容!

`./out.o < word.txt > word_copy.txt` 则同时重定向了 stdin 和 stdout. 最终结果是将 word.txt 的内容复制到 word_copy.txt.

另外需要注意, 重定向功能是操作系统提供的功能, 并不是 C 的. 操作系统为可执行文件提供重定向功能, 编译后的 C 只是可执行文件的其中一个. 此外, 操作系统还为可执行文件提供 >>, | 等功能, 具体可参考 Unix 相关的书籍.

## buffered input

C 中标准库中的输入都是 buffered, 一个表现是在终端中只有敲 Enter 键时, 相关函数 (例如 getchar) 才会拿到数据.
例如下面是运行 **编号 1 代码** 的一个例子, 如果不是 buffered, 那么当敲下第一行 Apple 中的 A 时, 就应该立刻显示 A. 另一个表现是在敲 Enter 前, 你可以修改已经输入的内容.

```
/* 编号: 1 */
Apple!  // 这里敲下了 Enter
Apple!
// 这里敲下了 Ctrl+D
```

此外还需要注意的是敲 Enter 键同时会发送字符 '\n', 也就是实际输入内容是 `Apple!\n`, 而输出内容也是 `Apple!\n`. **编号 2 代码** 中同时显示字符对应的 ascii 编号, 这样就可以直观的看出所有字符, **编号 2 终端交互** 中展示了此案例, 其中 10 是 '\n' 的 ascii 编号.

```c
/* 编号: 2
   功能: 显示输出字符的 ascii 编号 */
#include <stdio.h>
int main(void) {
    int ch;
    while ((ch = getchar()) != EOF)
        printf("(%d)%c", ch, ch);
    return 0;
}
```

```
/* 编号: 2 */
Apple!  // 这里敲下了 Enter
(65)A(112)p(112)p(108)l(101)e(33)!(10)
// 这里敲下了 Ctrl+D
```

## 输入输出中常遇的问题

### 问题 1 Enter 键会输入 '\n' 字符, 有时候这个 '\n' 字符会比较讨厌.

**编号 3 代码** 中希望用户输入 y 代表猜对了, 输入 n 代表猜错了. 但如 **编号 3 终端交互** 所示, 当用户输入 n 时, 循环执行了两次, 因为实际上输入的内容是 `n\n`, 所以循环执行了两次.

```c
/* 编号: 3
   功能: 简易的猜数, 用于说明 Enter 键带来的问题 */
#include <stdio.h>
int main(void) {
    int guess = 1;
    printf("Enter y if my guess is right, otherwise enter n.\n");
    printf("It is %d?\n", guess);
    while (getchar() != 'y')
        printf("It is %d?\n", ++guess);
    printf("Bye!\n");
    return 0;
}
```

```
/* 编号: 3 */
Enter y if my guess is right, otherwise enter n.
It is 1?
n  // 这里敲下 Enter
It is 2?
It is 3?
y  // 这里敲下 Enter
Bye!
```

解决办法是每次只读取每行的第一个字符, 忽略剩下所有的字符, **编号 4 代码** 中 `get_first` 完成了这个功能. 如 **编号 4 终端交互** 所示, 可以正确的处理 n 了, 不过 no 也被当做了 n, yes 被当做了 y, 但通常来说这样已经足够用了.

```c
/* 编号: 4
   功能: 简易的猜数, 用于说明 Enter 键带来的问题 */
#include <stdio.h>
void discard_rest_input_line(void);
int get_first(void);
int main(void) {
    int guess = 1;
    printf("Enter y if my guess is right, otherwise enter n.\n");
    printf("It is %d?\n", guess);
    while (get_first() != 'y')
        printf("It is %d?\n", ++guess);
    printf("Bye!\n");
    return 0;
}
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
```

```
/* 编号: 4 */
Enter y if my guess is right, otherwise enter n.
It is 1?
n  // 这里敲下 Enter
It is 2?
no  // 这里敲下 Enter
It is 3?
yes  // 这里敲下 Enter
Bye!
```

### 问题 2 scanf 和 getchar 混用.

由于 scanf 会忽略空白字符 (space / tab / newline), 因而每行输入中后面的空白字符都会留在输入流中. 下面 **编号 5 终端交互** 是 **编号 5 代码** 的一个例子, 其中 32, 9, 10 分别是 space, tab, newline 的 ascii 码.

```c
/* 编号: 5
   功能: 说明混用 scanf 和 getchar 的结果 */
#include <stdio.h>
int main(void) {
    int ch, row, col;
    printf("Enter two number:");
    scanf("%d %d", &row, &col);
    printf("row: %d, col: %d\n", row, col);
    while ((ch = getchar()) != EOF)
        printf("(%d)%c", ch, ch);
    return 0;
}
```

```
/* 编号: 5 */
Enter two number:2 3  // 这里分别敲下了一个 Space, Tab 和 Enter
row: 2, col: 3
(32) (9)	(10)
// 这里敲下 Ctrl+D
```

解决办法和 **编号 4 代码** 中一样, 在 scanf 和 getchar 之间使用 `discard_rest_input_line` 清理 scanf 在输入流中遗留下来的字符.

### 问题 3 多个 scanf.

scanf 读取失败后, 会把读取的内容放回输入流中. 如 **编号 6 终端交互** 所示, 输入字符 a 没有匹配 scanf 中的 %d, 因而被放回输入流中, 下一次 getchar 就会读取这个字符.

```c
/* 编号: 6
   功能: scanf 读取失败时会把读取的内容放回输入流中 */
#include <stdio.h>
int main(void) {
    int i, ch;
    printf("Enter a integer:\n");
    printf("读取结果: %s\n", scanf("%d", &i) == 1 ? "成功" : "失败" );
    while ((ch = getchar()) != EOF)
        printf("(%d)%c", ch, ch);
    return 0;
}
```

```
/* 编号: 6
   说明: 编号 6 代码的一个例子 */
Enter a integer:
a  // 输入内容
读取结果: 失败
(97)a(10)
```

因而当使用多个 scanf, 尤其是在循环中使用时, 必须清理输入流中的内容. 如果不清理输入流的内容, 那么就会像 **编号 7 终端交互** 中一样无限循环, 只能用 Ctrl+c 强制终止程序, 原因就是字符 a 不能被 scanf 读取, 被留在输入流中, 然后下一个 scanf 又读取 a, 一直循环.

```c
/* 编号: 7
   功能: 使用 scanf 后, 清理输入流. 这里省略了 `discard_rest_input_line` 函数的定义*/
#include <stdio.h>
int main(void) {
    int i = -1;
    printf("Enter a integer:\n");
    while (scanf("%d", &i) != 1) {
        discard_rest_input_line();
        printf("Enter a integer:\n");
    }
    discard_rest_input_line();
    printf("i = %d\n", i);
    return 0;
}
```

```
/* 编号: 7
   说明: 注释掉编号 7 代码中的 `discard_rest_input_line` 后的一个例子 */
Enter a integer:
a  // 输入内容
Enter a integer:
Enter a integer:
Enter a integer:
Enter a integer:
^C  // 输入 Ctrl+C
```

# 数据类型

## 8, 16 进制

```c
/* 编号: 1
   说明: 8, 16 进制字面量以及 `printf` 中对应的描述符. */
#include <stdio.h>
int main(void) {
    // 10 进制, 8 进制, 16 进制, 16 进制
    int i1 = 16, i2 = 020, i3 = 0x10, i4 = 0X10;

    printf("decimal value of 4 vars: %d, %d, %d, %d\n", i1, i2, i3, i4);
    printf("decimal: %d, octal: %o, octal2: %#o, hexadecimal: %x, "
           "hexadecimal2: %#x, hexadecimal3: %#X\n", i1, i1, i1, i1, i1, i1);
    return 0;
}
```

```
/* 编号: 1 */
decimal value of 4 vars: 16, 16, 16, 16
decimal: 16, octal: 20, octal2: 020, hexadecimal: 10, hexadecimal2: 0x10, hexadecimal3: 0X10
```

## 超过数据结构范围的数据会循环

假设一个数据类型的范围是 0 - 127, 那么 127 + 1 后会循环到初始范围 0.

```c
/* 编号: 2
   说明: 超过数据范围的数会循环 */
#include <limits.h>
#include <stdio.h>
int main(void) {
    int i = INT_MAX;
    unsigned int ui = UINT_MAX;

    printf("i = %d i + 1 = %d i + 2 = %d\n", i, i + 1, i + 2);
    printf("ui = %u ui + 1 = %u ui + 2 = %u\n", ui, ui + 1, ui + 2);
    return 0;
}
```

```
/* 编号: 2 */
i = 2147483647 i + 1 = -2147483648 i + 2 = -2147483647
ui = 4294967295 ui + 1 = 0 ui + 2 = 1
```

## 整数字面量

默认情况下整数字面量是 int 类型, 如果超过 int 的范围那么类型会自动向上升级.

```c
/* 编号: 3
   说明: 2147483648 超过了 int 的范围, 但依然可以被赋值给 unsigned int,
        证明这个字面量被升级成一个可包含 2147483648 的类型. */
#include <stdio.h>
#include <limits.h>
int main(void) {
    unsigned int ui = 2147483648;
    printf("max of int is %d, var ui is %u\n", INT_MAX, ui);
    return 0;
}
```

```
/* 编号: 3 */
max of int is 2147483647, var ui is 2147483648
```

## 整数类型描述符

无论什么数据在底层都是 bit, 具体是什么值取决于你如何看待这段 bit, 例如一个 bit 1, 可以看成 bool 类型的 true, int 类型中的 1, 以及 char 类型中的 ascii code 1. **编号 4 代码** 中使用的 -1 也是同理, 因此用有符号的 int 类型来看这段 bit 就是 -1 (%d), 无符号的 int 来看这段 bit 就是 4294967295 (%u).

```c
/* 编号: 4 */
#include <stdio.h>
int main(void) {
    int i = -1;
    printf("signed int of val i is %d\n"
           "unsigned int of val i is %u\n", i, i);
    return 0;
}
```

```
/* 编号: 4 */
signed int of val i is -1
unsigned int of val i is 4294967295
```

当用范围小的描述符 (%hu, unsigned short) 匹配范围大的变量, 则会截取部分内容. 可以用 16 进制观察 2 进制的值, 16 进制中的一个数字等于 2 进制的四个数字. 因此 0x10001 等于 0001 0000 0000 0000 0001, 而 unsigned short 的范围是 16 bit, 因而截取的内容是 0000 0000 0000 0001, 因此打印值是 1.

```c
/* 编号: 5 */
#include <stdio.h>
int main(void) {
    int i = 65537;
    printf("short type of var i is %hu\n"
           "int type of var i is %i\n"
           "hex of var i is %#x\n", i, i, i);
    return 0;
}
```

```
/* 编号: 5 */
short type of var i is 1
int type of var i is 65537
hex of var i is 0x10001
```

> P 71
That’s because C automatically expands a type short value to a type int value when it’s passed as an argument to a function. The answer to the first question is that the int type is intended to be the integer size that the computer handles most efficiently. So, on a computer for which short and int are different sizes, it may be faster to pass the value as an int.

当用范围大的描述符 (%d) 匹配范围小的变量, 则没有什么问题, 但也不应该这么做. 但这里有一个其他注意事项, 整数类型在被当做参数传入时, 范围小的类型会被转为 int, 原因是操作系统处理 int 是最快的, 因而能转成 int 的都尽量先转成 int. 在 **编号 6 代码** 中用 %i 匹配 short 类型的变量 h 时没有报错, 因为变量 h 传入 `printf` 函数时被升级为 int 类型, 而 %ld 匹配 int 类型的变量 i 时就报 warning 了, 如 **编号 6 终端交互** 所示.

```c
/* 编号: 6 */
#include <stdio.h>
#include <limits.h>
int main(void) {
    short h = SHRT_MAX;
    int i = INT_MAX;
    printf("short type of var h is %hd\n"
           "int type of var h is %d\n", h, h);
    printf("int type of var i is %d\n"
           "long type of var i is %ld\n", i, i);
    return 0;
}
```

```
/* 编号: 6 */
warning: format specifies type 'long' but the argument has type 'int' [-Wformat]

1 warning generated.
short type of var h is 32767
int type of var h is 32767
int type of var i is 2147483647
long type of var i is 2147483647
```

## char

(ASCII) 只有 0-127, 共 128 个字符, 只需要 7 bit 就能表示, 因而 char 是 1 字节的大小. 同时 char 也可以被用于代表范围最低的整数类型. 但这里有个问题, C 语言的规范只说明了 char 类型必须可以存储 0-127 个 ascii code, 其剩下的一个 bit 没有说明, 因此 char 可以是 signed 也可以是 unsigned. 所以在使用 0-127 范围以外的整数时, 需要显示声明 signed char 或 unsigned char.
另外, 在一些地方会使用 int 来代替 char. 例如 `getchar` 中的返回值是 int 类型.

8 / 16 进制表示字符, `\0oo` 是 8 进制表示法 (o represents an octal digit.), `\xhh` 是 16 进制表示法 (h represents a hexadecimal digit.). 注意, 每个进制后面只能跟随两位数字, 因而 8 进制中最大的就是 '\077', 不能表达更大的数了. 而 16 进制中可以表示所有 ascii code, 不过有效值只到 `\x7f`.

```c
/* 编号: 7 */
#include <stdio.h>
int main(void) {
    char hex_ch = '\x7F';
    char oct_ch = '\077';
    printf("hex: %d\n", hex_ch);
    printf("oct: %d\n", oct_ch);
    return 0;
}
```

```
/* 编号: 7 */
hex: 127
oct: 63
```

## portable type

由于不同操作系统的 int, long 等类型的大小不确定, C 提供了 stdint.h 解决了此问题, 对应的提供了 inttypes.h 用于 printf 中的描述符.

## 浮点数

浮点数字面量是 double 类型的, float 被当做参数传入函数时也会转为 double 类型. 因此 printf 中的 %f, 实际上是 double 类型的描述符.

浮点数相关的数据都可以在 `float.h` 中找到, 例如 exponent 的位数, mantissa 的位数

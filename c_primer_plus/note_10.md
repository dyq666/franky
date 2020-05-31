# 10. 数组与指针

注意, 下面提到的 **数组** 都不包含 VLA, 且是 auto storage class.

## 数组声明与初始化

由于数组在编译时就必须确定其在内存中的大小 (占用多少字节), 因而声明语句中必须确定数组的 type 和 size. size 通常会用 `#define` 来定义.

另外, 如果使用了初始化, 那么也可以让编译器计算 size, 不过这么做并没有什么好处.

```c
int ar[];  // error: definition of variable with array type needs an explicit size or an initializer

#define ROWS 3  // 定义 size 的最通用且推荐的方式.
int main(void) {
    int ar[ROWS] = {1, 2, 3};
    for  (int i = 0; i < ROWS; i++)
    ...
    print_ar(ar, ROWS);
    ...
}

int ar[] = {1, 2, 3};  // 编译器会帮你计算出 size 为 3.
printf("%zd\n", sizeof ar / sizeof ar[0]);  // 可以使用 sizeof 获得数组大小. stdout: 3
```

如果没有初始化数组, 那么数组中的元素可能是任意值, 这点和普通类型一样.

如果初始化元素个数少于数组的数量, 那么剩下的元素都会被初始为 0.

如果初始化元素个数多于数组的数量, 那么就会有 warning.

此外, C99 提供了指定初始化, 对于希望只初始化特定位置的值, 或者初始化部分末尾的值非常有帮助. 如果一个位置被初始化了多次, 那么最终的值是最后一次初始化的.

```c
int ar[3];  // 现在数组中的元素可能是任意值 !!

int ar[3] = {100};  // 等价于 {100, 0, 0}

int ar[3] = {100, 1, 2, 3};  // warning: excess elements in array initializer

int powers[3] = {[2] = 4};  // 等价于 {0, 0, 4}
int powers[4] = {1, [2] = 4, 8};  // 等价于 {1, 0, 4, 8}
int powers[SIZE] = {1, [2] = 4, 8, [0] = 16};  // 等价于 {16, 0, 4, 8}. warning: initializer overrides prior initialization of ths subobject
```

数组的 size 必须是 > 0 的 constant integer expression. 在 C 语言中, 整数字面量, sizeof 表达式, 宏定义, 或者是由它们组成表达式都算 constant integer expression, 特别注意常量值不算 (这点和 C ++ 不同) !!

```c
int n = 5;
const int m = 5;
int ar[n];  // warning: variable length array used
int ar2[m];  // 按照 C 的标准, m 不算 constant integer expression, 因此声明的是一个 VLA, 但在我的 gcc 下却声明了一个普通数组. 虽然如此但还是应该按照 C 标准, 避免这种声明方式.
```

对于二维数组来说有两种初始化方式.

```c
int powers[2][3] = {{1, 2}, {4, 8}}  // 等价于 {{1, 2, 0}, {4, 8, 0}}
int powers[2][3] = {1, 2, 4, 8}  // 等价于 {{1, 2, 4}, {8, 0, 0}}
```

## 指针与数组

[] 实际上就是 * 的语法糖, 任何指针都可以用这种操作符, 因而 p[0] == *(p + 0) == *p, p[10] == *(p + 10). 只不过对于普通类型的指针没有必要使用 [], 也不应该使用.

```c
int i = 3;
int * p = &i;

printf("%d\n", p[0]);  // stdout: 3
printf("%d\n", *p);  // stdout: 3
printf("%d\n", p[10]);  // stdout: 任意值
printf("%d\n", *(p + 10));  // stdout: 任意值
```

数组名并不是指针类型, 例如下面的编译报错就说明了 `ar` 是 `int [3]` 类型.
但数组名在大部分情况下会类型强转成指向数组第一个元素的指针, 例如下面的例子中 `ar` 会被强转成 `&ar[0]` 即 `int *` 类型赋值给 `int *` 类型的变量 `p`. 因而数组名可以使用所有 `int *` 类型的操作, 例如 `ar[0], *(ar + 1)`, 或者可以被赋值给 `int *` 的变量.

```c
int ar[3];
ar = 3;  // array type 'int [3]' is not assignable
int * p = ar;
```

`int [3]` 和 `int *` 的区别是什么 ? 或者说数组类型和它退化成的指针类型有什么区别 ?

1. 数组类型的变量只能是常量, 而指针类型可以是可以不是.
2. 数组类型知道数组大小, 而指针不知道.

```c
int ar[3];
int * p;
int ar1[3];
int * const p1;
p = ar;
ar1 = ar;  // error: array type 'int [3]' is not assignable
p1 = ar;  // error: cannot assign to variable 'p1' with const-qualified type 'int * const'

printf("%zd\n", sizeof ar);  // stdout: 12  (12 == 3 * sizeof(int))
printf("%zd\n", sizeof p);  // stdout: 8  (在现在大部分个人计算机中指针类型的大小都是 8)
```

将数组类型的变量传给函数, 实际上执行的是将数组类型赋值给其退化的指针类型, 因为退化后的指针类型缺失了数组大小的信息, 所以通常还需要将数组的大小传递给函数.

```c
void print_ar(int ar[], int n);  // 还可以声明成 void print_ar(int * ar, int n); int ar[] 和 int * ar 在函数 prototype 中是等价的.
int main(void) {
    int ar[3] = {1, 2, 3};
    print_ar(ar, 3);
    return 0;
}
void print_ar(int ar[], int n) {
    printf("%zd\n", sizeof ar);  // stdout: 8
}
```

对于多维数组来说, 结论也是一样的. 从下面编译报错中可得知 `ar` 的类型是 `int [3][4]`, 而它退化之后的类型是 `int (*)[4]`. (注意这里要区分下 `int (*)[4]` 和 `int * [4]` 的区别, 由于 [] 比 * 的优先级高, 所以要生成一个指针就必须先执行 *, 因此 `int (*)[4]` 等于先生成一个指针, 然后指针指向 `int [4]` 类型. 而 `int * [4]` 是先生成一个数组 `[4]`, 数组每个元素是 `int *` 类型.) 因而在处理二维数组时, 你只能传递一个维度的 size, 另一个维度的 size (即这里的 4) 在退化后的指针类型中是依然拥有的.

```c
int ar[3][4] = {1, 2, 3};
ar = 3;  // error: array type 'int [3][4]' is not assignable
int * i = &ar[0];  // warning: incompatible pointer types initializing 'int *' with an expression of type 'int (*)[4]'

void print_ar(int ar[][4], int n);
int main(void) {
    int ar[3][4] = {1, 2, 3};
    print_ar(ar, 3);
    ...
}
...
```

## VLA

首先注意 VLA 是 C99 中加入的, 但 C11 中又被作为可选项. 因此尽量不使用 VLA, 在 gcc 中可以使用 `-Wvla` 选项来避免误用了 VLA.

VLA 通常用于在函数中处理多维数组. 假设你想使用一个函数来打印二维数组, 但你又有 `int [3][4]` `int[3][5]` 等第二维 size 不一样的数组, 那么你必须为每种 size 的二维数组类型创建一个函数. 而 VLA 是动态生成的, 因而只需要一个函数就满足了.

```c
void print_ar(int rows, int cols, int ar[rows][cols]);  // ar 必须是最后一个参数
int main(void) {
    print_ar(2, 3, (int[2][3]){1, 2});
    return 0;
}
void print_ar(int rows, int cols, int ar[rows][cols]) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            printf("%d\n", ar[i][j]);
}
```

实际上不使用 VLA 也能用一个函数来实现二维数组打印, 不过有些 tricky. 你需要用一维数组的方式来处理二维数组, 然后手动计算索引.

```c
void print_ar(int * ar, int rows, int cols);
int main(void) {
    int powers[2][3] = {{1, 2, 4}, {8, 16, 32}};
    print_ar(powers[0], 2, 3);
    return 0;
}
void print_ar(int * ar, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            // 每行的起始位置 == 行数 * 总列数 == i * cols
            printf("%d\n", ar[i * cols + j]);
}
```

## 其他

### 数组范围

C 为了运行效率放弃了运行时检查索引, 因此需要程序员确保使用边界内的索引. 使用边界外的索引会修改到数组附近内存的值. 另外, 有的编译器会在编译时检查一些可以识别的索引错误, 并抛出 warning.

```c
int ar[3] = {1, 2, 3};
ar[3] = 4;  // warning: array index 3 is past the end of the array (which contains 3 elements)
```

### 数组字面量

数组字面量的格式: `(类型){初始值}`. 你可以使用数组字面量在在任何使用数组的地方代替它, 不过通常用在函数传参的过程中.

```c
int * p = (int [3]){1, 2, 4};  // 一维数组
int (*p1)[3] = (int [2][3]){{1, 2, 4}, {8, 16, 32}};  // 二维数组
```

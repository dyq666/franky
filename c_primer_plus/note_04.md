> Note that Figure 4.1 shows the character \0 in the last array position. This is the null charac- ter, and C uses it to mark the end of a string. The null character is not the digit zero; it is the nonprinting character whose ASCII code value (or equivalent) is 0.

> Note (and this is important) that scanf() just reads Angela Plains’s first name. After scanf() starts to read input, it stops reading at the first whitespace (blank, tab, or newline) it encounters.

> The #define statement can be used for character and string constants, too. Just use single quotes for the former and double quotes for the latter. The following examples are valid:
#define BEEP '\a'
#define TEE 'T'
#define ESC '\033'
#define OOPS "Now you have done it!"
Remember that everything following the symbolic name is substituted for it. Don’t make this common error:
/* the following is wrong */ #define TOES = 20
If you do this, TOES is replaced by = 20, not just 20. In that case, a statement such as digits = fingers + TOES;
is converted to the following misrepresentation:
digits = fingers + = 20;

```c
#include <stdio.h>
int main(void) {
    // 右对齐
    printf("*%10d* *%10d*\n", 2, 3);
    // 左对齐
    printf("*%-10d* *%-10d*\n", 2, 3);
    // 左填充 0
    printf("*%010d* *%010d*\n", 2, 3);
    // 正数显示 '+' 号
    printf("*%+d* *%+d*\n", 2, -3);
    // 正数前有一个空格
    printf("*% d* *% d*\n", 2, -3);
    return 0;
}
```

> The scanf() function uses whitespace (newlines, tabs, and spaces) to decide how to divide the input into separate fields. It matches up consecutive conversion specifications to consecutive fields, skipping over the whitespace in between. Note how this sample run spread the input over two lines. You could just as well have used one or five lines, as long as you had at least one newline, space, or tab between each entry:
The only exception to this is the %c specification, which reads the very next character, even if
that character is whitespace. We’ll return to this topic in a moment.

> What if the first non-whitespace character is, say, an A instead of a digit? Then scanf() stops right there and places the A (or whatever) back in the input. No value is assigned to the specified variable, and the next time the program reads input, it starts at the A again. If your program has only %d specifiers, scanf() will never get past that A. Also, if you use a scanf() statement with several specifiers, C requires the function to stop reading input at the first failure.

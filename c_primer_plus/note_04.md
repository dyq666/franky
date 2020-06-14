> Note that Figure 4.1 shows the character \0 in the last array position. This is the null charac- ter, and C uses it to mark the end of a string. The null character is not the digit zero; it is the nonprinting character whose ASCII code value (or equivalent) is 0.
Note (and this is important) that scanf() just reads Angela Plains’s first name. After scanf() starts to read input, it stops reading at the first whitespace (blank, tab, or newline) it encounters.

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

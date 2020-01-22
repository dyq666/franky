// 各种 format specifier.

#include <stdio.h>

void integer_in_bases(void);
void char_in_bases(void);
void float_in_bases(void);
void integer_specifiers(void);
void incorrect_integer_specifiers(void);
void float_specifiers(void);

int main(void) {
    integer_in_bases();
    printf("\n");
    char_in_bases();
    printf("\n");
    float_in_bases();
    printf("\n");

    integer_specifiers();
    printf("\n");
    incorrect_integer_specifiers();
    printf("\n");

    float_specifiers();
    printf("\n");

    return 0;
}

void integer_in_bases(void) {
    int oct = 0400, dec = 256, hex = 0x100;

    printf("The decimal value of `0400` is %d\n"
           "The decimal value of `0x100` is %d\n"
           "The octal value of `256` is %o, %#o\n"
           "The hexadecimal value of `256` is %x, %#x, %#X\n",
           oct, 
           hex, 
           dec, dec, 
           dec, dec, dec);
}

void char_in_bases(void) {
    char normal = 'A', dec = 65, oct = '\101', hex = '\x41';

    printf("The decimal value of `%c` is %d\n"
           "The char representation of `\\101` is %c\n"
           "The char representation of `65` is %c\n"
           "The char representation of `\\x41` is %c\n",
           normal, normal,
           dec,
           oct,
           hex);
}

void integer_specifiers(void) {
    int integer = 100;
    unsigned int unsigned_integer = 100u;
    short short_integer = 100;
    unsigned short unsigned_short_integer = 100u;
    long long_integer = 100L;
    unsigned long unsigned_long_integer = 100UL;
    long long long_long_integer = 100LL;
    unsigned long long unsigned_long_long_integer = 100ULL;

    printf("`integer` use %%d (%d)\n"
           "`unsigned_integer` use %%u (%u)\n"
           "`short_integer` use %%hd (%hd)\n"
           "`unsigned_short_integer` use %%hu (%hu)\n"
           "`long_integer` use %%ld (%ld)\n"
           "`unsigned_long_integer` use %%lu (%lu)\n"
           "`long_long_integer` use %%lld (%lld)\n"
           "`unsigned_long_long_integer` use %%llu (%llu)\n",
           integer,
           unsigned_integer,
           short_integer,
           unsigned_short_integer,
           long_integer,
           unsigned_long_integer,
           long_long_integer,
           unsigned_long_long_integer);
}

void incorrect_integer_specifiers(void) {
    unsigned int overflow = 2147483648;
    short small = 200;

    // %d 的最大值等于 int 的最大值 2147483647, 所以不能用 %d 展示 2147483648.
    printf("When unsigned value > 2147483648, you must use %%u (%u) rather than %%d (%d).\n"
           "When use short type, you can use %%d (%d) or %%hd (%hd)\n",
           overflow, overflow,
           small, small);
}

void float_in_bases(void) {
    double dec = 3.2E-2;
    // f = 15, 0.1 = 1 / 16 = 0.0625, p10 = 2 ** 10, 15.0625 * (2 ** 10) == 15424.0
    double hex = 0xf.1p10;

    printf("The value of `3.2E-2` is %f\n"
           "The value of `0xf.0p10` is %f\n"
           "The exponential representation of `3.2E-2` is %e\n"
           "The hexadecimal exponential representation of `3.2E-2` is %a\n",
           dec,
           hex,
           dec,
           dec);
}

void float_specifiers(void) {
    float float_ = 2.3f;
    double double_float = 2.3;
    long double long_double_float = 2.3L;

    printf("float use %%f (%f)\n"
           "double use %%f (%f)\n"
           "long double use %%Lf (%Lf)\n",
           float_,
           double_float,
           long_double_float);
}

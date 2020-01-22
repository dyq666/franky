// 各种 format specifier.

#include <stdio.h>

void integer_in_bases(void);
void char_in_bases(void);
void integer_specifiers(void);

int main(void) {
    integer_in_bases();
    printf("\n");
    char_in_bases();
    printf("\n");
    integer_specifiers();
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

    printf("`unsigned_integer` is %u\n", unsigned_integer);
    printf("`short_integer` is %hd\n", short_integer);
    printf("`unsigned_short_integer` is %hu\n", unsigned_short_integer);
    printf("`long_integer` is %ld\n", long_integer);
    printf("`unsigned_long_integer` is %lu\n", unsigned_long_integer);
    printf("`long_long_integer` is %lld\n", long_long_integer);
    printf("`unsigned_long_long_integer` is %llu\n", unsigned_long_long_integer);
}

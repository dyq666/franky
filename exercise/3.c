#include <stdio.h>

void exercise_1(void);
void exercise_2(void);
void exercise_3(void);
void exercise_4(void);
void exercise_5(void);
void exercise_6(void);
void exercise_7(void);
void exercise_8(void);

int main(void) {
    return 0;
}

void exercise_1(void) {
    int overflow_integer = 2147483648;
    float overflow_float = 0x1.ffffffp127;
    printf("The overflow integer 2147483648, real value is %d\n", overflow_integer);
    printf("The overflow float is %a\n", overflow_float);
}

void exercise_2(void) {
    int ascii_code;

    printf("Please enter a ascii code:");
    scanf("%d", &ascii_code);

    printf("The char representation of ascii code %d is %c\n", ascii_code, ascii_code);
}

void exercise_3(void) {
    printf("\aStartled by the sudden sound, Sally shouted,\n"
           "By the Great Pumpkin, what was that!\n");
}

void exercise_4(void) {
    float display;

    printf("Enter a floating-point value:");
    scanf("%f", &display);

    printf("fixed-point notation: %f\n"
           "exponential notation: %e\n"
           "p notation: %a\n",
           display, display, display);
}

void exercise_5(void) {
    int age;
    double seconds_in_year = 3.156e7;

    printf("Please enter your age:");
    scanf("%d", &age);

    printf("Your age is %f seconds\n", age * seconds_in_year);
}

void exercise_6(void) {
    int quart;
    int water_in_quart = 950;
    double molecule_in_water = 3.0e-23;

    printf("Please enter a quart of water:");
    scanf("%d", &quart);

    printf("Molecules is %e\n", quart * water_in_quart * molecule_in_water);
}

void exercise_7(void) {
    int height;
    float centimeter_in_inch = 2.54;
    
    printf("Please enter your height in inch:");
    scanf("%d", &height);

    printf("Your height in centimeter is %f", height * centimeter_in_inch);
}

void exercise_8(void) {
    float cups;
    int cup_in_pint = 2,
        ounce_in_cup = 8,
        tablespoon_in_ounce = 2,
        teaspoon_in_tablespoon = 3;
    
    printf("Please enter your volume in cups:");
    scanf("%f", &cups);

    printf("The volumes in pint is %f\n"
           "The volumes in ounce is %f\n"
           "The volumes in tablespoon is %f\n"
           "The volumes in teaspoon is %f\n",
           cups / cup_in_pint,
           cups * ounce_in_cup,
           cups * ounce_in_cup * tablespoon_in_ounce,
           cups * ounce_in_cup * tablespoon_in_ounce * teaspoon_in_tablespoon);
}

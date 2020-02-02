#include <stdio.h>
#define PRAISE "You are an extraordinary being."

int main(void) {
    float weight;
    char name[40];

    printf("Hi, what's your first name: ");
    scanf("%s", name);

    printf("%s, what's your weight in pounds: ", name);
    scanf("%f", &weight);

    printf("Well, %s, your volume is %2.2f cubic feet.\n"
           "Also, your first name has %zu letters,"
           "and we have %zu bytes to store it.\n",
           name, weight / DENSITY,
           strlen(name),
           sizeof(name));

    return 0;
}

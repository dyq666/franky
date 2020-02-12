#include <stdio.h>
#include <stdlib.h>  // for `exit`

int main(void) {
    int ch;
    FILE * fp;
    char filename[50];

    printf("Enter the name of the file: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Failed to open file. Bye\n");
        exit(1);
    }

    // `getc` gets a character from the open file.
    while ((ch = getc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);

    return 0;
}

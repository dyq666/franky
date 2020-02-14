#include <iso646.h>
#include <stdio.h>

void discard_chars(void);
int get_choice(void);

int main(void) {
    int choice;

    while ((choice = get_choice()) != 'q') {
        switch (choice) {
            case 'a': printf("It is a\n");
                      break;
            case 'b': printf("It is b\n");
                      break;
            case 'c': printf("It is c\n");
                      break;
            case 'd': printf("It is d\n");
                      break;
            default:  printf("Program error!.\n");
                      break;
        }
    }

    printf("Bye!\n");    

    return 0;
}

void discard_chars(void) {
    /* 丢弃当前行所有字符. */
    while (getchar() != '\n') {
        ;
    }
}

int get_choice(void) {
    int ch;

    printf("Enter the letter of your choice:\n"
           "a. addition           b. subtraction\n"
           "c. multiplication     d. division\n"
           "q. quit\n");

    ch = getchar();
    discard_chars();
    while (ch < 'a' or (ch > 'd' and ch != 'q')) {
        printf("Please enter a, b, c, d or q: ");
        ch = getchar();
        discard_chars();
    }

    return ch;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void exercise_1(void);
void exercise_2(void);
void exercise_3(void);
void exercise_4(void);
void exercise_5(void);
void exercise_6(void);
void exercise_7(void);
// void exercise_8 (void);
// void exercise_9(void);
void exercise_10(void);
void exercise_11(void);

int main(void) {
    exercise_11();

    return 0;
}

void exercise_1(void) {
    const int SIZE = 26;

    int iter_i;
    char lowercases[SIZE];

    for (iter_i = 0; iter_i < SIZE; iter_i++) {
        // 97 is ascii code of letter 'a'
        lowercases[iter_i] = 97 + iter_i;
    }

    for (iter_i = 0; iter_i < SIZE; iter_i++) {
        printf("%c ", lowercases[iter_i]);
    }
}

void exercise_2(void) {
    int iter_i, iter_j;

    for (iter_i = 1; iter_i < 6; iter_i++) {
        for (iter_j = 0; iter_j < iter_i; iter_j++) {
            printf("$");
        }
        printf("\n");
    }
}

void exercise_3(void) {
    int iter_i, iter_j;

    // 总共打印 7 - 1 行, 每行打印 `iter_i` 个字符.
    for (iter_i = 1; iter_i < 7; iter_i++) {
        for (iter_j = 0; iter_j < iter_i; iter_j++) {
            // 70 is ascii code of letter 'F'
            printf("%c", 70 - iter_j);
        }
        printf("\n");
    }
}

void exercise_4(void) {
    int iter_i, iter_j;
    int letter = 'A';

    // 打印 6 行, 每行打印 `iter_i` 个
    for (iter_i = 1; iter_i < 7; iter_i++) {
        for (iter_j = 0; iter_j < iter_i; iter_j++) {
            printf("%c", letter);
            letter++;
        }
        printf("\n");
    }
}

void exercise_5(void) {
    char center, cur_char, mid_char;
    int i, j, rows, cols, mid_index;

    printf("Please enter center letter: ");
    scanf("%c", &center);

    rows = center - 'A' + 1;
    cols = rows * 2 - 1;
    mid_index = cols / 2;

    for (i = 0; i < rows; i ++) {
        mid_char = 'A' + i;
        for (j = 0; j < cols; j ++) {
            cur_char = mid_char - abs(mid_index - j);
            if (cur_char < 'A') {
                cur_char = ' ';
            }
            printf("%c", cur_char);
        }
        printf("\n");
    }
}

void exercise_6(void) {
    int i, min, max;
    
    printf("Please enter max and min integer: ");
    scanf("%d%d", &min, &max);

    for (i = min; i < max + 1; i ++) {
        printf("%d %d %d\n", i, i * i, i * i * i);
    }
}

void exercise_7(void) {
    char word[41];
    int i;

    printf("Please enter a word (max length is 40): ");
    scanf("%s", word);

    for (i = strlen(word); i > -1; i --) {
        printf("%c", word[i]);
    }
}

void exercise_10(void) {
    int i, min, max;
    int sum = 0;

    printf("Enter lower and upper integer limits: ");
    scanf("%d%d", &min, &max);
    while (min < max) {
        for (i = min; i < max + 1; i ++) {
            sum += i * i;
        }
        printf("The sums of the squares from %d to %d is %d\n", min * min, max * max, sum);

        printf("Enter lower and upper integer limits: ");
        scanf("%d%d", &min, &max);
    }
    printf("Done\n");
}

void exercise_11(void) {
    const int SIZE = 8;
    int i, array[SIZE];

    printf("Enter eight integers: ");
    for (i = 0; i < SIZE; i ++) {
        scanf("%d", &array[i]);
    }

    for (i = SIZE - 1; i > -1; i --) {
        printf("%d ", array[i]);
    }
}
#include "util.h"

void discard_rest_input_line(void) {
    while (getchar() != '\n')
        continue;
}

#include <stdio.h>
#include "math_utils.h"

int main(void) {
    printf("Hello, C workspace!\n");
    printf("Quick math demo: 7 + 3 = %d\n", math_add(7, 3));
    printf("Quick math demo: 10 * 5 = %d\n", math_multiply(10, 5));
    return 0;
}

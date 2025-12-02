#include "math_utils.h"

int math_add(int a, int b) {
    return a + b;
}

int math_subtract(int a, int b) {
    return a - b;
}

int math_multiply(int a, int b) {
    return a * b;
}

int math_divide(int a, int b) {
    if (b == 0) {
        return 0;  /* Avoid division by zero */
    }
    return a / b;
}

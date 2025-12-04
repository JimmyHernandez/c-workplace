#include "math_utils.h"

/**
 * @brief Add two integers.
 *
 * Implementation of the `math_add` function declared in `math_utils.h`.
 */
int math_add(int a, int b) {
    return a + b;
}

/**
 * @brief Subtract two integers.
 */
int math_subtract(int a, int b) {
    return a - b;
}

/**
 * @brief Multiply two integers.
 */
int math_multiply(int a, int b) {
    return a * b;
}

/**
 * @brief Divide two integers (integer division).
 *
 * Returns 0 when dividing by zero to avoid a runtime crash; callers
 * should validate the divisor if they need error reporting.
 */
int math_divide(int a, int b) {
    if (b == 0) {
        return 0;  /* Avoid division by zero */
    }
    return a / b;
}

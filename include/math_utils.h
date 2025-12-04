#ifndef MATH_UTILS_H
#define MATH_UTILS_H

/**
 * @file math_utils.h
 * @brief Simple math utility functions (add, subtract, multiply, divide).
 *
 * These functions perform basic integer arithmetic. The divide function
 * returns 0 if a division-by-zero is attempted; callers should check the
 * divisor or use a different error reporting mechanism in production code.
 */

/**
 * @brief Add two integers.
 *
 * @param a First addend.
 * @param b Second addend.
 * @return int The sum of `a` and `b`.
 */
int math_add(int a, int b);

/**
 * @brief Subtract two integers.
 *
 * @param a Minuend.
 * @param b Subtrahend.
 * @return int The result of `a - b`.
 */
int math_subtract(int a, int b);

/**
 * @brief Multiply two integers.
 *
 * @param a Multiplicand.
 * @param b Multiplier.
 * @return int The product `a * b`.
 */
int math_multiply(int a, int b);

/**
 * @brief Divide two integers (integer division).
 *
 * @note This function returns `0` if `b == 0` to avoid a runtime error.
 *       For callers that need explicit error handling use a wrapper that
 *       checks the divisor first.
 *
 * @param a Dividend.
 * @param b Divisor.
 * @return int The quotient `a / b`, or `0` if `b == 0`.
 */
int math_divide(int a, int b);  /* Returns 0 on division by zero */

#endif /* MATH_UTILS_H */

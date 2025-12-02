#include <stdio.h>
#include "test.h"
#include "math_utils.h"

/* Example test cases using the test harness */

void test_arithmetic(void) {
    printf("Running: test_arithmetic\n");
    ASSERT_EQ(2 + 2, 4);
    ASSERT_EQ(5 - 3, 2);
    ASSERT_EQ(3 * 4, 12);
}

void test_math_utils(void) {
    printf("Running: test_math_utils\n");
    ASSERT_EQ(math_add(3, 5), 8);
    ASSERT_EQ(math_subtract(10, 4), 6);
    ASSERT_EQ(math_multiply(6, 7), 42);
    ASSERT_EQ(math_divide(20, 4), 5);
    ASSERT_EQ(math_divide(10, 0), 0);  /* Division by zero safety */
}

void test_conditions(void) {
    printf("Running: test_conditions\n");
    ASSERT_TRUE(1);
    ASSERT_TRUE(5 > 3);
    ASSERT_EQ(10, 10);
}

int main(void) {
    printf("=== C Workspace Test Suite ===\n\n");
    
    test_arithmetic();
    test_math_utils();
    test_conditions();
    
    TEST_SUMMARY();
}

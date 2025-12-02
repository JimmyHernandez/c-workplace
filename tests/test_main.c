#include <stdio.h>
#include "test.h"

/* Example test cases using the test harness */

void test_arithmetic(void) {
    printf("Running: test_arithmetic\n");
    ASSERT_EQ(2 + 2, 4);
    ASSERT_EQ(5 - 3, 2);
    ASSERT_EQ(3 * 4, 12);
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
    test_conditions();
    
    TEST_SUMMARY();
}

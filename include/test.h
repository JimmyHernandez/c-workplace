#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>

/* Simple test harness — no external dependencies */

static int test_pass_count = 0;
static int test_fail_count = 0;

#define ASSERT_EQ(actual, expected) \
    do { \
        if ((actual) != (expected)) { \
            fprintf(stderr, "  FAIL: %s:%d: expected %d, got %d\n", \
                    __FILE__, __LINE__, (expected), (actual)); \
            test_fail_count++; \
        } else { \
            test_pass_count++; \
        } \
    } while (0)

#define ASSERT_TRUE(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "  FAIL: %s:%d: assertion failed\n", \
                    __FILE__, __LINE__); \
            test_fail_count++; \
        } else { \
            test_pass_count++; \
        } \
    } while (0)

#define TEST_SUMMARY() \
    do { \
        printf("\n=== Test Summary ===\n"); \
        printf("Passed: %d\n", test_pass_count); \
        printf("Failed: %d\n", test_fail_count); \
        printf("Total:  %d\n", test_pass_count + test_fail_count); \
        if (test_fail_count > 0) { \
            printf("RESULT: FAIL\n"); \
            return 1; \
        } else { \
            printf("RESULT: PASS\n"); \
            return 0; \
        } \
    } while (0)

#endif /* TEST_H */

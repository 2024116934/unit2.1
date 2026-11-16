// ELEC2645 Unit 2.1 Activity 4 - Unit Tests
//
// This is a separate executable. It calls the operations library directly
// using known inputs, without running the interactive application.

#include <stdio.h>
#include "activity4_operations.h"

// Count how many tests have run and how many have failed.
//
// These variables are outside main(), so all functions in this file can
// access them. static prevents other .c files from accessing them.
static int tests_run = 0;
static int tests_failed = 0;

void check_int(const char *test_name, int expected, int actual)
{
    tests_run++;

    printf("Test: %s\n", test_name);
    printf("  Expected: %d\n", expected);
    printf("  Actual:   %d\n", actual);

    if (expected == actual)
    {
        printf("  Result:   PASS\n\n");
    }
    else
    {
        printf("  Result:   FAIL\n\n");
        tests_failed++;
    }
}

int main(void)
{
    // Two example tests are supplied.
    check_int("addition with positive values", 12, operation_add(7, 5));

    check_int("subtraction giving a negative result", -3, operation_subtract(2, 5));

    // Step 1: Add a multiplication test.
    // Step 2: Add an integer division test using 9 and 2.
    // Step 3: Add a test involving zero.
    // Step 4: Test division by zero.
    // operation_divide() should return 0 to report failure.
    // Do not check quotient because no result is written when division fails.
    // Step 5: Add at least one boundary or unusual case of your own.

    printf("Tests run: %d\n", tests_run);
    printf("Tests failed: %d\n", tests_failed);

    if (tests_failed == 0)
    {
        printf("All tests passed! Get in!\n");
        return 0;
    }

    printf("Some tests failed. Looks like we have work to do.\n");
    return 1;
}

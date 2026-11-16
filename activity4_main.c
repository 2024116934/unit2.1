// ELEC2645 Unit 2.1 Activity 4 - Interactive Application
//
// This executable uses the operations library through keyboard input.

#include <stdio.h>
#include "activity4_operations.h"

int main(void)
{
    int a;
    int b;

    printf("Enter two integers separated by a space: ");

    // we are keeping it simple for this activity, so we will not handle invalid input gracefully
    if (scanf("%d %d", &a, &b) != 2)
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Sum: %d\n", operation_add(a, b));
    printf("Difference: %d\n", operation_subtract(a, b));
    printf("Product: %d\n", operation_multiply(a, b));

    int quotient;

    if (operation_divide(a, b, &quotient))
    {
        printf("Integer quotient: %d\n", quotient);
    }
    else
    {
        printf("Cannot divide by zero.\n");
    }

    return 0;
}

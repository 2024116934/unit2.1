#include "activity4_operations.h"

int operation_add(int a, int b)
{
    return a + b;
}

int operation_subtract(int a, int b)
{
    return a - b;
}

int operation_multiply(int a, int b)
{
    return a * b;
}

int operation_divide(int numerator, int denominator, int *result)
{
    if (denominator == 0)
    {
        return 0;
    }

    *result = numerator / denominator;
    return 1;
}

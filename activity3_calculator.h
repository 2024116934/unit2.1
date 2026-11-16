#ifndef ACTIVITY3_CALCULATOR_H
#define ACTIVITY3_CALCULATOR_H

int calculator_add(int a, int b);
int calculator_subtract(int a, int b);
int calculator_multiply(int a, int b);

// Return 1 on success and store the integer result using the pointer.
// Return 0 if the denominator is zero.
int calculator_divide(int numerator, int denominator, int *result);

#endif

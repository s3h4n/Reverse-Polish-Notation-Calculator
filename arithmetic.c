#include "arithmetic.h"
#include <stdio.h>

// Addition function
double add(double a, double b)
{
    return a + b;
}

// Subtraction function
double subtract(double a, double b)
{
    return a - b;
}

// Multiplication function
double multiply(double a, double b)
{
    return a * b;
}

// Division function that returns a float result
double divide(double a, double b, int *error)
{
    if (b != 0)
    {
        *error = 0;           // No error
        return (double)a / b; // Return floating-podouble result
    }
    else
    {
        *error = 1; // Division by zero error
        return 0;   // Return a default value, but error will be flagged
    }
}

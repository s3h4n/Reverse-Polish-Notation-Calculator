#include "parser.h"
#include "arithmetic.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to evaluate a space-separated postfix expression with floating-point support
int evaluatePostfix(char expression[], Stack *stack)
{
    char *token = strtok(expression, " "); // Tokenize input by spaces
    int errorFlag = 0;                     // Track any errors during evaluation

    while (token != NULL)
    {
        // Check for digits and negative integers
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
        {
            double num = atof(token); // Convert token to double to allow precise results from division
            push(stack, num);         // Push the number onto the stack
        }
        else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
        {
            // Check for stack underflow
            if (stack->top < 1)
            {
                return 1; // Error code for invalid expression (not enough operands)
            }

            double b = pop(stack);
            double a = pop(stack);

            if (token[0] == '+')
            {
                push(stack, add(a, b));
            }
            else if (token[0] == '-')
            {
                push(stack, subtract(a, b));
            }
            else if (token[0] == '*')
            {
                push(stack, multiply(a, b));
            }
            else if (token[0] == '/')
            {
                int divisionError = 0;
                double result = divide(a, b, &divisionError); // Allow float division result
                if (divisionError)
                {
                    return 2; // Error code for division by zero
                }
                push(stack, result); // Push the floating-point result
            }
        }
        else
        {
            return 1; // Error code for invalid operator or token
        }

        token = strtok(NULL, " "); // Move to the next token
    }

    // If there's more than one number left in the stack, it's an error
    if (stack->top != 0)
    {
        return 1; // Error code for too many operands
    }

    return 0; // Success
}

#include "parser.h"
#include "arithmetic.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void evaluatePostfix(char expression[], Stack *stack)
{
    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (isdigit(expression[i]))
        {
            push(stack, expression[i] - '0');
        }
        else
        {
            // Check if there are at least two operands on the stack
            if (stack->top < 1)
            {
                printf("Error: Invalid Expression\n");
            }

            int b = pop(stack);
            int a = pop(stack);

            if (expression[i] == '+')
            {
                push(stack, add(a, b));
            }
            else if (expression[i] == '-')
            {
                push(stack, subtract(a, b));
            }
            else if (expression[i] == '*')
            {
                push(stack, multiply(a, b));
            }
            else if (expression[i] == '/')
            {
                if (b == 0)
                {
                    printf("Error: Division by zero\n");
                }
                push(stack, divide(a, b));
            }
            else
            {
                printf("Error: Invalid Operator\n");
            }
        }
    }

    // If there's more than one number left in the stack, it's an error
    if (stack->top != 0)
    {
        printf("Error: Too many operands\n");
    }
}

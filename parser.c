#include "parser.h"
#include "arithmetic.h"
#include <ctype.h>
#include <stdio.h>

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
            if (stack->top < 1)
            {
                printf("Error: Invalid Expression\n");
                return;
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
                    return;
                }
                push(stack, divide(a, b));
            }
            else
            {
                printf("Error: Invalid Operator\n");
                return;
            }
        }
    }

    if (stack->top != 0)
    {
        printf("Error: Too many operators\n");
        return;
    }
}

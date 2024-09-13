#include "io_handler.h"
#include <stdio.h>

void getExpression(char expression[])
{
    printf("Enter a postfix expression (e.g., 23*54*+): ");
    scanf("%s", expression); // Get the postfix expression from the user
}

void printResult(Stack *stack)
{
    printf("Result: %d\n", peek(stack)); // Print the result (top of the stack)
}

#include "io_handler.h"
#include <stdio.h>
#include <string.h>

// Function to get the postfix expression from the user with multi-digit support (space-separated)
void getExpression(char expression[])
{
    printf("Enter a space-separated postfix expression (e.g., 23 54 * +): ");
    scanf(" %[^\n]", expression); // Get the input until a newline is encountered
}

// Function to print the result from the stack
void printResult(Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Error: Stack is empty. No result to display.\n");
    }
    else
    {
        printf("Result: %.2f\n", peek(stack)); // Print the result (top of the stack) as a float
    }
}

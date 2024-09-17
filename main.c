#include <stdio.h>
#include "stack.h"
#include "parser.h"
#include "io_handler.h"

int main()
{
    char expression[100]; // Array to store the input expression (max size 100)
    Stack stack;          // Stack to hold operands during evaluation
    int evalStatus;       // Status to track errors during evaluation

    while (1) // Infinite loop, will run until interrupted by Ctrl+C
    {
        initStack(&stack); // Initialize the stack

        getExpression(expression); // Get postfix expression from user

        evalStatus = evaluatePostfix(expression, &stack); // Evaluate the postfix expression

        // Handle specific errors based on return code
        if (evalStatus == 0)
        {
            printResult(&stack); // Print the final result from the stack
        }
        else if (evalStatus == 1)
        {
            printf("Error: Invalid expression - Not enough operands or invalid operator.\n");
        }
        else if (evalStatus == 2)
        {
            printf("Error: Division by zero.\n");
        }
        else
        {
            printf("An unknown error occurred during evaluation. Please try again.\n");
        }
    }

    return 0;
}
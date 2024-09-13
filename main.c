#include <stdio.h>
#include "stack.h"
#include "parser.h"
#include "io_handler.h"

int main()
{
    char expression[100]; // Array to store the input expression (max size 100)

    Stack stack; // Stack to hold operands during evaluation

    initStack(&stack); // Initialize the stack

    getExpression(expression); // Get postfix expression from user

    evaluatePostfix(expression, &stack); // Evaluate the postfix expression

    printResult(&stack); // Print the final result from the stack

    return 0;
}

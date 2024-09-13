#include <stdio.h>
#include "stack.h"
#include "parser.h"
#include "io_handler.h"

int main()
{
    char expression[100];
    Stack stack;

    initStack(&stack);

    getExpression(expression);

    evaluatePostfix(expression, &stack);

    printResult(&stack);

    return 0;
}

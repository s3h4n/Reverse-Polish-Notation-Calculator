#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "parser.h"
#include "io_handler.h"

void test(char *expression)
{
    Stack stack;
    initStack(&stack);

    printf("Test: %s\n", expression);
    evaluatePostfix(expression, &stack);
}

int main()
{

    printf("Running valid test cases...\n");
    test("23+");
    test("53-");
    test("52*");
    test("82/");
    test("12+4*");
    test("35*7+");

    printf("\nRunning invalid test cases...\n");
    test("6+");
    test("59&");
    test("52*-");
    test("80/");
    test("");

    return 0;
}

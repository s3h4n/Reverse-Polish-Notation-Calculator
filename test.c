#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "parser.h"
#include "io_handler.h"
#include "arithmetic.h"

// Function to run each test case
void runTest(const char *description, const char *expression, double expectedOutput, int expectedError)
{
    Stack stack;
    initStack(&stack);

    char exprCopy[100];
    strncpy(exprCopy, expression, 100); // Copy expression to avoid modifying original
    exprCopy[99] = '\0';                // Ensure null-termination

    int evalStatus = evaluatePostfix(exprCopy, &stack);

    // Prepare output variables
    char resultStatus[10]; // Pass/Fail
    double resultValue = 0.0;

    // Handle error cases and check result
    if (evalStatus == expectedError)
    {
        if (evalStatus == 0) // No error, check result
        {
            resultValue = peek(&stack);
            if (resultValue == expectedOutput)
            {
                strcpy(resultStatus, "Pass");
            }
            else
            {
                strcpy(resultStatus, "Fail");
            }
        }
        else
        {
            strcpy(resultStatus, "Pass");
        }
    }
    else
    {
        strcpy(resultStatus, "Fail");
    }

    // Truncate long expressions for table formatting
    char truncatedExpr[25];
    if (strlen(expression) > 24)
    {
        strncpy(truncatedExpr, expression, 24);
        truncatedExpr[24] = '\0'; // Add null-termination
    }
    else
    {
        strcpy(truncatedExpr, expression);
    }

    // Print result in table format with aligned columns
    printf("| %-35s | %-24s | %-15.2f | %-10d | %-5s |\n", description, truncatedExpr, expectedOutput, evalStatus, resultStatus);
}

int main()
{
    printf("Starting Tests...\n\n");

    // Print Valid Test Cases Header
    printf("VALID TEST CASES:\n\n");
    printf("| %-35s | %-24s | %-15s | %-10s | %-5s |\n", "Test Description", "Expression", "Expected", "Error", "Result");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    // Valid test cases
    runTest("Addition with 2 operands", "2.5 3.2 +", 5.7, 0);
    runTest("Subtraction with 2 operands", "8.5 2.0 -", 6.5, 0);
    runTest("Multiplication with 2 operands", "3.5 2.0 *", 7.0, 0);
    runTest("Division with 2 operands", "9.0 3.0 /", 3.0, 0);
    runTest("Multi-step expression", "5.0 1.0 2.0 + 4.0 * + 3.0 -", 14.0, 0);
    runTest("Different operation sequences", "3.0 5.0 8.0 * 7.0 + *", 141.0, 0);
    runTest("Complex with multiple operators", "10.5 3.0 2.0 + * 4.5 / 5.0 -", 12.25, 0);
    runTest("Complex involving subtraction", "6.5 3.5 - 2.0 1.0 + *", 6.0, 0);

    printf("-------------------------------------------------------------------------------------------------------------\n");

    // Print Invalid Test Cases Header
    printf("\nINVALID TEST CASES:\n\n");
    printf("| %-35s | %-24s | %-15s | %-10s | %-5s |\n", "Test Description", "Expression", "Expected", "Error", "Result");
    printf("-------------------------------------------------------------------------------------------------------------\n");

    // Invalid test cases
    runTest("Missing operand", "6.0 +", 0, 1);
    runTest("Invalid operator", "5.0 9.0 &", 0, 1);
    runTest("Too many operators", "5.0 2.0 * - /", 0, 1);
    runTest("Too many operands", "5.0 3.0 2.0 +", 0, 1);
    runTest("Division by zero", "10.0 0.0 /", 0, 2);
    runTest("Non-numeric input", "a b +", 0, 1);
    runTest("Empty expression", "", 0, 1);
    runTest("Only operators with no operands", "+ + +", 0, 1);

    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("\nTesting complete.\n");

    return 0;
}

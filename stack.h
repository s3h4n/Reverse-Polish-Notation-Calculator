#ifndef STACK_H
#define STACK_H

#define MAX 100 // Maximum size of the stack

// Stack structure to store double values
typedef struct
{
    double data[MAX]; // Store double instead of int for correct division results
    int top;
} Stack;

// Function declarations
void initStack(Stack *s);
void push(Stack *s, double value);
double pop(Stack *s);
double peek(Stack *s);

#endif

#ifndef STACK_H
#define STACK_H
#define MAX 100 // Maximum size of the stack in RPN calculator

typedef struct {
    int data[MAX];
    int top;
} Stack;

// Function declarations
void initStack(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);

#endif
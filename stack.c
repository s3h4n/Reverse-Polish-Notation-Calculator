#include "stack.h"

void initStack(Stack *s) {
    s->top = -1; // Initialize the top of the stack to -1 in  (empty stack) in RPN calculator
}

void push(Stack *s, int value) {
    s->data[++(s->top)] = value; // Push the value onto the top of the stack of RPN calculator
}

int pop(Stack *s) {
    return s->data[(s->top)--]; // Pop and return the top value
}

int peek(Stack *s) {
    return s->data[s->top]; // Peek the top value without popping it
}
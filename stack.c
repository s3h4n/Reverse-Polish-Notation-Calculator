#include "stack.h"
#include <stdio.h>

// Initialize the stack
void initStack(Stack *s){
    s->top = -1; // Set top to -1 (empty stack)
}

// Push a value onto the stack with overflow check
void push(Stack *s, double value){
    if (s->top >= MAX - 1){
        printf("Error: Stack overflow. Cannot push value.\n");
    }
    else{
        s->data[++(s->top)] = value; // Push the double value onto the stack
    }
}

// Pop a value from the stack with underflow check
double pop(Stack *s){
    if (s->top == -1){
        printf("Error: Stack underflow. Cannot pop value.\n");
        return 0; // Return a default value
    }
    else{
        return s->data[(s->top)--]; // Pop and return the top value
    }
}

// Peek the top value of the stack without popping it
double peek(Stack *s){
    if (s->top == -1){
        printf("Error: Stack is empty. Cannot peek value.\n");
        return 0; // Return a default value
    }
    else{
        return s->data[s->top]; // Return the top value
    }
}

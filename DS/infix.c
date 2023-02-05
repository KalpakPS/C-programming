#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// Stack structure
struct Stack {
    int top;
    char items[MAX_SIZE];
};

// Function to initialize stack
void init(struct Stack *stack) {
    stack->top = -1;
}

// Function to push elements onto the stack
void push(struct Stack *stack, char x) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Error: stack overflow\n");
        return;
    }
    stack->items[++stack->top] = x;
}

// Function to pop elements from the stack
char pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Error: stack underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

// Function to return the precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(char *infix, char *postfix) {
    int i, j;
    struct Stack stack;
    init(&stack);
    for (i = 0, j = 0; i < strlen(infix); i++) {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z') {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        } else {
            while (stack.top != -1 && precedence(stack.items[stack.top]) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
    }
    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
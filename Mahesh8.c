#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
struct Stack {
    char arr[MAX];
    int top;
};
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}
void push(struct Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->arr[++stack->top] = value;
}
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        return -1;  
    }
    return stack->arr[stack->top--];
}
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;  
    }
    return stack->arr[stack->top];
    }
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '^') {
        return 3;
    }
    return -1;
}
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
void infixToPostfix(char* infix, char* postfix) {
    struct Stack stack;
    initializeStack(&stack);
    int k = 0;  
    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];
        if (isalnum(token)) {
            postfix[k++] = token;
        }
        else if (token == '(') {
            push(&stack, token);
        }
         postfix until '('
        else if (token == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack);  
        }
        else if (isOperator(token)) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(token)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, token);  /
        }
    }

    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }
    postfix[k] = '\0'; 
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);  
    / Convert the infix expression to postfix
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}

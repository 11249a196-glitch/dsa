#include <stdio.h>
#include <stdlib.h>
#define MAX 5  
struct Stack {
    int arr[MAX];
    int top;
};
void initializeStack(struct Stack* stack) {
    stack->top = -1;  
}
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Unable to push %d\n", value);
    } else {
        stack->arr[++stack->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Unable to pop\n");
        return -1;  
    } else {
        int poppedValue = stack->arr[stack->top--];
        return poppedValue;
    }
}
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Nothing to peek.\n");
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}
int main() {
    struct Stack stack;
    initializeStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60); 
    display(&stack);
    int poppedValue = pop(&stack);
    if (poppedValue != -1) {
        printf("Popped value: %d\n", poppedValue);
    }
    display(&stack);
    int topValue = peek(&stack);
    if (topValue != -1) {
        printf("Top value is: %d\n", topValue);
    }
    return 0;
}

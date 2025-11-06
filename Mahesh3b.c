#include <stdio.h>
#include <stdlib.h>
// Define a structure for Stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};
// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}
// Stack is full when the top is equal to the last index
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}
// Stack is empty when the top is -1
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
// Function to add an item to stack. It increases top by 1
void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = item;
}
// Function to remove an item from stack. It decreases top by 1
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return -1;  // Return a special character or error code if stack is empty
    }
    return stack->array[stack->top--];
}
// Function to check if the given character is an opening parenthesis
int isOpeningParenthesis(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}
// Function to check if the given character is a closing parenthesis
int isClosingParenthesis(char ch) {
    return ch == ')' || ch == ']' || ch == '}';
}
// Function to check if two parentheses are matching
int isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') || 
           (opening == '[' && closing == ']') || 
           (opening == '{' && closing == '}');
// Function to check if the parentheses in the given expression are balanced
int areParenthesesBalanced(char expr[]) {
    struct Stack* stack = createStack(strlen(expr));  // Create a stack to store opening parentheses
    // Traverse the expression
    for (int i = 0; expr[i]; i++) {
        // If the current character is an opening parenthesis, push it to the stack
        if (isOpeningParenthesis(expr[i])) {
            push(stack, expr[i]);
        } 
        // If the current character is a closing parenthesis
        else if (isClosingParenthesis(expr[i])) {
            // If the stack is empty or the top of the stack doesn't match the closing parenthesis
            if (isEmpty(stack) || !isMatchingPair(pop(stack), expr[i])) {
                free(stack->array);
                free(stack);
                return 0;  // Not balanced
            }
        }
    }
    // If the stack is empty, it means all parentheses matched correctly
    int result = isEmpty(stack);
    free(stack->array);
    free(stack);
    return result;
}
// Main function
int main() {

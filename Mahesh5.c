#include <stdio.h>
#include <stdlib.h>
// Define the structure of a Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to insert at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
// Function to insert at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
// Function to delete a node by value
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    // If the head node itself contains the data to be deleted
    if (temp != NULL && temp->data == data) {
        *head = temp->next;  // Change head to the next node
        free(temp);  // Free the old head
        printf("Node with value %d deleted.\n", data);
        return;
    }
    // Search for the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    // If data not found
    if (temp == NULL) {
        printf("Node with value %d not found.\n", data);
        return;
    }
    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", data);
}
// Function to display the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Function to search for a node by value
int search(struct Node* head, int data) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == data) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;  // If data is not found
}
int main() {
    struct Node* head = NULL;  // Initialize an empty list
    // Perform operations
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    // Display the list
    display(head);
    // Search for a value in the list
    int value = 20;
    int position = search(head, value);
    if (position != -1) {
        printf("Element %d found at position %d.\n", value, position);
    } else {
        printf("Element %d not found in the list.\n", value);
    }
    // Delete a node
    deleteNode(&head, 20);  // Delete node with value 20
    display(head);
    return 0;
}
    

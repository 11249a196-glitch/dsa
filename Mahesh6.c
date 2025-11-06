#include <stdio.h>
#include <stdlib.h>
// Define the structure for a Node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
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
    newNode->prev = NULL;
    return newNode;
}
// Function to insert at the beginning of the doubly linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}
// Function to insert at the end of the doubly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
// Function to delete a node by value
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("Node with value %d deleted.\n", data);
        return;
    }
    // Search for the node to be deleted
    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }
    // If the data is not found
    if (temp == NULL) {
        printf("Node with value %d not found.\n", data);
        return;
    }
    // Unlink the node from the list
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    free(temp);
    printf("Node with value %d deleted.\n", data);
}
// Function to display the doubly linked list forward
void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Doubly Linked List (Forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Function to display the doubly linked list backward
void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    // Go to the last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("Doubly Linked List (Backward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
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
    return -1;  // Return -1 if data is not found
}
int main() {
    struct Node* head = NULL;  // Initialize an empty list
    // Perform operations
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    // Display the list forward
    displayForward(head);
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
    // Display the list forward and backward
    displayForward(head);
    displayBackward(head);
    return 0;
}

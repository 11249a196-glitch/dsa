#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10
// Structure to represent a node in the linked list (used for separate chaining)
struct Node {
    int key;
    int value;
    struct Node* next;
};
// Structure to represent the hash table
struct HashTable {
    struct Node* table[TABLE_SIZE];  // Array of linked lists
};
// Hash function to map a key to an index in the table
int hashFunction(int key) {
    return key % TABLE_SIZE;
}
// Create a new node
struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
// Initialize the hash table
struct HashTable* createHashTable() {
    struct HashTable* newTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        newTable->table[i] = NULL;
    }
    return newTable;
}
// Insert a key-value pair into the hash table
void insert(struct HashTable* hashTable, int key, int value) {
    int index = hashFunction(key);
    struct Node* newNode = createNode(key, value);
    // Insert the new node at the beginning of the linked list at the index
    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;
}
// Search for a key in the hash table
int search(struct HashTable* hashTable, int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable->table[index];

    while (temp != NULL) {
        if (temp->key == key) {
            return temp->value;  // Return the value if the key is found
        }
        temp = temp->next;
    }
    return -1;  // Re

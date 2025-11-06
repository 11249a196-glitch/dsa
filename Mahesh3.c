#include <stdio.h>
// Function to perform linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index if the target is found
        }
    }
    return -1;  // Return -1 if the target is not found
}
int main() {
    // Example array
    int arr[] = {5, 3, 8, 6, 7, 2, 4};
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array
    // Ask user to input a target value
    int target;
    printf("Enter the number to search for: ");
    scanf("%d", &target);
    // Perform linear search
    int result = linearSearch(arr, size, target);
    // Output the result
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    return 0;
}

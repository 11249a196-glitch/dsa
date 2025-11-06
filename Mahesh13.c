#include <stdio.h>
#include <stdlib.h>
// Function to merge two halves of the array
void merge(int arr[], int left, int right) {
    // Base case: if there is only one element, no merge needed
    if (left == right) {
        return;
    }
    // Find the middle point of the array
    int mid = (left + right) / 2;
    // Recursively divide the array into two halves
    merge(arr, left, mid);          // Left half
    merge(arr, mid + 1, right);     // Right half
    // Merge the two halves
    int n1 = mid - left + 1;        // Size of left subarray
    int n2 = right - mid;           // Size of right subarray
    // Create temporary arrays
    int leftArr[n1], rightArr[n2];
    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    // Copy remaining elements of leftArr[] if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    // Copy remaining elements of rightArr[] if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Main function to test the Merge Sort
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);
    merge(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

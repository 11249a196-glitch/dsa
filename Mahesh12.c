#include <stdio.h>
// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Partition function to rearrange elements in the array
// It picks the last element as pivot and places it at its correct position
int partition(int arr[], int low, int high) {
    // Pivot is the last element
    int pivot = arr[high];
    // Pointer for the smaller element
    int i = (low - 1)
    // Loop through the array and swap elements that are smaller than pivot
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Swap the pivot element with the element at (i + 1)
    swap(&arr[i + 1], &arr[high]);
    // Return the partitioning index (position of pivot)
    return (i + 1);
}
// QuickSort function that recursively sorts the array
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);
        // Recursively sort the subarrays
        quickSort(arr, low, pi - 1); // Elements before the pivot
        quickSort(arr, pi + 1, high); // Elements after the pivot
    }
}
// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Main function
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

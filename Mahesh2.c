#include <stdio.h>
// Recursive binary search function
int binarySearch(int arr[], int left, int right, int target) {
    // Base condition: if the search range is invalid
    if (left > right) {
        return -1;  // Element not found
    }
    // Find the middle element
    int mid = left + (right - left) / 2;

    // Check if the target is present at mid
    if (arr[mid] == target) {
        return mid;  // Return the index of the target element
    }
    // If target is smaller than mid, search the left half
    if (arr[mid] > target) {
        return binarySearch(arr, left, mid - 1, target);
    }
    // If target is larger than mid, search the right half
    return binarySearch(arr, mid + 1, right, target);
}
int main() {
    // Example sorted array
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Target element to search for
    int target;
    printf("Enter the number to search for: ");
    scanf("%d", &target);
    // Call the recursive binary search function
    int result = binarySearch(arr, 0, n - 1, target);
    // Output the result
    if (result == -1) {
        printf("Element %d not found in the array.\n", target);
    } else {
        printf("Element %d found at index %d.\n", target, result);
    }
    return 0;
}

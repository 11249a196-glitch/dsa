# Function to perform linear search
def linear_search(arr, target):
    # Iterate through the list
    for i in range(len(arr)):
        if arr[i] == target:
            return i  # Return the index of the target element
    return -1  # Return -1 if the element is not found

# Main part to test the function
if __name__ == "__main__":
    # Example list
    arr = [5, 3, 8, 6, 7, 2, 4]
    
    # Target value to search for
    target = int(input("Enter the number to search for: "))
    
    # Perform the search
    result = linear_search(arr, target)
    
    # Output the result
    if result != -1:
        print(f"Element {target} found at index {result}.")
    else:
        print(f"Element {target} not found in the list.")

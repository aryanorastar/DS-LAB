#include <iostream>

/**
 * @brief Performs an iterative binary search on a sorted array.
 * @param arr The sorted integer array to search in.
 * @param size The number of elements in the array.
 * @param key The integer value to search for.
 * @return The index of the key if found; otherwise, -1.
 */
int binarySearch(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;

    // The loop continues as long as there is a valid search space.
    while (low <= high) {
        // Calculate the middle index.
        // This way is better than (low + high) / 2 to prevent potential overflow.
        int mid = low + (high - low) / 2;

        // Case 1: The middle element is our key.
        if (arr[mid] == key) {
            return mid; // Found it! 🎉
        }
        
        // Case 2: The middle element is smaller than our key.
        // This means the key must be in the right half of the array.
        else if (arr[mid] < key) {
            low = mid + 1; // Discard the left half.
        } 
        
        // Case 3: The middle element is larger than our key.
        // This means the key must be in the left half of the array.
        else {
            high = mid - 1; // Discard the right half.
        }
    }

    // If the loop finishes, the key was not in the array.
    return -1;
}


int main() {
    int sorted_array[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int n = sizeof(sorted_array) / sizeof(sorted_array[0]);
    int key_to_find;

    std::cout << "Sorted array is: [ ";
    for(int i = 0; i < n; ++i) {
        std::cout << sorted_array[i] << " ";
    }
    std::cout << "]\n";
    
    std::cout << "Enter a number to search for: ";
    std::cin >> key_to_find;

    int result_index = binarySearch(sorted_array, n, key_to_find);

    if (result_index != -1) {
        std::cout << "✅ Element found at index: " << result_index << std::endl;
    } else {
        std::cout << "❌ Element not found in the array." << std::endl;
    }

    return 0;
}
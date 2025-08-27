#include <iostream>
#include <utility> // Required for std::swap

// A helper function to print the elements of an array.
void printArray(int arr[], int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

/**
 * @brief Sorts an array using the optimized Bubble Sort algorithm.
 * @param arr The integer array to be sorted.
 * @param n The number of elements in the array.
 */
void bubbleSort(int arr[], int n) {
    // The outer loop controls the number of passes through the array.
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        // The inner loop compares adjacent elements.
        // After each pass 'i', the largest 'i' elements are already at the end,
        // so the inner loop's range shrinks by 'i'.
        for (int j = 0; j < n - i - 1; j++) {
            // If the element found is greater than the next element, swap them.
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // OPTIMIZATION: If the inner loop completed a full pass
        // without making any swaps, the array is already sorted.
        // We can stop early.
        if (!swapped) {
            break;
        }
    }
}

int main() {
    // The specific array of elements to be sorted.
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    std::cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}
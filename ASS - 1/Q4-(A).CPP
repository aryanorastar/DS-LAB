#include <iostream>
#include <utility> // For std::swap

// Function to print the elements of an array
void printArray(int arr[], int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

// Function to reverse an array in-place
void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    // Loop until the two pointers meet or cross each other
    while (start < end) {
        // Swap the elements at the start and end positions
        std::swap(arr[start], arr[end]);

        // Move the pointers towards the center
        start++;
        end--;
    }
}

int main() {
    int my_array[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(my_array) / sizeof(my_array[0]);

    std::cout << "Original array: ";
    printArray(my_array, n);

    reverseArray(my_array, n);

    std::cout << "Reversed array: ";
    printArray(my_array, n);

    return 0;
}
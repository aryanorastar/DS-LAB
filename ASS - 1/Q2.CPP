#include <iostream>
#include <algorithm>

/**
 * @brief Removes duplicate elements from a sorted integer array in-place.
 * * @param arr The integer array.
 * @param n The number of elements in the array.
 * @return The new size of the array after duplicates are removed.
 */
int removeDuplicates(int arr[], int n) {
    if (n <= 1) {
        return n;
    }

    std::sort(arr, arr + n);
    int write_index = 1; 

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[write_index] = arr[i];
            write_index++;
        }
    }

    return write_index;
}

void printArray(int arr[], int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int main() {
    int my_array[] = {2, 7, 2, 3, 8, 7, 3, 9, 3};
    int size = sizeof(my_array) / sizeof(my_array[0]);

    std::cout << "Original array: ";
    printArray(my_array, size);

    int new_size = removeDuplicates(my_array, size);

    std::cout << "Array after removing duplicates: ";
    printArray(my_array, new_size);

    return 0;
}
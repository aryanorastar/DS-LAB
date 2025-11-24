#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * Counting Sort for a specific digit (used by Radix Sort)
 */
void countingSortByDigit(int arr[], int n, int exp) {
    vector<int> output(n);
    vector<int> count(10, 0);
    
    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    // Change count[i] so that count[i] contains actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Copy the output array to arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

/**
 * Radix Sort Algorithm
 * Time Complexity: O(d * (n + k)) where d is number of digits,
 *                  n is number of elements, k is the range (0-9)
 * Space Complexity: O(n + k)
 * 
 * Radix sort sorts numbers digit by digit, starting from the
 * least significant digit to the most significant digit.
 */
void radixSort(int arr[], int n) {
    // Find the maximum number to know number of digits
    int maxVal = *max_element(arr, arr + n);
    
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortByDigit(arr, n, exp);
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    radixSort(arr, n);
    
    cout << "Sorted array:   ";
    printArray(arr, n);
    
    return 0;
}


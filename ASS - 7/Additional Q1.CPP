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
 * Counting Sort Algorithm
 * Time Complexity: O(n + k) where k is the range of input
 * Space Complexity: O(k)
 * 
 * Counting sort is efficient when the range of input data (k) is not
 * significantly greater than the number of elements (n).
 */
void countingSort(int arr[], int n) {
    // Find the maximum element to determine the range
    int maxVal = *max_element(arr, arr + n);
    int minVal = *min_element(arr, arr + n);
    int range = maxVal - minVal + 1;
    
    // Create count array to store count of each element
    vector<int> count(range, 0);
    
    // Store count of each element
    for (int i = 0; i < n; i++) {
        count[arr[i] - minVal]++;
    }
    
    // Modify count array to store actual position of elements
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    
    // Create output array
    vector<int> output(n);
    
    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }
    
    // Copy the output array back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1, 7, 5, 6, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    countingSort(arr, n);
    
    cout << "Sorted array:   ";
    printArray(arr, n);
    
    return 0;
}


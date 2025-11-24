#include <iostream>
#include <algorithm>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/**
 * Improved Selection Sort
 * In each pass, finds both minimum and maximum elements
 * and places them at their correct positions from both ends
 */
void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;
    
    while (left < right) {
        int minIndex = left;
        int maxIndex = left;
        
        // Find minimum and maximum in the current range
        for (int i = left + 1; i <= right; i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
        
        // Place minimum at the left end
        if (minIndex != left) {
            swap(arr[left], arr[minIndex]);
            
            // If maximum was at left position, update maxIndex
            // because we just swapped it
            if (maxIndex == left) {
                maxIndex = minIndex;
            }
        }
        
        // Place maximum at the right end
        if (maxIndex != right) {
            swap(arr[right], arr[maxIndex]);
        }
        
        // Move boundaries inward
        left++;
        right--;
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 5, 77, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original array: ";
    printArray(arr, n);
    
    improvedSelectionSort(arr, n);
    
    cout << "Sorted array:   ";
    printArray(arr, n);
    
    return 0;
}


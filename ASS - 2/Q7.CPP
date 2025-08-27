#include <iostream>
#include <vector>

/**
 * @brief Merges two sorted subarrays and counts the inversions between them.
 * @param arr The main array being sorted.
 * @param temp A temporary array for merging.
 * @param left The starting index of the left subarray.
 * @param mid The ending index of the left subarray.
 * @param right The ending index of the right subarray.
 * @return The number of inversions between the two halves.
 */
long long mergeAndCount(std::vector<int>& arr, std::vector<int>& temp, int left, int mid, int right) {
    int i = left;       // Starting index for the left subarray
    int j = mid + 1;    // Starting index for the right subarray
    int k = left;       // Starting index for the merged temporary array
    long long inv_count = 0;

    // Compare elements from both halves and merge them in sorted order.
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // If arr[i] > arr[j], then it's an inversion.
            // Since the left half (from i to mid) is sorted, all of its
            // remaining elements are also greater than arr[j].
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    // Copy any remaining elements from the left half.
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy any remaining elements from the right half.
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the sorted, merged elements back to the original array.
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

/**
 * @brief Recursively sorts the array using merge sort and counts inversions.
 * @param arr The array to be sorted.
 * @param temp A temporary helper array.
 * @param left The starting index of the array/subarray.
 * @param right The ending index of the array/subarray.
 * @return The total number of inversions.
 */
long long mergeSortAndCount(std::vector<int>& arr, std::vector<int>& temp, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Count inversions in the left half.
        inv_count += mergeSortAndCount(arr, temp, left, mid);

        // Count inversions in the right half.
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        // Count inversions between the two halves during the merge step.
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    std::vector<int> arr = {8, 4, 2, 1};
    std::cout << "Original array: ";
    for(int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    // Create a temporary array for the merge process.
    std::vector<int> temp(arr.size());
    long long inversions = mergeSortAndCount(arr, temp, 0, arr.size() - 1);
    
    std::cout << "Total number of inversions: " << inversions << std::endl;

    std::cout << "Sorted array: ";
    for(int num : arr) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}
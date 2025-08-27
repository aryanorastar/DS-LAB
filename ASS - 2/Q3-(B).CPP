#include <iostream>
#include <vector>

/**
 * @brief Finds the missing number using binary search O(log n).
 * @param nums A sorted vector of n-1 distinct integers from 1 to n.
 * @return The missing integer.
 */
int findMissingBinarySearch(const std::vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;
    int missing_num = nums.size() + 1; // Default to n

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If the element at mid is in its correct place...
        if (nums[mid] == mid + 1) {
            // ...then the mismatch must be in the right half.
            low = mid + 1;
        } else {
            // ...otherwise, this could be the missing number.
            // We store it as a potential answer and check
            // the left half for an even earlier mismatch.
            missing_num = mid + 1;
            high = mid - 1;
        }
    }
    return missing_num;
}


int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 6, 7, 8}; // Missing 5
    std::cout << "Array: {1, 2, 3, 4, 6, 7, 8}" << std::endl;
    std::cout << "Missing number (binary search): " << findMissingBinarySearch(arr1) << std::endl;

    std::vector<int> arr2 = {2, 3, 4, 5}; // n=5, missing 1
    std::cout << "\nArray: {2, 3, 4, 5}" << std::endl;
    std::cout << "Missing number (binary search): " << findMissingBinarySearch(arr2) << std::endl;

    return 0;
}
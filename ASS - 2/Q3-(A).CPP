#include <iostream>
#include <vector>

/**
 * @brief Finds the missing number in linear time O(n).
 * @param nums A sorted vector of n-1 distinct integers from 1 to n.
 * @return The missing integer.
 */
int findMissingLinear(const std::vector<int>& nums) {
    int n = nums.size() + 1; // n is the expected size (1 to n).

    // In a perfect array, the element at index 'i' should be 'i + 1'.
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1) {
            // We found the first mismatch, so i+1 is the missing number.
            return i + 1;
        }
    }

    // If the loop completes, it means all elements from 1 to n-1 are present.
    // The missing number must be 'n' itself.
    return n;
}

int main() {
    std::vector<int> arr1 = {1, 2, 3, 4, 6, 7, 8}; // Missing 5
    std::cout << "Array: {1, 2, 3, 4, 6, 7, 8}" << std::endl;
    std::cout << "Missing number (linear): " << findMissingLinear(arr1) << std::endl;

    std::vector<int> arr2 = {1, 2, 3, 4, 5}; // n=6, missing 6
    std::cout << "\nArray: {1, 2, 3, 4, 5}" << std::endl;
    std::cout << "Missing number (linear): " << findMissingLinear(arr2) << std::endl;
    
    return 0;
}
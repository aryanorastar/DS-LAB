#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

int countDistinct(std::vector<int>& arr) {
    // An empty array has 0 distinct elements.
    if (arr.empty()) {
        return 0;
    }

    // 1. Sort the array. This brings all identical elements next to each other.
    std::sort(arr.begin(), arr.end());

    // 2. Iterate and count.
    int distinct_count = 1; // At least one distinct element exists.
    for (size_t i = 1; i < arr.size(); ++i) {
        // If the current element is different from the previous one, it's a new distinct element.
        if (arr[i] != arr[i - 1]) {
            distinct_count++;
        }
    }
    return distinct_count;
}

int main() {
    std::vector<int> arr = {10, 20, 20, 10, 30, 10, 40, 40};
    
    std::cout << "Original array: ";
    for(int num : arr) std::cout << num << " ";
    std::cout << std::endl;
    
    int count = countDistinct(arr);

    std::cout << "Total number of distinct elements: " << count << std::endl;

    return 0;
}
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Find first non-repeating element in array using hash map
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int firstNonRepeating(vector<int>& arr) {
    unordered_map<int, int> count;
    
    // Count frequency of each element
    for (int num : arr) {
        count[num]++;
    }
    
    // Find first element with count == 1
    for (int num : arr) {
        if (count[num] == 1) {
            return num;
        }
    }
    
    return -1; // No non-repeating element found
}

int main() {
    vector<int> arr = {4, 5, 1, 2, 0, 4};
    
    cout << "Input: [4, 5, 1, 2, 0, 4]" << endl;
    cout << "Output: " << firstNonRepeating(arr) << endl;
    
    return 0;
}


#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Check if there exists a pair whose sum equals target
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
bool hasPairWithSum(vector<int>& arr, int target) {
    unordered_set<int> seen;
    
    for (int num : arr) {
        int complement = target - num;
        
        // Check if complement exists in set
        if (seen.find(complement) != seen.end()) {
            return true;
        }
        
        // Add current number to set
        seen.insert(num);
    }
    
    return false;
}

int main() {
    // Test case 1
    vector<int> arr1 = {0, -1, 2, -3, 1};
    int target1 = -2;
    cout << "Input: arr[] = [0, -1, 2, -3, 1], target = -2" << endl;
    cout << "Output: " << (hasPairWithSum(arr1, target1) ? "true" : "false") << endl;
    cout << "Explanation: There is a pair (1, -3) with the sum equal to given target, 1 + (-3) = -2." << endl;
    cout << endl;
    
    // Test case 2
    vector<int> arr2 = {1, -2, 1, 0, 5};
    int target2 = 0;
    cout << "Input: arr[] = [1, -2, 1, 0, 5], target = 0" << endl;
    cout << "Output: " << (hasPairWithSum(arr2, target2) ? "true" : "false") << endl;
    cout << "Explanation: There is no pair with sum equals to given target." << endl;
    
    return 0;
}


#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Check if array contains duplicates using hash set
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;
        }
        seen.insert(num);
    }
    
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    
    cout << "Input: [1, 2, 3, 1]" << endl;
    cout << "Output: " << (containsDuplicate(nums) ? "true" : "false") << endl;
    
    return 0;
}


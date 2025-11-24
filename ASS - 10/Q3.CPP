#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Count frequency of each number in array using hash map
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
void countFrequency(vector<int>& nums) {
    unordered_map<int, int> freq;
    
    // Count frequency of each element
    for (int num : nums) {
        freq[num]++;
    }
    
    // Print frequencies
    for (auto& pair : freq) {
        cout << pair.first << " → " << pair.second << " time";
        if (pair.second > 1) cout << "s";
        cout << endl;
    }
}

int main() {
    vector<int> nums = {2, 3, 2, 4, 3, 2};
    
    cout << "Input: [2, 3, 2, 4, 3, 2]" << endl;
    cout << "Output:" << endl;
    countFrequency(nums);
    
    return 0;
}


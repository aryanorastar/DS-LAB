#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Find element that appears most frequently
 * If multiple elements have same highest frequency, return the largest
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
int mostFrequentElement(vector<int>& arr) {
    unordered_map<int, int> freq;
    
    // Count frequency of each element
    for (int num : arr) {
        freq[num]++;
    }
    
    int maxFreq = 0;
    int result = INT_MIN;
    
    // Find element with maximum frequency
    // If tie, choose the largest value
    for (auto& pair : freq) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            result = pair.first;
        } else if (pair.second == maxFreq && pair.first > result) {
            result = pair.first;
        }
    }
    
    return result;
}

int main() {
    // Test case 1
    vector<int> arr1 = {1, 3, 2, 1, 4, 1};
    cout << "Input: [1, 3, 2, 1, 4, 1]" << endl;
    cout << "Output: " << mostFrequentElement(arr1) << endl;
    cout << "Explanation: 1 appears three times in array which is maximum frequency." << endl;
    cout << endl;
    
    // Test case 2
    vector<int> arr2 = {10, 20, 10, 20, 30, 20, 20};
    cout << "Input: [10, 20, 10, 20, 30, 20, 20]" << endl;
    cout << "Output: " << mostFrequentElement(arr2) << endl;
    cout << "Explanation: 20 appears four times in array which is maximum frequency." << endl;
    cout << endl;
    
    // Test case 3
    vector<int> arr3 = {1, 2, 2, 4, 1};
    cout << "Input: [1, 2, 2, 4, 1]" << endl;
    cout << "Output: " << mostFrequentElement(arr3) << endl;
    cout << "Explanation: 1 and 2 both appear two times, so return 2 as it's value is bigger." << endl;
    
    return 0;
}


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Check if two arrays are equal
 * Two arrays are equal if they contain same set of elements with same counts
 * Time Complexity: O(n + m)
 * Space Complexity: O(n)
 */
bool areArraysEqual(vector<int>& a, vector<int>& b) {
    // If sizes are different, arrays can't be equal
    if (a.size() != b.size()) {
        return false;
    }
    
    unordered_map<int, int> count;
    
    // Count frequency of elements in first array
    for (int num : a) {
        count[num]++;
    }
    
    // Decrement count for elements in second array
    for (int num : b) {
        if (count.find(num) == count.end()) {
            // Element not found in first array
            return false;
        }
        count[num]--;
        if (count[num] == 0) {
            count.erase(num);
        }
    }
    
    // If count map is empty, all elements matched
    return count.empty();
}

int main() {
    // Test case 1
    vector<int> a1 = {1, 2, 5, 4, 0};
    vector<int> b1 = {2, 4, 5, 0, 1};
    cout << "Input: a[] = [1, 2, 5, 4, 0], b[] = [2, 4, 5, 0, 1]" << endl;
    cout << "Output: " << (areArraysEqual(a1, b1) ? "true" : "false") << endl;
    cout << endl;
    
    // Test case 2
    vector<int> a2 = {1, 2, 5, 4, 0, 2, 1};
    vector<int> b2 = {2, 4, 5, 0, 1, 1, 2};
    cout << "Input: a[] = [1, 2, 5, 4, 0, 2, 1], b[] = [2, 4, 5, 0, 1, 1, 2]" << endl;
    cout << "Output: " << (areArraysEqual(a2, b2) ? "true" : "false") << endl;
    cout << endl;
    
    // Test case 3
    vector<int> a3 = {1, 7, 1};
    vector<int> b3 = {7, 7, 1};
    cout << "Input: a[] = [1, 7, 1], b[] = [7, 7, 1]" << endl;
    cout << "Output: " << (areArraysEqual(a3, b3) ? "true" : "false") << endl;
    
    return 0;
}


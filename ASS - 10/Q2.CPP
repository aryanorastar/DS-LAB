#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Find common elements in two arrays using hash set
 * Time Complexity: O(n + m)
 * Space Complexity: O(min(n, m))
 */
vector<int> findCommonElements(vector<int>& A, vector<int>& B) {
    unordered_set<int> setA(A.begin(), A.end());
    vector<int> common;
    
    for (int num : B) {
        if (setA.find(num) != setA.end()) {
            common.push_back(num);
            // Remove to avoid duplicates in output
            setA.erase(num);
        }
    }
    
    return common;
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};
    
    cout << "Input:" << endl;
    cout << "A = [1, 2, 3, 4]" << endl;
    cout << "B = [3, 4, 5, 6]" << endl;
    
    vector<int> common = findCommonElements(A, B);
    
    cout << "Output: ";
    for (int i = 0; i < common.size(); i++) {
        cout << common[i];
        if (i < common.size() - 1) cout << ", ";
    }
    cout << endl;
    
    return 0;
}


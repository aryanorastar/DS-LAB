#include <iostream>
#include <unordered_set>

using namespace std;

// Definition for binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * Check if binary tree contains duplicate values using hash set
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
bool hasDuplicates(TreeNode* root, unordered_set<int>& seen) {
    if (root == nullptr) {
        return false;
    }
    
    // Check if current node's value is already seen
    if (seen.find(root->val) != seen.end()) {
        return true;
    }
    
    // Add current value to set
    seen.insert(root->val);
    
    // Recursively check left and right subtrees
    return hasDuplicates(root->left, seen) || hasDuplicates(root->right, seen);
}

bool checkDuplicates(TreeNode* root) {
    unordered_set<int> seen;
    return hasDuplicates(root, seen);
}

int main() {
    // Create a binary tree
    // Example: 
    //       5
    //      / \
    //     3   3
    //    / \
    //   2   4
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    
    cout << "Binary tree structure:" << endl;
    cout << "       5" << endl;
    cout << "      / \\" << endl;
    cout << "     3   3" << endl;
    cout << "    / \\" << endl;
    cout << "   2   4" << endl;
    cout << endl;
    
    if (checkDuplicates(root)) {
        cout << "Output: Duplicates Found" << endl;
    } else {
        cout << "Output: No Duplicates" << endl;
    }
    
    // Clean up
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
    
    return 0;
}


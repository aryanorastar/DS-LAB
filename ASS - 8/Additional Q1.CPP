#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

int sumOfLeftLeaves(Node* root, bool isLeft = false) {
    if (root == nullptr) {
        return 0;
    }

    // Check if it's a left leaf
    if (root->left == nullptr && root->right == nullptr && isLeft) {
        return root->data;
    }

    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Create sample tree
    //       3
    //      / \
    //     9   20
    //        /  \
    //       15   7
    
    Node* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    cout << "Binary Tree: ";
    inorder(root);
    cout << endl;

    int sum = sumOfLeftLeaves(root);
    cout << "Sum of left leaves: " << sum << endl;

    return 0;
}


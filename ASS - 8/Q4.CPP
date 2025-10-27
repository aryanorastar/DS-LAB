#include <iostream>
#include <climits>

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

bool isBSTUtil(Node* root, int min, int max) {
    if (root == nullptr) {
        return true;
    }

    if (root->data < min || root->data > max) {
        return false;
    }

    return isBSTUtil(root->left, min, root->data - 1) &&
           isBSTUtil(root->right, root->data + 1, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Create BST
    Node* bst = createNode(50);
    bst->left = createNode(30);
    bst->right = createNode(70);
    bst->left->left = createNode(20);
    bst->left->right = createNode(40);
    bst->right->left = createNode(60);
    bst->right->right = createNode(80);

    cout << "Tree 1 (BST): ";
    inorder(bst);
    cout << endl;
    cout << "Is BST: " << (isBST(bst) ? "Yes" : "No") << endl;

    // Create non-BST
    Node* notBST = createNode(3);
    notBST->left = createNode(2);
    notBST->right = createNode(5);
    notBST->left->left = createNode(1);
    notBST->left->right = createNode(4);

    cout << "\nTree 2 (Non-BST): ";
    inorder(notBST);
    cout << endl;
    cout << "Is BST: " << (isBST(notBST) ? "Yes" : "No") << endl;

    return 0;
}


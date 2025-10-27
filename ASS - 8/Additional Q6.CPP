#include <iostream>
#include <vector>

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

Node* buildTreeInPost(vector<int>& inorder, vector<int>& postorder, int& postIndex, int inStart, int inEnd) {
    if (inStart > inEnd) {
        return nullptr;
    }

    Node* root = createNode(postorder[postIndex--]);

    // Find root in inorder
    int inIndex;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->data) {
            inIndex = i;
            break;
        }
    }

    // Recursively build right subtree first (because postorder)
    root->right = buildTreeInPost(inorder, postorder, postIndex, inIndex + 1, inEnd);
    root->left = buildTreeInPost(inorder, postorder, postIndex, inStart, inIndex - 1);

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> inorder(n);
    vector<int> postorder(n);

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    cout << "Enter postorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> postorder[i];
    }

    int postIndex = n - 1;
    Node* root = buildTreeInPost(inorder, postorder, postIndex, 0, n - 1);

    cout << "\nConstructed tree - Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Constructed tree - Postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}


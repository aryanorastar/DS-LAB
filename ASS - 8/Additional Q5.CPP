#include <iostream>
#include <vector>
#include <map>

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

Node* buildTreePreIn(vector<int>& preorder, vector<int>& inorder, int& preIndex, int inStart, int inEnd) {
    if (inStart > inEnd) {
        return nullptr;
    }

    Node* root = createNode(preorder[preIndex++]);

    // Find root in inorder
    int inIndex;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->data) {
            inIndex = i;
            break;
        }
    }

    root->left = buildTreePreIn(preorder, inorder, preIndex, inStart, inIndex - 1);
    root->right = buildTreePreIn(preorder, inorder, preIndex, inIndex + 1, inEnd);

    return root;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> preorder(n);
    vector<int> inorder(n);

    cout << "Enter preorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }

    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }

    int preIndex = 0;
    Node* root = buildTreePreIn(preorder, inorder, preIndex, 0, n - 1);

    cout << "\nConstructed tree - Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Constructed tree - Inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}


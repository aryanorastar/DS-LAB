#include <iostream>
#include <vector>

using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
};

BSTNode* createBSTNode(int data) {
    BSTNode* newNode = new BSTNode;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

DLLNode* createDLLNode(int data) {
    DLLNode* newNode = new DLLNode;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

BSTNode* insertBST(BSTNode* root, int data) {
    if (root == nullptr) {
        return createBSTNode(data);
    }

    if (data < root->data) {
        root->left = insertBST(root->left, data);
    } else if (data > root->data) {
        root->right = insertBST(root->right, data);
    }

    return root;
}

void inorderTraversal(BSTNode* root, vector<int>& result) {
    if (root == nullptr) return;
    inorderTraversal(root->left, result);
    result.push_back(root->data);
    inorderTraversal(root->right, result);
}

void inorder(BSTNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

DLLNode* mergeBSTsToDLL(BSTNode* root1, BSTNode* root2) {
    vector<int> inorder1, inorder2;
    
    inorderTraversal(root1, inorder1);
    inorderTraversal(root2, inorder2);

    // Merge two sorted arrays
    vector<int> merged;
    int i = 0, j = 0;
    while (i < inorder1.size() && j < inorder2.size()) {
        if (inorder1[i] < inorder2[j]) {
            merged.push_back(inorder1[i++]);
        } else {
            merged.push_back(inorder2[j++]);
        }
    }

    while (i < inorder1.size()) {
        merged.push_back(inorder1[i++]);
    }

    while (j < inorder2.size()) {
        merged.push_back(inorder2[j++]);
    }

    // Create doubly linked list
    DLLNode* head = nullptr;
    DLLNode* tail = nullptr;

    for (int val : merged) {
        DLLNode* newNode = createDLLNode(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    return head;
}

void displayDLL(DLLNode* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    DLLNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << " <-> null" << endl;
}

int main() {
    BSTNode* root1 = nullptr;
    BSTNode* root2 = nullptr;

    // Build first BST
    cout << "Building first BST (e.g., 20 10 30 25 100)..." << endl;
    root1 = insertBST(root1, 20);
    root1 = insertBST(root1, 10);
    root1 = insertBST(root1, 30);
    root1 = insertBST(root1, 25);
    root1 = insertBST(root1, 100);

    // Build second BST
    cout << "Building second BST (e.g., 50 5 70)..." << endl;
    root2 = insertBST(root2, 50);
    root2 = insertBST(root2, 5);
    root2 = insertBST(root2, 70);

    cout << "\nBST 1 (inorder): ";
    inorder(root1);
    cout << endl;

    cout << "BST 2 (inorder): ";
    inorder(root2);
    cout << endl;

    DLLNode* mergedDLL = mergeBSTsToDLL(root1, root2);

    cout << "\nMerged Doubly Linked List: ";
    displayDLL(mergedDLL);

    return 0;
}


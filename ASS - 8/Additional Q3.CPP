#include <iostream>
#include <queue>

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

int maxDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}

// Level order approach for testing
Node* buildFromLevelOrder(vector<int>& arr, int n) {
    if (n == 0 || arr[0] == -1) {
        return nullptr;
    }

    Node* root = createNode(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < n) {
        Node* current = q.front();
        q.pop();

        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            q.push(current->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    cout << "Enter number of nodes (including NULL): ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter tree elements (level order, -1 for NULL): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = buildFromLevelOrder(arr, n);

    int depth = maxDepth(root);
    cout << "\nMaximum depth: " << depth << endl;

    return 0;
}


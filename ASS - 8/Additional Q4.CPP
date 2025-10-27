#include <iostream>
#include <queue>
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

vector<int> rightView(Node* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* current = q.front();
            q.pop();

            if (i == size - 1) {
                result.push_back(current->data);
            }

            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
    }

    return result;
}

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

    vector<int> result = rightView(root);

    cout << "Right view: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}


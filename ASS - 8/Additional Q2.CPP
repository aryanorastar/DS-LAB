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

vector<Node*> generateTrees(int start, int end) {
    vector<Node*> trees;

    if (start > end) {
        trees.push_back(nullptr);
        return trees;
    }

    for (int i = start; i <= end; i++) {
        vector<Node*> leftSubtrees = generateTrees(start, i - 1);
        vector<Node*> rightSubtrees = generateTrees(i + 1, end);

        for (Node* left : leftSubtrees) {
            for (Node* right : rightSubtrees) {
                Node* root = createNode(i);
                root->left = left;
                root->right = right;
                trees.push_back(root);
            }
        }
    }

    return trees;
}

vector<Node*> generateUniqueBSTs(int n) {
    if (n == 0) {
        return vector<Node*>();
    }
    return generateTrees(1, n);
}

void inorder(Node* root, vector<int>& result) {
    if (root == nullptr) {
        result.push_back(-1);
        return;
    }
    inorder(root->left, result);
    result.push_back(root->data);
    inorder(root->right, result);
}

void printTree(Node* root) {
    vector<int> result;
    inorder(root, result);
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == -1) {
            cout << "null";
        } else {
            cout << result[i];
        }
        if (i < result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]";
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<Node*> trees = generateUniqueBSTs(n);

    cout << "\nNumber of unique BSTs with " << n << " nodes: " << trees.size() << endl;
    cout << "\nAll unique BSTs:\n" << endl;

    for (int i = 0; i < trees.size(); i++) {
        cout << "Tree " << (i + 1) << ": ";
        printTree(trees[i]);
        cout << endl;
    }

    return 0;
}


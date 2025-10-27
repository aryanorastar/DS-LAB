#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
};

Node* matrixToDLL(int** matrix, int rows, int cols) {
    if (matrix == nullptr || rows == 0 || cols == 0) {
        return nullptr;
    }

    // Create all nodes
    Node*** nodeMatrix = new Node**[rows];
    for (int i = 0; i < rows; i++) {
        nodeMatrix[i] = new Node*[cols];
        for (int j = 0; j < cols; j++) {
            nodeMatrix[i][j] = new Node;
            nodeMatrix[i][j]->data = matrix[i][j];
            nodeMatrix[i][j]->next = nullptr;
            nodeMatrix[i][j]->prev = nullptr;
            nodeMatrix[i][j]->up = nullptr;
            nodeMatrix[i][j]->down = nullptr;
        }
    }

    // Connect next and prev pointers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j < cols - 1) {
                nodeMatrix[i][j]->next = nodeMatrix[i][j + 1];
            }
            if (j > 0) {
                nodeMatrix[i][j]->prev = nodeMatrix[i][j - 1];
            }
        }
    }

    // Connect up and down pointers
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            if (i > 0) {
                nodeMatrix[i][j]->up = nodeMatrix[i - 1][j];
            }
            if (i < rows - 1) {
                nodeMatrix[i][j]->down = nodeMatrix[i + 1][j];
            }
        }
    }

    return nodeMatrix[0][0];
}

void displayDLL(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* rowStart = head;
    while (rowStart != nullptr) {
        Node* current = rowStart;
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout << endl;

        if (rowStart->down != nullptr) {
            cout << "  |   ";
            current = rowStart;
            while (current->next != nullptr) {
                current = current->next;
                cout << " |    ";
            }
            cout << endl;
            cout << "  v   ";
            current = rowStart;
            while (current->next != nullptr) {
                current = current->next;
                cout << " v    ";
            }
            cout << endl;
        }

        rowStart = rowStart->down;
    }
}

void displayCompact(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* rowStart = head;
    while (rowStart != nullptr) {
        Node* current = rowStart;
        cout << "[";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << ", ";
            }
            current = current->next;
        }
        cout << "]" << endl;
        rowStart = rowStart->down;
    }
}

int main() {
    int rows, cols;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Allocate and initialize matrix
    int** matrix = new int*[rows];
    cout << "\nEnter matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    Node* head = matrixToDLL(matrix, rows, cols);

    cout << "\nDoubly Linked List representation:" << endl;
    displayCompact(head);

    return 0;
}


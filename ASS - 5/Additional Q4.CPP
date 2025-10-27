#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertEnd(Node*& head, int data) {
    if (head == nullptr) {
        head = createNode(data);
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = createNode(data);
}

Node* rotateLeft(Node* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) {
        return head;
    }

    int length = 1;
    Node* tail = head;

    // Find length and last node
    while (tail->next != nullptr) {
        length++;
        tail = tail->next;
    }

    // If k >= length, reduce k
    k = k % length;
    if (k == 0) {
        return head;
    }

    // Find the (k-1)th node from beginning
    Node* current = head;
    for (int i = 0; i < k - 1; i++) {
        current = current->next;
    }

    // Split the list
    Node* newHead = current->next;
    current->next = nullptr;

    // Connect last node to original head
    tail->next = head;

    return newHead;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, value, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(head, value);
    }

    cout << "Enter k (left rotation positions): ";
    cin >> k;

    cout << "\nOriginal Linked List: ";
    display(head);

    head = rotateLeft(head, k);

    cout << "Rotated Linked List: ";
    display(head);

    // Free memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


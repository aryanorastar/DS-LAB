#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* reverseKGroup(Node* head, int k) {
    if (head == nullptr || k == 1) {
        return head;
    }

    Node* current = head;
    int count = 0;

    // Check if there are k nodes
    while (current != nullptr && count < k) {
        current = current->next;
        count++;
    }

    // If less than k nodes, don't reverse
    if (count < k) {
        return head;
    }

    // Reverse k nodes
    current = head;
    Node* prev = nullptr;
    Node* next = nullptr;

    for (int i = 0; i < k && current != nullptr; i++) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }

    // Recursively reverse remaining nodes
    if (current != nullptr) {
        head->next = reverseKGroup(current, k);
        if (head->next != nullptr) {
            head->next->prev = head;
        }
    } else {
        head->next = nullptr;
    }

    return prev;
}

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertEnd(Node*& head, int data) {
    Node* newNode = createNode(data);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << " <-> NULL" << endl;
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

    cout << "Enter k (group size): ";
    cin >> k;

    cout << "\nOriginal Doubly Linked List: ";
    display(head);

    head = reverseKGroup(head, k);

    cout << "\nAfter reversing in groups of " << k << ": ";
    display(head);

    return 0;
}


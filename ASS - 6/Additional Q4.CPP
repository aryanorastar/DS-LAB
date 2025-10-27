#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* random;
};

void correctRandomPointer(Node* head) {
    if (head == nullptr) {
        return;
    }

    Node* current = head;

    // Find the node with incorrect random pointer
    while (current != nullptr) {
        Node* temp = head;

        // Check if random pointer points to a valid node in the list
        bool found = false;
        while (temp != nullptr) {
            if (current->random == temp) {
                found = true;
                break;
            }
            temp = temp->next;
        }

        // If random doesn't point to any valid node, correct it
        if (!found || current->random == nullptr) {
            // Find the correct node based on position or value
            // For this example, let's assume we need to point to the next node
            if (current->next != nullptr) {
                current->random = current->next;
            } else {
                current->random = nullptr;
            }
            cout << "Corrected random pointer for node " << current->data << endl;
        }

        current = current->next;
    }
}

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    newNode->random = nullptr;
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
        if (temp->random != nullptr) {
            cout << "(->" << temp->random->data << ")";
        } else {
            cout << "(->NULL)";
        }
        if (temp->next != nullptr) {
            cout << " <-> ";
        }
        temp = temp->next;
    }
    cout << " <-> NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertEnd(head, value);
    }

    // Create a sample incorrect random pointer
    if (head != nullptr && head->next != nullptr && head->next->next != nullptr) {
        // Make the random pointer point to an invalid node for demonstration
        head->random = head->next;
        head->next->random = head;
        head->next->next->random = nullptr; // Invalid pointer
    }

    cout << "\nOriginal Doubly Linked List with Random Pointers: " << endl;
    display(head);

    correctRandomPointer(head);

    cout << "\nAfter correcting random pointers: " << endl;
    display(head);

    return 0;
}


#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Create intersection list of two linked lists
 * Time Complexity: O(n + m)
 * Space Complexity: O(min(n, m))
 */
ListNode* getIntersection(ListNode* head1, ListNode* head2) {
    unordered_set<int> set1;
    ListNode* current = head1;
    
    // Store all values from first list
    while (current != nullptr) {
        set1.insert(current->val);
        current = current->next;
    }
    
    // Find common elements
    unordered_set<int> intersectionSet;
    current = head2;
    while (current != nullptr) {
        if (set1.find(current->val) != set1.end()) {
            intersectionSet.insert(current->val);
        }
        current = current->next;
    }
    
    // Create intersection list
    ListNode* intersectionHead = nullptr;
    ListNode* intersectionTail = nullptr;
    
    for (int val : intersectionSet) {
        ListNode* newNode = new ListNode(val);
        if (intersectionHead == nullptr) {
            intersectionHead = newNode;
            intersectionTail = newNode;
        } else {
            intersectionTail->next = newNode;
            intersectionTail = newNode;
        }
    }
    
    return intersectionHead;
}

/**
 * Create union list of two linked lists
 * Time Complexity: O(n + m)
 * Space Complexity: O(n + m)
 */
ListNode* getUnion(ListNode* head1, ListNode* head2) {
    unordered_set<int> unionSet;
    
    // Add all elements from first list
    ListNode* current = head1;
    while (current != nullptr) {
        unionSet.insert(current->val);
        current = current->next;
    }
    
    // Add all elements from second list
    current = head2;
    while (current != nullptr) {
        unionSet.insert(current->val);
        current = current->next;
    }
    
    // Create union list
    ListNode* unionHead = nullptr;
    ListNode* unionTail = nullptr;
    
    for (int val : unionSet) {
        ListNode* newNode = new ListNode(val);
        if (unionHead == nullptr) {
            unionHead = newNode;
            unionTail = newNode;
        } else {
            unionTail->next = newNode;
            unionTail = newNode;
        }
    }
    
    return unionHead;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // Test case 1
    ListNode* head1 = new ListNode(10);
    head1->next = new ListNode(15);
    head1->next->next = new ListNode(4);
    head1->next->next->next = new ListNode(20);
    
    ListNode* head2 = new ListNode(8);
    head2->next = new ListNode(4);
    head2->next->next = new ListNode(2);
    head2->next->next->next = new ListNode(10);
    
    cout << "Input:" << endl;
    cout << "head1: ";
    printList(head1);
    cout << "head2: ";
    printList(head2);
    cout << endl;
    
    ListNode* intersection = getIntersection(head1, head2);
    ListNode* unionList = getUnion(head1, head2);
    
    cout << "Output:" << endl;
    cout << "Intersection List: ";
    printList(intersection);
    cout << "Union List: ";
    printList(unionList);
    cout << "Explanation: In these two lists 4 and 10 nodes are common. The union lists contain all the nodes of both lists." << endl;
    cout << endl;
    
    deleteList(head1);
    deleteList(head2);
    deleteList(intersection);
    deleteList(unionList);
    
    // Test case 2
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    head3->next->next = new ListNode(3);
    head3->next->next->next = new ListNode(4);
    
    ListNode* head4 = new ListNode(3);
    head4->next = new ListNode(4);
    head4->next->next = new ListNode(8);
    head4->next->next->next = new ListNode(10);
    
    cout << "Input:" << endl;
    cout << "head1: ";
    printList(head3);
    cout << "head2: ";
    printList(head4);
    cout << endl;
    
    ListNode* intersection2 = getIntersection(head3, head4);
    ListNode* unionList2 = getUnion(head3, head4);
    
    cout << "Output:" << endl;
    cout << "Intersection List: ";
    printList(intersection2);
    cout << "Union List: ";
    printList(unionList2);
    cout << "Explanation: In these two lists 4 and 3 nodes are common. The union lists contain all the nodes of both lists." << endl;
    
    deleteList(head3);
    deleteList(head4);
    deleteList(intersection2);
    deleteList(unionList2);
    
    return 0;
}


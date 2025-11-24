#include <iostream>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Check if linked list contains a cycle using hash set
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
bool hasCycle(ListNode* head) {
    unordered_set<ListNode*> visited;
    
    ListNode* current = head;
    while (current != nullptr) {
        // If we've seen this node before, there's a cycle
        if (visited.find(current) != visited.end()) {
            return true;
        }
        
        visited.insert(current);
        current = current->next;
    }
    
    return false;
}

int main() {
    // Create a linked list with cycle: 1 -> 2 -> 3 -> 4 -> 2 (back to node 2)
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // Cycle: points back to node2
    
    cout << "Input: 1 → 2 → 3 → 4 → 2 (back to node 2)" << endl;
    cout << "Output: " << (hasCycle(node1) ? "true" : "false") << endl;
    
    // Clean up (note: with cycle, we can't delete all nodes normally)
    // In a real scenario, you'd need to break the cycle first
    node4->next = nullptr;
    delete node4;
    delete node3;
    delete node2;
    delete node1;
    
    return 0;
}


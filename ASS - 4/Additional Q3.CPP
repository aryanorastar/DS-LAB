#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool canSortQueue(queue<int>& inputQueue) {
    stack<int> s;
    queue<int> outputQueue;
    int expected = 1;
    int n = inputQueue.size();

    while (!inputQueue.empty() || !s.empty()) {
        // If top of stack is expected element, pop it and enqueue to output
        if (!s.empty() && s.top() == expected) {
            outputQueue.push(s.top());
            s.pop();
            expected++;
        }
        // If front of input queue is expected element, dequeue and enqueue to output
        else if (!inputQueue.empty() && inputQueue.front() == expected) {
            outputQueue.push(inputQueue.front());
            inputQueue.pop();
            expected++;
        }
        // Otherwise, push front of input queue to stack
        else if (!inputQueue.empty()) {
            s.push(inputQueue.front());
            inputQueue.pop();
        }
        // If none of the above conditions, sorting is not possible
        else {
            return false;
        }
    }

    return true;
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }

    cout << "Input queue: ";
    printQueue(q);

    if (canSortQueue(q)) {
        cout << "Yes - Queue can be sorted!" << endl;
    } else {
        cout << "No - Queue cannot be sorted!" << endl;
    }

    return 0;
}


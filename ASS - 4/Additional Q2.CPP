#include <iostream>
#include <queue>

using namespace std;

int findMinIndex(queue<int>& q, int sortedIndex) {
    int minIndex = -1;
    int minValue = INT_MAX;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        if (curr < minValue && i <= sortedIndex) {
            minValue = curr;
            minIndex = i;
        }
        q.push(curr);
    }
    return minIndex;
}

void insertMinToRear(queue<int>& q, int minIndex) {
    int minValue = INT_MAX;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        if (i != minIndex) {
            q.push(curr);
        } else {
            minValue = curr;
        }
    }
    q.push(minValue);
}

void sortQueue(queue<int>& q) {
    for (int i = 1; i <= q.size(); i++) {
        int minIndex = findMinIndex(q, q.size() - i);
        insertMinToRear(q, minIndex);
    }
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front();
        q.pop();
        if (!q.empty()) cout << ", ";
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

    cout << "Original queue: ";
    printQueue(q);

    sortQueue(q);

    cout << "Sorted queue: ";
    printQueue(q);

    return 0;
}


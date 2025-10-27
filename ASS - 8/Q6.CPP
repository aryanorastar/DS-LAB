#include <iostream>
#include <climits>

using namespace std;

class PriorityQueue {
private:
    int* heap;
    int capacity;
    int size;

    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
            swap(heap[(index - 1) / 2], heap[index]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        while (true) {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }

            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    PriorityQueue(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    void enqueue(int value) {
        if (size >= capacity) {
            cout << "Priority queue is full!" << endl;
            return;
        }

        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    int dequeue() {
        if (size == 0) {
            cout << "Priority queue is empty!" << endl;
            return INT_MIN;
        }

        int min = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);

        return min;
    }

    int peek() {
        if (size == 0) {
            cout << "Priority queue is empty!" << endl;
            return INT_MIN;
        }
        return heap[0];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size >= capacity;
    }

    void display() {
        if (size == 0) {
            cout << "Priority queue is empty!" << endl;
            return;
        }

        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(10);
    int choice, value;

    while (true) {
        cout << "\n========= Priority Queue Operations =========" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. isEmpty" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                pq.enqueue(value);
                break;
            case 2:
                value = pq.dequeue();
                if (value != INT_MIN) {
                    cout << "Dequeued: " << value << endl;
                }
                break;
            case 3:
                value = pq.peek();
                if (value != INT_MIN) {
                    cout << "Top element: " << value << endl;
                }
                break;
            case 4:
                pq.display();
                break;
            case 5:
                cout << (pq.isEmpty() ? "Priority queue is empty." : "Priority queue is not empty.") << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}


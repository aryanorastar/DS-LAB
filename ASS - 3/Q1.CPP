#include <iostream>

// Set a fixed maximum size for our stack array.
#define MAX_SIZE 10

class Stack {
private:
    int arr[MAX_SIZE]; // The array to store stack elements.
    int top;           // An index to keep track of the top-most element.

public:
    // Constructor to initialize the stack.
    Stack() {
        top = -1; // -1 indicates that the stack is initially empty.
    }

    // (iv) Checks if the stack is full.
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // (iii) Checks if the stack is empty.
    bool isEmpty() {
        return top == -1;
    }

    // (i) Pushes (adds) an element onto the stack.
    void push(int value) {
        if (isFull()) {
            std::cout << "Stack Overflow! Cannot push " << value << ".\n";
            return;
        }
        // Increment top first, then place the element.
        arr[++top] = value;
        std::cout << value << " was pushed onto the stack.\n";
    }

    // (ii) Pops (removes) an element from the stack.
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow! Cannot pop from an empty stack.\n";
            return;
        }
        // Return the top element, then decrement top.
        int popped_value = arr[top--];
        std::cout << popped_value << " was popped from the stack.\n";
    }

    // (vi) Peeks at the top element without removing it.
    void peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "The top element is: " << arr[top] << std::endl;
    }

    // (v) Displays all elements in the stack.
    void display() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Nothing to display.\n";
            return;
        }
        std::cout << "Stack (top to bottom):\n";
        for (int i = top; i >= 0; i--) {
            std::cout << "| " << arr[i] << " |\n";
        }
        std::cout << "-----\n";
    }
};


int main() {
    Stack myStack;
    int choice, value;

    while (true) {
        std::cout << "\n--- STACK MENU ---\n"
                  << "1. Push\n"
                  << "2. Pop\n"
                  << "3. isEmpty\n"
                  << "4. isFull\n"
                  << "5. Peek\n"
                  << "6. Display\n"
                  << "7. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to push: ";
                std::cin >> value;
                myStack.push(value);
                break;
            case 2:
                myStack.pop();
                break;
            case 3:
                if (myStack.isEmpty()) std::cout << "Result: Stack is EMPTY.\n";
                else std::cout << "Result: Stack is NOT EMPTY.\n";
                break;
            case 4:
                if (myStack.isFull()) std::cout << "Result: Stack is FULL.\n";
                else std::cout << "Result: Stack is NOT FULL.\n";
                break;
            case 5:
                myStack.peek();
                break;
            case 6:
                myStack.display();
                break;
            case 7:
                std::cout << "Exiting program. Goodbye! 👋\n";
                return 0;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
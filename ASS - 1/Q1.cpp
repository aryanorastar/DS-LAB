#include <iostream>
#define MAX_SIZE 100 

int arr[MAX_SIZE]; 
int current_size = 0; 

void create();
void display();
void insert();
void deleteElement();
void linearSearch();

int main() {
    int choice;
    while (true) {

        std::cout << "\n--- ARRAY OPERATIONS MENU ---\n"
                  << "1. CREATE\n"
                  << "2. DISPLAY\n"
                  << "3. INSERT\n"
                  << "4. DELETE\n"
                  << "5. LINEAR SEARCH\n"
                  << "6. EXIT\n"
                  << "---------------------------\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                insert();
                break;
            case 4:
                deleteElement();
                break;
            case 5:
                linearSearch();
                break;
            case 6:
                std::cout << "Exiting program. Goodbye! 👋\n";
                return 0;
            default:
                std::cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    }
    return 0;
}

/**
 * @brief Creates a new array by taking input from the user.
 * This will overwrite any existing data.
 */
void create() {
    std::cout << "Enter the number of elements (up to " << MAX_SIZE << "): ";
    std::cin >> current_size;

    if (current_size > MAX_SIZE || current_size < 0) {
        std::cout << "Error: Invalid size. Size must be between 0 and " << MAX_SIZE << ".\n";
        current_size = 0;
        return;
    }

    std::cout << "Enter " << current_size << " integer elements:\n";
    for (int i = 0; i < current_size; ++i) {
        std::cin >> arr[i];
    }
    std::cout << "Array created successfully. ✨\n";
}

/**
 * @brief Displays all the elements currently in the array.
 */
void display() {
    if (current_size == 0) {
        std::cout << "Array is empty. Nothing to display.\n";
        return;
    }
    std::cout << "Array elements: [ ";
    for (int i = 0; i < current_size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]\n";
}

/**
 * @brief Inserts a new element at a specified position in the array.
 */
void insert() {
    if (current_size >= MAX_SIZE) {
        std::cout << "Array is full. Cannot insert element.\n";
        return;
    }

    int pos, value;
    std::cout << "Enter the position to insert (1 to " << current_size + 1 << "): ";
    std::cin >> pos;
    
    if (pos < 1 || pos > current_size + 1) {
        std::cout << "Invalid position!\n";
        return;
    }

    std::cout << "Enter the value to insert: ";
    std::cin >> value;

    int index = pos - 1;

    for (int i = current_size - 1; i >= index; --i) {
        arr[i + 1] = arr[i];
    }

    arr[index] = value;
    current_size++; 

    std::cout << "Element inserted successfully.\n";
}

/**
 * @brief Deletes an element from a specified position in the array.
 */
void deleteElement() {
    if (current_size == 0) {
        std::cout << "Array is empty. Cannot delete element.\n";
        return;
    }

    int pos;
    std::cout << "Enter the position to delete (1 to " << current_size << "): ";
    std::cin >> pos;

    if (pos < 1 || pos > current_size) {
        std::cout << "Invalid position!\n";
        return;
    }
    int index = pos - 1;

    for (int i = index; i < current_size - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    current_size--;

    std::cout << "Element deleted successfully.\n";
}

/**
 * @brief Searches for a given element in the array using linear search.
 */
void linearSearch() {
    if (current_size == 0) {
        std::cout << "Array is empty. Cannot search.\n";
        return;
    }

    int value;
    bool found = false;
    std::cout << "Enter the element to search for: ";
    std::cin >> value;

    for (int i = 0; i < current_size; ++i) {
        if (arr[i] == value) {
            std::cout << "✅ Element " << value << " found at position " << i + 1 << ".\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "❌ Element " << value << " not found in the array.\n";
    }
}
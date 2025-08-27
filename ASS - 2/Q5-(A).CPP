#include <iostream>

class DiagonalMatrix {
private:
    int n;     // The dimension of the matrix (n x n)
    int *A;    // Pointer to a 1D array to store the diagonal elements

public:
    // Constructor: initializes the matrix of a given size
    DiagonalMatrix(int size) {
        this->n = size;
        A = new int[n]; // Only need space for 'n' elements
    }

    // Destructor: cleans up the dynamically allocated memory
    ~DiagonalMatrix() {
        delete[] A;
    }

    // Sets a value at position (i, j)
    void set(int i, int j, int x) {
        // We only care about the main diagonal
        if (i == j) {
            A[i - 1] = x; // Map (i, i) to 1D index i-1
        }
    }

    // Gets the value from position (i, j)
    int get(int i, int j) {
        if (i == j) {
            return A[i - 1]; // Map (i, i) to 1D index i-1
        }
        return 0; // If it's not on the diagonal, it's 0
    }

    // Displays the full n x n matrix
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                std::cout << get(i, j) << "\t";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    DiagonalMatrix dm(4); // Create a 4x4 diagonal matrix

    dm.set(1, 1, 5);
    dm.set(2, 2, 8);
    dm.set(3, 3, 9);
    dm.set(4, 4, 12);
    dm.set(2, 3, 99); // This value will be ignored

    std::cout << "Displaying 4x4 Diagonal Matrix:\n";
    dm.display();
    std::cout << "\nValue at (2,2) is: " << dm.get(2, 2) << std::endl;
    std::cout << "Value at (1,2) is: " << dm.get(1, 2) << std::endl;

    return 0;
}
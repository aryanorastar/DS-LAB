#include <iostream>

class SymmetricMatrix {
private:
    int n;
    int *A;

public:
    SymmetricMatrix(int size) {
        this->n = size;
        // Same storage size as a lower triangular matrix
        A = new int[n * (n + 1) / 2];
    }
    ~SymmetricMatrix() {
        delete[] A;
    }

    void set(int i, int j, int x) {
        // We only store the lower triangular part
        if (i >= j) {
            int index = ((i * (i - 1)) / 2) + (j - 1);
            A[index] = x;
        }
    }

    int get(int i, int j) {
        // If we are asked for an upper-triangle element...
        if (i < j) {
            // ...we just swap i and j to find its stored counterpart.
            std::swap(i, j);
        }
        int index = ((i * (i - 1)) / 2) + (j - 1);
        return A[index];
    }

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
    SymmetricMatrix sm(4);
    // We only need to set values for the lower triangle
    sm.set(1, 1, 2);
    sm.set(2, 1, 3); sm.set(2, 2, 4);
    sm.set(3, 1, 5); sm.set(3, 2, 6); sm.set(3, 3, 7);
    sm.set(4, 1, 8); sm.set(4, 2, 9); sm.set(4, 3, 10); sm.set(4, 4, 11);

    std::cout << "Displaying 4x4 Symmetric Matrix:\n";
    sm.display();
    return 0;
}
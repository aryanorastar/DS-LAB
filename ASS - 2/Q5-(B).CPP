#include <iostream>

class TriDiagonalMatrix {
private:
    int n;
    int *A;

public:
    TriDiagonalMatrix(int size) {
        this->n = size;
        // Total non-zero elements: (n-1) lower + n main + (n-1) upper = 3n-2
        A = new int[3 * n - 2];
    }

    ~TriDiagonalMatrix() {
        delete[] A;
    }

    void set(int i, int j, int x) {
        // Check if the element belongs to one of the three diagonals
        if (abs(i - j) <= 1) {
            int index;
            // Lower Diagonal (i > j)
            if (i - j == 1) {
                index = i - 2;
            }
            // Main Diagonal (i == j)
            else if (i == j) {
                index = (n - 1) + (i - 1);
            }
            // Upper Diagonal (j > i)
            else { // j - i == 1
                index = (n - 1) + n + (i - 1);
            }
            A[index] = x;
        }
    }

    int get(int i, int j) {
         if (abs(i - j) <= 1) {
            int index;
            if (i - j == 1) {
                index = i - 2;
                return A[index];
            } else if (i == j) {
                index = (n - 1) + (i - 1);
                return A[index];
            } else {
                index = (n - 1) + n + (i - 1);
                return A[index];
            }
        }
        return 0; // It's a zero element
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
    TriDiagonalMatrix tdm(4); // 4x4 matrix
    // Setting elements:
    tdm.set(1, 1, 1); tdm.set(1, 2, 2);
    tdm.set(2, 1, 3); tdm.set(2, 2, 4); tdm.set(2, 3, 5);
    tdm.set(3, 2, 6); tdm.set(3, 3, 7); tdm.set(3, 4, 8);
    tdm.set(4, 3, 9); tdm.set(4, 4, 10);
    
    std::cout << "Displaying 4x4 Tri-Diagonal Matrix:\n";
    tdm.display();
    return 0;
}
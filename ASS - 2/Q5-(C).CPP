#include <iostream>

class LowerTriangularMatrix {
private:
    int n;
    int *A;

public:
    LowerTriangularMatrix(int size) {
        this->n = size;
        // Total elements = 1 + 2 + ... + n = n*(n+1)/2
        A = new int[n * (n + 1) / 2];
    }
    ~LowerTriangularMatrix() {
        delete[] A;
    }

    void set(int i, int j, int x) {
        if (i >= j) {
            // Row-major mapping formula
            int index = ((i * (i - 1)) / 2) + (j - 1);
            A[index] = x;
        }
    }

    int get(int i, int j) {
        if (i >= j) {
            int index = ((i * (i - 1)) / 2) + (j - 1);
            return A[index];
        }
        return 0;
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
    LowerTriangularMatrix ltm(4); // 4x4 matrix
    int val = 1;
    for(int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if(i >= j) {
                ltm.set(i, j, val++);
            }
        }
    }
    
    std::cout << "Displaying 4x4 Lower Triangular Matrix:\n";
    ltm.display();
    return 0;
}
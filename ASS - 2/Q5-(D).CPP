#include <iostream>

class UpperTriangularMatrix {
private:
    int n;
    int *A;

public:
    UpperTriangularMatrix(int size) {
        this->n = size;
        A = new int[n * (n + 1) / 2];
    }
    ~UpperTriangularMatrix() {
        delete[] A;
    }

    void set(int i, int j, int x) {
        if (i <= j) {
            // Column-major mapping formula
            int index = ((j * (j - 1)) / 2) + (i - 1);
            A[index] = x;
        }
    }

    int get(int i, int j) {
        if (i <= j) {
            int index = ((j * (j - 1)) / 2) + (i - 1);
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
    UpperTriangularMatrix utm(4);
    int val = 1;
    for(int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if(i <= j) {
                utm.set(i, j, val++);
            }
        }
    }

    std::cout << "Displaying 4x4 Upper Triangular Matrix:\n";
    utm.display();
    return 0;
}
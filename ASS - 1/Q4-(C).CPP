#include <iostream>

#define ROWS 3
#define COLS 2

// Function to print a matrix
void printMatrix(int mat[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    int original_matrix[ROWS][COLS] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };

    // The transposed matrix will have swapped dimensions (COLS x ROWS)
    int transposed_matrix[COLS][ROWS];

    // Logic to transpose the matrix
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            transposed_matrix[j][i] = original_matrix[i][j];
        }
    }

    std::cout << "Original Matrix (" << ROWS << "x" << COLS << "):" << std::endl;
    printMatrix(original_matrix);

    std::cout << "\nTransposed Matrix (" << COLS << "x" << ROWS << "):" << std::endl;
    // We need a specific print function for the transposed dimensions
    for (int i = 0; i < COLS; ++i) {
        for (int j = 0; j < ROWS; ++j) {
            std::cout << transposed_matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
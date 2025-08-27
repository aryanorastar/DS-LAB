#include <iostream>

#define R1 2 // Rows in matrix 1
#define C1 3 // Columns in matrix 1
#define R2 3 // Rows in matrix 2
#define C2 2 // Columns in matrix 2

void multiplyMatrices(int mat1[][C1], int mat2[][C2], int result[][C2]) {
    // Standard matrix multiplication logic
    for (int i = 0; i < R1; ++i) {
        for (int j = 0; j < C2; ++j) {
            result[i][j] = 0; // Initialize the element to 0
            for (int k = 0; k < C1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void printMatrix(int mat[][C2]) {
    for (int i = 0; i < R1; ++i) {
        for (int j = 0; j < C2; ++j) {
            std::cout << mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Check for compatibility: Columns of mat1 must equal Rows of mat2
    if (C1 != R2) {
        std::cout << "Matrices cannot be multiplied. Column count of first matrix"
                  << " must equal row count of second matrix." << std::endl;
        return 1; // Exit with an error code
    }

    int matrix1[R1][C1] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int matrix2[R2][C2] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    int result_matrix[R1][C2];

    multiplyMatrices(matrix1, matrix2, result_matrix);

    std::cout << "Result of matrix multiplication:" << std::endl;
    printMatrix(result_matrix);

    return 0;
}
#include <iostream>

// Define the dimensions of our matrix for easy modification.
#define ROWS 3
#define COLS 4

int main() {
    // A sample 3x4 matrix.
    int matrix[ROWS][COLS] = {
        {10, 20, 30, 40},
        {5,  15, 25, 35},
        {1,  2,  3,  4}
    };

    std::cout << "Calculating sums for the matrix:\n";
    for(int i = 0; i < ROWS; ++i) {
        for(int j = 0; j < COLS; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // --- Calculate Row Sums ---
    std::cout << "\n--- Row Sums ---" << std::endl;
    // The outer loop iterates through each row.
    for (int i = 0; i < ROWS; ++i) {
        int current_row_sum = 0;
        // The inner loop goes through all columns *within* the current row.
        for (int j = 0; j < COLS; ++j) {
            current_row_sum += matrix[i][j];
        }
        std::cout << "Sum of Row " << i + 1 << ": " << current_row_sum << std::endl;
    }

    // --- Calculate Column Sums ---
    std::cout << "\n--- Column Sums ---" << std::endl;
    // The outer loop iterates through each column.
    for (int j = 0; j < COLS; ++j) {
        int current_col_sum = 0;
        // The inner loop goes through all rows *within* the current column.
        for (int i = 0; i < ROWS; ++i) {
            current_col_sum += matrix[i][j];
        }
        std::cout << "Sum of Column " << j + 1 << ": " << current_col_sum << std::endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

// Represents a single non-zero element.
struct Triplet {
    int row, col, value;
};

// Represents the sparse matrix using a vector of Triplets.
class SparseMatrix {
private:
    int numRows, numCols, numElements;
    std::vector<Triplet> elements;

public:
    // Constructor
    SparseMatrix(int r = 0, int c = 0, int n = 0) : numRows(r), numCols(c), numElements(n) {}

    // Reads matrix data from the user.
    void create() {
        std::cout << "Enter number of rows, columns, and non-zero elements: ";
        std::cin >> numRows >> numCols >> numElements;
        elements.resize(numElements);
        std::cout << "Enter the triplets (row col value) for each non-zero element:\n";
        for (int i = 0; i < numElements; i++) {
            std::cin >> elements[i].row >> elements[i].col >> elements[i].value;
        }
    }

    // Displays the matrix in triplet format.
    void display() const {
        std::cout << "\nDimensions: " << numRows << "x" << numCols << " | Non-zero elements: " << numElements << "\n";
        std::cout << "---------------------\n";
        std::cout << "Row\tCol\tValue\n";
        for (const auto& t : elements) {
            std::cout << t.row << "\t" << t.col << "\t" << t.value << "\n";
        }
        std::cout << "---------------------\n";
    }

    // (a) Transpose of a matrix
    SparseMatrix transpose() const {
        SparseMatrix result(numCols, numRows, numElements);
        if (numElements == 0) return result;

        std::vector<int> col_count(numCols + 1, 0);
        std::vector<int> start_pos(numCols + 1, 0);

        for (const auto& elem : elements) {
            col_count[elem.col]++;
        }

        start_pos[1] = 0;
        for (int i = 2; i <= numCols; i++) {
            start_pos[i] = start_pos[i - 1] + col_count[i - 1];
        }
        
        result.elements.resize(numElements);
        for (const auto& elem : elements) {
            int pos = start_pos[elem.col]++;
            result.elements[pos] = {elem.col, elem.row, elem.value};
        }
        return result;
    }

    // (b) Addition of two matrices
    SparseMatrix add(const SparseMatrix& other) const {
        if (numRows != other.numRows || numCols != other.numCols) {
            std::cout << "Error: Dimensions must match for addition.\n";
            return {};
        }

        SparseMatrix result(numRows, numCols, 0);
        int i = 0, j = 0;

        while (i < numElements && j < other.numElements) {
            if (elements[i].row < other.elements[j].row || (elements[i].row == other.elements[j].row && elements[i].col < other.elements[j].col)) {
                result.elements.push_back(elements[i++]);
            } else if (other.elements[j].row < elements[i].row || (other.elements[j].row == elements[i].row && other.elements[j].col < elements[i].col)) {
                result.elements.push_back(other.elements[j++]);
            } else {
                int sum = elements[i].value + other.elements[j].value;
                if (sum != 0) {
                    result.elements.push_back({elements[i].row, elements[i].col, sum});
                }
                i++; j++;
            }
        }
        while (i < numElements) result.elements.push_back(elements[i++]);
        while (j < other.numElements) result.elements.push_back(other.elements[j++]);

        result.numElements = result.elements.size();
        return result;
    }

    // (c) Multiplication of two matrices
    SparseMatrix multiply(const SparseMatrix& other) const {
        if (numCols != other.numRows) {
            std::cout << "Error: Dimensions are not compatible for multiplication.\n";
            return {};
        }

        SparseMatrix result(numRows, other.numCols, 0);
        SparseMatrix otherT = other.transpose(); // Transpose for easier row-on-row processing

        int i = 0;
        while (i < this->numElements) {
            int current_row_A = this->elements[i].row;
            int j = 0;
            while (j < otherT.numElements) {
                int current_row_B_T = otherT.elements[j].row; // This is an original column from B
                
                int temp_i = i;
                int temp_j = j;
                int sum = 0;

                // Dot product logic
                while (temp_i < this->numElements && this->elements[temp_i].row == current_row_A &&
                       temp_j < otherT.numElements && otherT.elements[temp_j].row == current_row_B_T) {
                    if (this->elements[temp_i].col < otherT.elements[temp_j].col) {
                        temp_i++;
                    } else if (otherT.elements[temp_j].col < this->elements[temp_i].col) {
                        temp_j++;
                    } else {
                        sum += this->elements[temp_i].value * otherT.elements[temp_j].value;
                        temp_i++; temp_j++;
                    }
                }
                
                if (sum != 0) {
                    result.elements.push_back({current_row_A, current_row_B_T, sum});
                }
                
                // Advance j to the next row in otherT
                while (j < otherT.numElements && otherT.elements[j].row == current_row_B_T) j++;
            }
            // Advance i to the next row in this matrix
            while (i < this->numElements && this->elements[i].row == current_row_A) i++;
        }
        
        result.numElements = result.elements.size();
        return result;
    }
};

int main() {
    SparseMatrix s1, s2;

    std::cout << "--- Create First Sparse Matrix (A) ---\n";
    s1.create();
    
    std::cout << "--- Create Second Sparse Matrix (B) ---\n";
    s2.create();

    std::cout << "\n--- Matrix A ---";
    s1.display();
    std::cout << "--- Matrix B ---";
    s2.display();

    std::cout << "\n--- (a) Transpose of A ---";
    SparseMatrix s1_T = s1.transpose();
    s1_T.display();

    std::cout << "\n--- (b) Addition (A + B) ---";
    SparseMatrix s_add = s1.add(s2);
    s_add.display();

    std::cout << "\n--- (c) Multiplication (A * B) ---";
    SparseMatrix s_mul = s1.multiply(s2);
    s_mul.display();

    return 0;
}
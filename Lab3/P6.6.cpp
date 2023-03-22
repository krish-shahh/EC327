/*Magic squares. An n × n matrix that is filled with the numbers 1, 2, 3, . . ., n2 is a magic square if the sum of the elements in each row, in each column, and in the two diagonals is the same value
Write a program that reads in 16 values from the keyboard and tests whether they form a magic square when put into a 4 × 4 array. You need to test two features:
1. Does each of the numbers 1, 2, ..., 16 occur in the user input?
2. When the numbers are put into a square, are the sums of the rows, columns, and diagonals equal to each other?*/

#include <iostream>
#include <vector>

using namespace std;

// Function to check if a given vector of integers contains a given value
bool contains(vector<int> vec, int value) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == value) {
            return true;
        }
    }
    return false;
}

// Function to check if a given 4x4 matrix is a magic square
bool is_magic_square(int matrix[][4]) {
    // Calculate the magic constant (the sum of any row, column, or diagonal)
    int magic_const = matrix[0][0] + matrix[0][1] + matrix[0][2] + matrix[0][3];

    // Check the rows
    for (int i = 1; i < 4; i++) {
        int row_sum = matrix[i][0] + matrix[i][1] + matrix[i][2] + matrix[i][3];
        if (row_sum != magic_const) {
            return false;
        }
    }

    // Check the columns
    for (int j = 0; j < 4; j++) {
        int col_sum = matrix[0][j] + matrix[1][j] + matrix[2][j] + matrix[3][j];
        if (col_sum != magic_const) {
            return false;
        }
    }

    // Check the diagonals
    int diagonal1_sum = matrix[0][0] + matrix[1][1] + matrix[2][2] + matrix[3][3];
    int diagonal2_sum = matrix[0][3] + matrix[1][2] + matrix[2][1] + matrix[3][0];
    if (diagonal1_sum != magic_const || diagonal2_sum != magic_const) {
        return false;
    }

    // If all checks pass, the matrix is a magic square
    return true;
}

int main() {
    int matrix[4][4];
    vector<int> values;

    // Read in 16 values and store them in a vector
    cout << "Enter 16 values: ";
    for (int i = 0; i < 16; i++) {
        int value;
        cin >> value;
        values.push_back(value);
    }

    // Check that each of the numbers 1-16 occurs in the input
    for (int i = 1; i <= 16; i++) {
        if (!contains(values, i)) {
            cout << "The number " << i << " is missing from the input." << endl;
            return 0;
        }
    }

    // Store the values in the matrix
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = values[count++];
        }
    }

    // Check if the matrix is a magic square
    if (is_magic_square(matrix)) {
        cout << "The input forms a magic square." << endl;
    } else {
        cout << "The input does not form a magic square." << endl;
    }

    return 0;
}

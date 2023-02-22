#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int SIZE = 4;

bool isMagicSquare(const vector<vector<int> > &matrix) {
    unordered_set<int> s;
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int val = matrix[i][j];
            if (s.count(val) || val < 1 || val > SIZE * SIZE) {
                return false;
            }
            s.insert(val);
        }
        sum += matrix[i][0];
    }
    for (int i = 0; i < SIZE; i++) {
        int row_sum = 0, col_sum = 0;
        for (int j = 0; j < SIZE; j++) {
            row_sum += matrix[i][j];
            col_sum += matrix[j][i];
        }
        if (row_sum != sum || col_sum != sum) {
            return false;
        }
    }
    int diag_sum = 0, anti_diag_sum = 0;
    for (int i = 0; i < SIZE; i++) {
        diag_sum += matrix[i][i];
        anti_diag_sum += matrix[i][SIZE - i - 1];
    }
    if (diag_sum != sum || anti_diag_sum != sum) {
        return false;
    }
    return true;
}

int main() {
    vector<vector<int> > matrix(SIZE, vector<int>(SIZE));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> matrix[i][j];
        }
    }
    if (isMagicSquare(matrix)) {
        cout << "The input forms a 4x4 magic square." << endl;
    } else {
        cout << "The input does not form a 4x4 magic square." << endl;
    }
    return 0;
}

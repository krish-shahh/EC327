#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> convert_to_base(int number, int base) {
    vector<int> result;
    while (number > 0) {
        result.push_back(number % base);
        number /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int N, y;
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter base (y): ";
    cin >> y;
    for (int i = 0; i <= N; i++) {
        vector<int> representation = convert_to_base(i, y);
        for (int j = representation.size() - 1; j >= 0; j--) {
            cout << representation[j];
        }
        cout << endl;
    }
    return 0;
}

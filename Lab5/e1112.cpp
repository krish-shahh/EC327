#include <iostream>
#include <vector>

using namespace std;

int findMax(vector<int> values, int n) {
    // base case
    if (n == 1) {
        return values[0];
    }
    // recursive case
    int max = findMax(values, n-1);
    if (max > values[n-1]) {
        return max;
    } else {
        return values[n-1];
    }
}

int main() {
    vector<int> values = {2, 5, 1, 8, 10, 7};
    int maxVal = findMax(values, values.size());
    cout << "The maximum value is: " << maxVal << endl;
    return 0;
}

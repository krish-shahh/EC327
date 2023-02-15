#include <iostream>

using namespace std;

int nthPerfect(int nn) {
    int count = 0;
    int i = 1;
    while (count < nn) {
        int sum = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }
        if (sum == i) {
            count++;
        }
        i++;
    }
    return i - 1;
}

int main() {
    cout << nthPerfect(2) << endl;
}

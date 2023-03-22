#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int count = 0;
    int n = 3;
    while (count < 100) {
        if (n % 4 == 3 && is_prime(n)) {
            cout << n << endl;
            count++;
        }
        n++;
    }
    return 0;
}

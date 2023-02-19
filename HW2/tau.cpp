#include <iostream>
#include <cmath>

using namespace std;

long tau(long nn) {
    if (nn == 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(nn); i++) {
        if (nn % i == 0) {
            int factor1 = i;
            int factor2 = nn / i;
            return tau(factor1) + tau(factor2);
        }
    }
    return nn;
}

int main() {
    long n;
    cout << "Enter a positive integer: ";
    cin >> n;
    cout << "tau(" << n << ") = " << tau(n) << endl;
    return 0;
}

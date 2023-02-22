#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

long tau(long nn) {
    if (nn == 1) {
        return 1;
    }
    long count = 0;
    for (long i = 1; i <= sqrt(nn); i++) {
        if (nn % i == 0) {
            if (nn/i == i) { // i is a square root of nn
                count++;
            } else {
                count += 2; // i and nn/i are distinct factors of nn
            }
        }
    }
    return count;
}

bool is_prime(long n) {
    if (n < 2) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (long i = 5; i*i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

long next_prime(long n) {
    if (n < 2) {
        return 2;
    }
    if (n == 2) {
        return 3;
    }
    long i = n + 2;
    while (!is_prime(i)) {
        i += 2;
    }
    return i;
}

int main() {
    long max_long = numeric_limits<long>::max();
    long sum = 1; // start with tau(1) = 1
    long i = 2;
    long max_x = 1;
    cout << "x\tS(x)" << endl;
    while (true) {
        long tau_i = tau(i);
        if (sum + tau_i > max_long) {
            break;
        }
        sum += tau_i;
        max_x = i; // update the largest x value
        cout << i << "\t" << sum << endl;
        i = next_prime(i);
    }
    cout << "The largest value of x is: " << max_x << endl;
    return 0;
}

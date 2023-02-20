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
    for (long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

long next_prime(long n) {
    if (n < 2) {
        return 2;
    }
    n++; // check the next integer
    while (!is_prime(n)) {
        n++; // keep checking until a prime is found
    }
    return n;
}

int main() {
    long max_long = numeric_limits<long>::max();
    long sum = 1; // start with tau(1) = 1
    long i = 2;
    while (true) {
        long tau_i = tau(i);
        if (sum + tau_i > max_long) {
            break;
        }
        sum += tau_i;
        i = next_prime(i);
    }
    long upper_bound = i; // i is the largest prime power whose tau sum is less than max_long
    
    // perform binary search to find the largest n whose tau sum is less than max_long
    long lo = 1;
    long hi = upper_bound;
    long mid;
    while (lo < hi) {
        mid = (lo + hi + 1) / 2;
        long tau_sum = 0;
        for (long j = 1; j <= mid; j++) {
            tau_sum += tau(j);
        }
        if (tau_sum > max_long) {
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }
    long max_x = lo;
    cout << "The largest value of x is: " << max_x << endl;
    return 0;
}

/*
Write programs with loops that compute
    The sum of all squares between 1 and 100 (inclusive).
    All powers of 2 from 20 up to 220.
    The sum of all odd digits of an input. (For example, if the input is 32677, the sum would be 3 + 7 + 7 = 17.)
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i * i;
    }
    cout << "The sum of all squares between 1 and 100 is: " << sum << endl;
    
    int exponent = 20;
    for (int i = 0; i <= exponent; i++) {
        cout << "2^" << i << " = " << pow(2, i) << endl;
    }

    int n, sum_2 = 0;
    cout << "Enter an integer: ";
    cin >> n;
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 1) sum_2 += digit;
        n /= 10;
    }
    cout << "The sum of all odd digits is: " << sum_2 << endl;

    return 0;
}
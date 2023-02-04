#include <cmath>
#include <iostream>

using namespace std;

int first_digit(int n) {
    while (n >= 10) {
        n /= 10;
    }
    return n;
}

int last_digit(int n) {
    return n % 10;
}

int digits(int n) {
    if (n == 0) {
        return 1;
    }
    return floor(log10(abs(n))) + 1;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int first_digit(int n);
    int last_digit(int n);
    int digits(int n);       
    cout << "First digit of " << n << " is: " << first_digit(n) << endl;
    cout << "Last digit of " << n << " is: " << last_digit(n) << endl;
    cout << "Number of digits in " << n << " is: " << digits(n) << endl;
    return 0;       
}

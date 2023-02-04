/*
Prime numbers. Write a program that prompts the user for an integer and then prints out all prime numbers up to that integer. For example, when the user enters 20, the program should print
   2
   3
   5
   7
   11
   13
   17
   19
Recall that a number is a prime number if it is not divisible by any number except 1 and itself.
*/

#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
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
    int maxNum;
    cout << "Enter a positive integer: ";
    cin >> maxNum;

    cout << "Prime numbers up to " << maxNum << ":" << endl;
    for (int i = 2; i <= maxNum; i++) {
        if (isPrime(i)) {
            cout << i << endl;
        }
    }

    return 0;
}

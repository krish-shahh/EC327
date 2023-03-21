#include "new2.h"
#include <cmath>
#include <sstream>
#include <iostream>
#include <vector>

GaussianInteger::GaussianInteger() : real(0), imag(0) {}

GaussianInteger::GaussianInteger(const GaussianInteger &other) :
    real(other.real), imag(other.imag) {}

GaussianInteger::GaussianInteger(const int realCoeff, const int imagCoeff) :
    real(realCoeff), imag(imagCoeff) {}

    // Returns true if this object is divisible by [second]
    bool GaussianInteger::divides(const GaussianInteger &second) const {
        if (second.real == 0 && second.imag == 0) {
            return false; // division by zero is not defined
        }
        return (real * second.real + imag * second.imag) % second.norm() == 0 &&
               (imag * second.real - real * second.imag) % second.norm() == 0;
    }

int GaussianInteger::norm() const {
  return real * real + imag * imag;
}

string GaussianInteger::print() const {
  stringstream ss;
     ss << real;
        if (imag >= 0) {
            ss << "+";
        }
        ss << imag << "i";
        return ss.str();
}

// Returns true if this GaussianInteger is prime
    bool GaussianInteger::isPrime() const {
        if (norm() == 2) {
            return true; // special case: 1+i and 1-i are prime
        }
        if (real == 0 && (abs(imag) % 4 == 3)) {
            return true; // special case: Gaussian integers of the form bi where b is an odd prime are prime
        }
        for (int i = 2; i <= sqrt(norm()); i++) {
            if (norm() % i == 0) {
                return false; // the Gaussian integer has a non-trivial factor
            }
        }
        return true; // the Gaussian integer is prime
    }

// Addition operator
GaussianInteger GaussianInteger::operator+(const GaussianInteger &second) const {
    return GaussianInteger(real + second.real, imag + second.imag);
}

// Multiplication operator
GaussianInteger GaussianInteger::operator*(const GaussianInteger &second) const {
    return GaussianInteger(real * second.real - imag * second.imag,
                           real * second.imag + imag * second.real);
}

GaussianInteger GaussianInteger::operator/(const GaussianInteger &second) const {
    int denom = second.norm();
    int realNum = real * second.real + imag * second.imag;
    int imagNum = imag * second.real - real * second.imag;
    return GaussianInteger(realNum / denom, imagNum / denom);
}

// Equality operator
bool GaussianInteger::operator==(const GaussianInteger &second) const {
    return (real == second.real && imag == second.imag);
}


int main() {
    // Construct some GaussianIntegers
    GaussianInteger z1(3, 2);
    GaussianInteger z2(-1, 5);
    GaussianInteger z3(z1);

    // Test the print method
    cout << "z1 = " << z1.print() << endl;
    cout << "z2 = " << z2.print() << endl;
    cout << "z3 = " << z3.print() << endl;

    // Test the addition operator
    cout << "z1 + z2 = " << (z1 + z2).print() << endl;

    // Test the multiplication operator
    cout << "z1 * z2 = " << (z1 * z2).print() << endl;

    // Test the division operator
    cout << "z1 / z2 = " << (z1 / z2).print() << endl;

    // Test the norm method
    cout << "Norm of z1: " << z1.norm() << endl;

    // Test the divides method
    cout << "Does z2 divide z1? " << z2.divides(z1) << endl;

    // Test the isPrime method
    cout << "Is z1 prime? " << z1.isPrime() << endl;
    cout << "Is z2 prime? " << z2.isPrime() << endl;

    // Find all prime GaussianIntegers with norm < 14
    vector<GaussianInteger> primes;
    for (int i = -3; i <= 3; i++) {
        for (int j = -3; j <= 3; j++) {
            GaussianInteger z(i, j);
            if (z.norm() < 14 && z.isPrime()) {
                primes.push_back(z);
            }
        }
    }

    // Print out the prime GaussianIntegers
    cout << "All prime GaussianIntegers with norm < 14:" << endl;
    for (GaussianInteger prime : primes) {
        cout << prime.print() << endl;
    }

    return 0;
}


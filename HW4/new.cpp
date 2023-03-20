#include "new.h"
#include <cmath>
#include <sstream>

GaussianInteger::GaussianInteger() : real(0), imag(0) {}

GaussianInteger::GaussianInteger(const GaussianInteger &other) :
    real(other.real), imag(other.imag) {}

GaussianInteger::GaussianInteger(const int realCoeff, const int imagCoeff) :
    real(realCoeff), imag(imagCoeff) {}

bool GaussianInteger::divides(const GaussianInteger &second) const {
  if (second.real == 0 && second.imag == 0) {
    return true;
  }
  int r = real % second.real;
  int i = imag % second.imag;
  return r == 0 && i == 0;
}

int GaussianInteger::norm() const {
  return real * real + imag * imag;
}

string GaussianInteger::print() const {
  stringstream ss;
  ss << real;
  if (imag < 0) {
    ss << " - " << -imag << "i";
  } else if (imag > 0) {
    ss << " + " << imag << "i";
  }
  return ss.str();
}

bool GaussianInteger::isPrime() const {
  // A Gaussian integer is prime if and only if its norm is a prime integer
  if (norm() <= 1) {
    return false;
  } else if (norm() == 2 || norm() == 5) {
    return true;
  } else if (norm() % 2 == 0 || norm() % 5 == 0) {
    return false;
  }
  
  // Check if the Gaussian integer can be factored into non-trivial factors
  for (int i = -1; i <= 1; i += 2) {
    for (int j = -1; j <= 1; j += 2) {
      GaussianInteger factor(i, j);
      if (factor.norm() >= norm()) {
        continue;
      }
      if (divides(factor) && factor.divides(*this)) {
        return false;
      }
    }
  }
  
  // If the Gaussian integer cannot be factored into non-trivial factors, it is prime
  return true;
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

// Division operator
GaussianInteger GaussianInteger::operator/(const GaussianInteger &second) const {
    int commonFactor = second.norm();
    int newReal = (real*second.real + imag*second.imag) / commonFactor;
    int newImag = (imag*second.real - real*second.imag) / commonFactor;
    return GaussianInteger(newReal, newImag);
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


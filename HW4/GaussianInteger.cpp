#include "GaussianInteger.h"
#include <iostream>

using namespace std;

GaussianInteger::GaussianInteger() : real_(0), imag_(0) {}

GaussianInteger::GaussianInteger(const GaussianInteger &other) :
    real_(other.real_), imag_(other.imag_) {}

GaussianInteger::GaussianInteger(const int realCoeff, const int imagCoeff) :
    real_(realCoeff), imag_(imagCoeff) {}

bool GaussianInteger::divides(const GaussianInteger &second) const {
    if (second.real_ == 0 && second.imag_ == 0) {
        // 0 does not divide any GaussianInteger
        return false;
    }
    int a = real_, b = imag_, c = second.real_, d = second.imag_;
    return c % a == 0 && d % b == 0 && (c / a) % 2 == (d / b) % 2;
}

int GaussianInteger::norm() const {
    return real_ * real_ + imag_ * imag_;
}

bool GaussianInteger::isPrime() const {
    if (norm() == 2) {
        return true;
    }
    if (real_ == 0) {
        return abs(imag_) % 2 == 1 && isPrimeHelper(abs(imag_));
    }
    if (imag_ == 0) {
        return abs(real_) % 2 == 1 && isPrimeHelper(abs(real_));
    }
    return isPrimeHelper(norm());
}

bool GaussianInteger::isPrimeHelper(int n) const {
    if (n <= 1) {
        return false;
    }
    if (n == 2 || n == 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

string GaussianInteger::print() const {
    return to_string(real_) + (imag_ >= 0 ? "+" : "") + to_string(imag_) + "i";
}

GaussianInteger GaussianInteger::operator+(const GaussianInteger &second) const {
    return GaussianInteger(real_ + second.real_, imag_ + second.imag_);
}

GaussianInteger GaussianInteger::operator*(const GaussianInteger &second) const {
    int a = real_, b = imag_, c = second.real_, d = second.imag_;
    return GaussianInteger(a * c - b * d, b * c + a * d);
}

GaussianInteger GaussianInteger::operator/(const GaussianInteger &second) const {
    int a = real_, b = imag_, c = second.real_, d = second.imag_;
    int factor = c * c + d * d;
    return GaussianInteger((a * c + b * d) / factor, (b * c - a * d) / factor);
}

bool GaussianInteger::operator==(const GaussianInteger &second) const {
    return real_ == second.real_ && imag_ == second.imag_;
}

int main() {
    GaussianInteger a(1, 1);
    GaussianInteger b(3, 2);
    GaussianInteger c = a + b;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = a + b = " << c << std::endl;

    std::cout << "Is c prime? " << std::boolalpha << c.isPrime() << std::endl;

    return 0;
}

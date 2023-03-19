#ifndef GAUSSIAN_INTEGER_H
#define GAUSSIAN_INTEGER_H

#include <string>
#include <cmath>

class GaussianInteger {
public:
    GaussianInteger();
    GaussianInteger(const GaussianInteger& other);
    GaussianInteger(const int realCoeff, const int imagCoeff);

    bool divides(const GaussianInteger& second) const;
    int norm() const;
    bool isPrime() const;
    bool isPrimeHelper(int n) const;
    std::string print() const;

    GaussianInteger operator+(const GaussianInteger& second) const;
    GaussianInteger operator*(const GaussianInteger& second) const;
    GaussianInteger operator/(const GaussianInteger& second) const;
    bool operator==(const GaussianInteger& second) const;

private:
    int real_;
    int imag_;
};

#endif // GAUSSIAN_INTEGER_H

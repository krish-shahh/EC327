#ifndef NEW_H
#define NEW_H

#include <string>
using namespace std;
 
class GaussianInteger {
public:
  /**
   * Constructs an GaussianInteger 0
   */
  GaussianInteger();
 
  /**
   * Copy constructor - constructs a duplicate of [other]
   * @param other The GaussianInteger to duplicate
   */
  GaussianInteger(const GaussianInteger &other);
 
  /**
   * Constructs a Gaussian integer representing realCoeff + imagCoeff i
   */
  GaussianInteger(const int realCoeff, const int imagCoeff);

  /**
   * @param second The GaussianInteger by which to divide this object
   * @return true if and only if this object is divides by [second]
   *     (or, in other words, second is a factor of this object)
   */
  bool divides(const GaussianInteger &second) const;
 
  /**
   * @return the norm of this object.  If this object is a+bi, then the norm is a^2+b^2.
   */
  int norm() const;
 
  /**
   * @return A string pretty-printing this GaussianInteger
   */
  string print() const;

  bool isPrime() const;

  GaussianInteger operator+(const GaussianInteger& second) const;

  GaussianInteger operator*(const GaussianInteger& second) const;

  GaussianInteger operator/(const GaussianInteger& second) const;

  bool operator==(const GaussianInteger& second) const;

private:
  int real;
  int imag;
};
 
#endif // GAUSSIANINTEGER_H

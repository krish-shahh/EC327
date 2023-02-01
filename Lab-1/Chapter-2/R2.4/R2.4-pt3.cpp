// Third Equation: G=4(pi)^2 * (a^3/p^2(m1+m2))

#include <iostream>
#include <cmath>

int main() {
    double pi = 3.14159265358979323846, a = 2, p = 2, m_1 = 2, m_2 = 2, G;

    G = 4 * pow(pi, 2) * pow(a, 3) / (pow(p, 2) * (m_1 + m_2));

    std::cout << "G = " << G << std::endl;

    return 0;
}

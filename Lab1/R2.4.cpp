#include <iostream>
#include <cmath>

int main() {
    // First Equation: s = s=s(sub 0)+v(sub 0)*t + 1/2g*t^2

    double s_0 = 2, v_0 = 2, t = 2, g = 2, s;

    s = s_0 + v_0 * t + 0.5 * g * pow(t, 2);

    std::cout << "s = " << s << std::endl;

    // Second Equation: FV= PV * (1 + INT/100)^YRS

    double PV = 2, INT = 2, YRS = 2, FV;

    FV = PV * pow((1 + INT/100), YRS);

    std::cout << "FV = " << FV << std::endl;

    // Third Equation: G=4(pi)^2 * (a^3/p^2(m1+m2))

    double pi = 3.14159265358979323846, a = 2, p = 2, m_1 = 2, m_2 = 2, G;

    G = 4 * pow(pi, 2) * pow(a, 3) / (pow(p, 2) * (m_1 + m_2));

    std::cout << "G = " << G << std::endl;

    // Fourth Equation: sqrt(a^2 + b^2 - 2ab cos y)

    double a_val = 2, b = 2, y = 2, c;

    c = sqrt(pow(a_val, 2) + pow(b, 2) - 2 * a_val * b * cos(y));

    std::cout << "C = " << c << std::endl;

    return 0;
}


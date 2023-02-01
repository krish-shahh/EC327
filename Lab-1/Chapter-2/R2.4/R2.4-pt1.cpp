// First Equation: s = s=s(sub 0)+v(sub 0)*t + 1/2g*t^2

#include <iostream>
#include <cmath>

int main() {
    double s_0 = 2, v_0 = 2, t = 2, g = 2, s;

    s = s_0 + v_0 * t + 0.5 * g * pow(t, 2);

    std::cout << "s = " << s << std::endl;

    return 0;
}


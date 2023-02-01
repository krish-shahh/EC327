// Fourth Equation: sqrt(a^2 + b^2 - 2ab cos y)

#include <iostream>
#include <cmath>

int main() {
    double a = 2, b = 2, y = 2, result;

    result = sqrt(pow(a, 2) + pow(b, 2) - 2 * a * b * cos(y));

    std::cout << "Result = " << result << std::endl;

    return 0;
}

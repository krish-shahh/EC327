// Second Equation: FV= PV * (1 + INT/100)^YRS

#include <iostream>
#include <cmath>

int main() {
    double PV = 2, INT = 2, YRS = 2, FV;

    FV = PV * pow((1 + INT/100), YRS);

    std::cout << "FV = " << FV << std::endl;

    return 0;
}

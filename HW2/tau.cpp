#include <iostream>

long tau(long nn) {
    if (nn <= 1) {  // special case: tau(1) = 0
        return 0;
    }
    for (int ii = 2; ii <= nn / 2; ii++) {
        if (nn % ii == 0) {
            // nn is composite, so find its factors and recurse on them
            long aa = ii;
            long bb = nn / ii;
            return tau(aa) + tau(bb);
        }
    }
    // nn is prime
    return nn;
}

int main() {
    std::cout << tau(1) << std::endl;  // should output 0
    std::cout << tau(2) << std::endl;  // should output 2
    std::cout << tau(3) << std::endl;  // should output 3
    std::cout << tau(6) << std::endl;  // should output 5
    std::cout << tau(12) << std::endl;  // should output 7
    return 0;
}

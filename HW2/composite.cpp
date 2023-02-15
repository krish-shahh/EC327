#include <iostream>

bool compositeQ(int nn) {
    if (nn <= 1) {  // special cases: 0, 1 are not composite
        return false;
    }
    for (int ii = 2; ii <= nn / 2; ii++) {
        if (nn % ii == 0) {
            return true;  // nn has a factor, so it is composite
        }
    }
    return false;  // nn is prime, so it is not composite
}

int main() {
    std::cout << compositeQ(3) << std::endl;  // should output 0 (false)
    std::cout << compositeQ(4) << std::endl;  // should output 1 (true)
    std::cout << compositeQ(6) << std::endl;  // should output 1 (true)
    return 0;
}

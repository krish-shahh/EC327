#include <iostream>
#include <cmath>

using namespace std;

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
    

    return 0;
}

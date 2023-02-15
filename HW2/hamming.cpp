#include <iostream>

int HammingDistance(unsigned long aa, unsigned long bb) {
    unsigned long count = 0;
    unsigned long diff = aa ^ bb;  // XOR operation to find bit differences
    
    while (diff != 0) {
        count++;
        diff &= diff - 1;  // clear the least significant bit that is set
    }
    
    return count;
}

int main() {
    std::cout << HammingDistance(10, 14) << std::endl;  // should output 1
    std::cout << HammingDistance(1, 15) << std::endl;  // should output 3
    return 0;
}

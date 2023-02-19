#include <iostream>

using namespace std;

int HammingDistance(unsigned long aa, unsigned long bb) {
    unsigned long mask = 1;
    int distance = 0;
    for (int i = 0; i < sizeof(unsigned long) * 8; i++) {
        if ((aa & mask) != (bb & mask)) {
            distance++;
        }
        mask <<= 1;
    }
    return distance;
}


int main() {
    unsigned long aa, bb;
    cout << "Enter the first unsigned long integer: ";
    cin >> aa;
    cout << "Enter the second unsigned long integer: ";
    cin >> bb;
    int distance = HammingDistance(aa, bb);
    cout << "The Hamming distance between " << aa << " and " << bb << " is " << distance << std::endl;
    // cout << HammingDistance(10, 14) << endl;  // should output 1
    // cout << HammingDistance(1, 15) << endl;  // should output 3
    return 0;
}

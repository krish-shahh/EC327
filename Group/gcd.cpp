#include <iostream>

using namespace std;

int gcd(int aa, int bb) {
    while (bb != 0) {
        int temp = bb;
        bb = aa % bb;
        aa = temp;

    }
    return aa;
}

int main() {
    int result = gcd(5, 10);
    cout << result << endl;
}
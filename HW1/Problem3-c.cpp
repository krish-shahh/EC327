#include <iostream>
using namespace std;

int main() {
    float flt1 = 0;
    float adder1 = 0.000002;
    while(flt1 < 0.375) {
        flt1 = flt1 + adder1;
    }
    flt1 = flt1 - adder1;
    cout << "The Computer Stores: " << flt1 << endl;

    float flt2 = 0;
    float adder2 = 0.000002;
    while(flt2 < 0.15) {
        flt2 = flt2 + adder2;
    }
    flt2 = flt2 - adder2;
    cout << "The Computer Stores: " << flt2 << endl;

    float flt3 = 0;
    float adder3 = 0.000002;
    while(flt3 < 0.984375) {
        flt3 = flt3 + adder3;
    }
    flt3 = flt3 - adder3;
    cout << "The Computer Stores: " << flt3 << endl;

    return 0;
}

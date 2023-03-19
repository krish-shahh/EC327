#include <cmath>
#include <iostream>

using namespace std;

float gammaFunc(float z) {
    float result = 1.0;
    for (int n = 1; n <= 1000000; n++) {
        result *= pow((1.0 + 1.0 / n), z) / (1.0 + z / n);
    }
    result *= 1.0 / z;
    return result;
}


float equals(float id) {
    float left = 0.1;
    float right = 100.0;
    float x = (left + right) / 2.0;

    while (right - left > 0.000001) {
        float gamma_x = gammaFunc(x);
        if (gamma_x < id) {
            left = x;
        } else {
            right = x;
        }
        x = (left + right) / 2.0;
    }

    return x;
}


int main() {

    float ID1 = 2.0;  // Replace with your last digit of BU ID

    float gamma1 = gammaFunc(1 + ID1);
    float gamma2 = gammaFunc(1 + ID1 / 10);

    cout << "Gamma(1+" << ID1 << ") = " << gamma1 << endl;
    cout << "Gamma(1+" << ID1 / 10 << ") = " << gamma2 << endl;

    float ID = 3.14159;
    float x = equals(ID);   
    float ID4 = 2512;
    float x1 = equals(ID4);              

    cout << "x= " << x << endl;
    cout << "x1= " << x1 << endl;

    return 0;

}
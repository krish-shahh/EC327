#include <iostream>

using namespace std;

bool makeTotalQ(int num1, int num2) {
    if (num1 * num2 == 24) {
        return true;
    } else if (num1 + num2 == 24 || num1 - num2 == 24 || num2 - num1 == 24) {
        return true;
    } else if (num1 != 0 && num2 != 0 && (num1 % num2 == 0 || num2 % num1 == 0)) {
        int div1 = num1 / num2;
        int div2 = num2 / num1;
        if (div1 == 24 || div2 == 24) {
            return true;
        }
    }
    return false;
}

int main() {
    int num1, num2;
    cout << "Enter first non-negative integer: ";
    cin >> num1; 
    cout << "Enter second non-negative integer: ";
    cin >> num2;
    if (makeTotalQ(num1, num2)) {
        cout << "These numbers can be combined to result in 24." << endl;
    } else {
        cout << "These numbers cannot be combined to result in 24." << endl;
    }
    return 0;
}

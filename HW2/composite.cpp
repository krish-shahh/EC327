#include <iostream>
#include <cmath>

using namespace std;

bool compositeQ(int nn) {
    if (nn <= 1) {
        return false;
    }
    
    int limit = sqrt(nn);
    for (int i = 2; i <= limit; i++) {
        if (nn % i == 0) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int nn;
    cout << "Enter an integer: ";
    cin >> nn;
    
    if (compositeQ(nn)) {
        cout << nn << " is composite." << endl;
    } else {
        cout << nn << " is prime." << endl;
    }
    return 0;
}

#include <iostream>
#include <string>

using namespace std;

void printInBase(int n, int y) {
    string digits = "0123456789";
    string result = "";
    
    while (n > 0) {
        int digit = n % y;
        result = digits[digit] + result;
        n /= y;
    }
    
    cout << result << endl;
}

int main() {
    int N, y;
    cout << "Enter N: ";
    cin >> N;
    cout << "Enter base (y): ";
    cin >> y;           
    for (int i = 0; i <= N; i++) {
        printInBase(i, y);
    }
    
    return 0;
}

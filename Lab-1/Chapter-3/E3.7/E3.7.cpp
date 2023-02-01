/*
Write a program that reads in three integers and prints “in order” if they are sorted in ascending or descending order, or “not in order” otherwise.
*/

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    while (cin >> a >> b >> c) {
        if ((a <= b && b <= c) || (c <= b && b <= a)) {
            cout << "in order" << endl;
        } else if ((a >= b && b >= c) || (c >= b && b >= a)) {
            cout << "in order" << endl;
        } else {
            cout << "not in order" << endl;
        }
    }
    return 0;
}

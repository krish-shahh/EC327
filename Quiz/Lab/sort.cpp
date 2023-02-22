/*
Write a C++ program that reads in four integers and prints in order if they are sorted in ascending or descending order, or not in order otherwise.
*/

#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;

    cout << "Enter first integer: ";
    cin >> a;
    cout << "Enter second integer: ";
    cin >> b;
    cout << "Enter third integer: ";
    cin >> c;
    cout << "Enter fourth integer: ";
    cin >> d;

    if((a < b && b < c && c < d) || (a > b && b > c && c > d)) {
        cout << "In Order" << endl;
    } 
    else {
        cout << "Not in Order" << endl;
    }
    return 0;
}



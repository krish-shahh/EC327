/*
The nested loops
for (int i = 1; i <= height; i++)
{
for (int j = 1; j <= width; j++) { cout << "*"; }
cout << endl; }
display a rectangle of a given width and height, such as
**** **** ****
Write a single for loop that displays the same rectangle.
*/

#include <iostream>

using namespace std;

int main() {
    int width, height;

    cout << "Enter the width of the rectangle: ";
    cin >> width;

    cout << "Enter the height of the rectangle: ";
    cin >> height;

    for (int i = 1; i <= height * width; i++) {
        cout << "*";
        if (i % width == 0) cout << endl;
    }

    return 0;
}

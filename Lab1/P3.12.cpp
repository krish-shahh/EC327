/*
Write a program that reads in the x- and y-coordinates of four corner points of a quadrilateral and prints out whether it is a square, a rectangle, a trapezoid, a rhom- bus, or none of those shapes.
*/


#include <iostream>
#include <cmath>

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    std::cout << "Enter x coodinate of first point: ";
    std::cin >> x1;
    std::cout << "Enter y coodinate of first point: ";
    std::cin >> y1;
    std::cout << "Enter x coodinate of second point: ";
    std::cin >> x2;
    std::cout << "Enter y coodinate of second point: ";
    std::cin >> y2;
    std::cout << "Enter x coodinate of third point: ";
    std::cin >> x3;
    std::cout << "Enter y coodinate of third point: ";
    std::cin >> y3;
    std::cout << "Enter x coodinate of fourth point: ";
    std::cin >> x4;
    std::cout << "Enter y coodinate of fourth point: ";
    std::cin >> y4;

    double d1 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double d2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double d3 = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
    double d4 = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));

    double d_diagonal1 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    double d_diagonal2 = sqrt(pow(x2 - x4, 2) + pow(y2 - y4, 2));

    if (d1 == d2 && d2 == d3 && d3 == d4 && d1 == d4) {
        if(d_diagonal1 == d_diagonal2) {
            std::cout << "square" << std::endl;
        }
    } else if (d1 == d3 && d2 == d4 && d_diagonal1 == d_diagonal2) {
        std::cout << "rectangle" << std::endl;
    } else if (d_diagonal1 != d_diagonal2) {
        std::cout << "rhombus" << std::endl;
    } else if (d1 == d3 || d2 == d4) {
        std::cout << "trapezoid" << std::endl;
    } else {
        std::cout << "none of those shapes" << std::endl;
    }
    return 0;
}
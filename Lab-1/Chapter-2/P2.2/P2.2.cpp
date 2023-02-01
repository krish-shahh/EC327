/*
    In this project, you will perform calculations with triangles. A triangle is defined by the x- and y-coordinates of its three corner points.
Your job is to compute the following properties of a given triangle:
• the lengths of all sides
• the angles at all corners
• the perimeter
• the area
Supply a program that prompts a user for the corner point coordinates and produces a nicely formatted table of the triangle properties.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

const double pi = 3.14159265358979323846;

struct Point {
    double x;
    double y;
};

double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double angle(Point a, Point b, Point c) {
    double A = distance(b, c);
    double B = distance(a, c);
    double C = distance(a, b);
    return acos((A * A + C * C - B * B) / (2 * A * C)) * 180 / pi;
}

int main() {
    Point a, b, c;
    std::cout << "Enter the x and y coordinates of the first point: ";
    std::cin >> a.x >> a.y;
    std::cout << "Enter the x and y coordinates of the second point: ";
    std::cin >> b.x >> b.y;
    std::cout << "Enter the x and y coordinates of the third point: ";
    std::cin >> c.x >> c.y;

    double AB = distance(a, b);
    double BC = distance(b, c);
    double AC = distance(a, c);
    double A = angle(b, a, c);
    double B = angle(a, b, c);
    double C = angle(a, c, b);
    double perimeter = AB + BC + AC;
    double s = perimeter / 2;
    double area = sqrt(s * (s - AB) * (s - BC) * (s - AC));

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Side lengths:" << std::endl;
    std::cout << "AB = " << AB << std::endl;
    std::cout << "BC = " << BC << std::endl;
    std::cout << "AC = " << AC << std::endl;
    std::cout << "Angles:" << std::endl;
    std::cout << "A = " << A << " degrees" << std::endl;
    std::cout << "B = " << B << " degrees" << std::endl;
    std::cout << "C = " << C << " degrees" << std::endl;
    std::cout << "Perimeter: " << perimeter << std::endl;
    std::cout << "Area: " << area << std::endl;

    return 0;
}



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
    return acos((A * A + C * C - B * B) / (2 * A * C)) * 180 / M_PI; //pi constant resource: http://www.quantstart.com/articles/Mathematical-Constants-in-C/
}

int main() {
    Point a, b, c;
    std::cout << "Enter the x coordinate of the first point: ";
    std::cin >> a.x;
    std::cout << "Enter the y coordinate of the first point: ";
    std::cin >> a.y;
    std::cout << "Enter the x coordinate of the second point: ";
    std::cin >> b.x;
    std::cout << "Enter the y coordinate of the second point: ";
    std::cin >> b.y;
    std::cout << "Enter the x coordinate of the third point: ";
    std::cin >> c.x;
    std::cout << "Enter the y coordinate of the third point: ";
    std::cin >> c.y;

    double AB = distance(a, b);
    double BC = distance(b, c);
    double AC = distance(a, c);
    double A = angle(b, a, c);
    double B = angle(a, b, c);
    double C = angle(a, c, b);
    double perimeter = AB + BC + AC;
    double s = perimeter / 2;
    double area = sqrt(s * (s - AB) * (s - BC) * (s - AC)); // Heron's Formula

    // Formatting Output into Table
    // setw resource: https://cplusplus.com/reference/iomanip/setw/
    // setpercision resource: https://cplusplus.com/reference/iomanip/setprecision/
    std::cout << std::fixed << std::setprecision(3); 
    std::cout << std::left << std::setw(20) << "Side Lengths:" << std::endl; 
    std::cout << std::left << std::setw(15) << "AB" << "= " << AB << std::endl;
    std::cout << std::left << std::setw(15) << "BC" << "= " << BC << std::endl;
    std::cout << std::left << std::setw(15) << "AC" << "= " << AC << std::endl;
    std::cout << std::left << std::setw(20) << "Angles:" << std::endl;
    std::cout << std::left << std::setw(15) << "A" << "= " << A << " degrees" << std::endl;
    std::cout << std::left << std::setw(15) << "B" << "= " << B << " degrees" << std::endl;
    std::cout << std::left << std::setw(15) << "C" << "= " << C << " degrees" << std::endl;    
    std::cout << std::left << std::setw(15) << "Perimeter:" << "= " << perimeter << std::endl;
    std::cout << std::left << std::setw(15) << "Area:" << "= " << area << std::endl;

    return 0;
}



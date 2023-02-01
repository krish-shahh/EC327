/*
Write a program that reads in the x- and y-coordinates of four corner points of a quadrilateral and prints out whether it is a square, a rectangle, a trapezoid, a rhom- bus, or none of those shapes.
*/

#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-6;

struct Point {
    double x, y;
};

double dist(Point A, Point B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

int main() {
    Point p[4];
    for (int i = 0; i < 4; i++) {
        cin >> p[i].x >> p[i].y;
    }

    double d1 = dist(p[0], p[1]);
    double d2 = dist(p[1], p[2]);
    double d3 = dist(p[2], p[3]);
    double d4 = dist(p[3], p[0]);
    double d5 = dist(p[0], p[2]);
    double d6 = dist(p[1], p[3]);

    if (fabs(d1 - d3) < eps && fabs(d2 - d4) < eps) {
        if (fabs(d1 - d2) < eps) {
            cout << "square" << endl;
        } else {
            cout << "rectangle" << endl;
        }
    } else if (fabs(d5 - d6) < eps) {
        cout << "rhombus" << endl;
    } else if (fabs(d1 - d2) < eps || fabs(d2 - d3) < eps || fabs(d3 - d4) < eps || fabs(d4 - d1) < eps) {
        cout << "trapezoid" << endl;
    } else {
        cout << "none of those shapes" << endl;
    }
    return 0;
}

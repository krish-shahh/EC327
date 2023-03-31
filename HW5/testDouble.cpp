#include "DoubleLink.h"
#include <iostream>

using namespace std;

int main() {
    DoubleLink link1(1);
    DoubleLink link2(2);
    DoubleLink link3(3);

    link1 += link2 += link3;

    cout << link1 << endl;

    DoubleLink link4(new int[3]{4,5,6}, 3);
    DoubleLink link5(new int[2]{7,8}, 2);

    link4 += link5;

    cout << link4 << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int total = 100;

void setTotal(int t) {
    total = t;
}

bool makeTotalQ(int num1, int num2, int num3, int num4) {
    int a, b, c, d, e, f, g;
    a = num1 + num2;
    b = num1 * num2;
    c = num1 / num2;
    d = num2 - num1;
    e = num3 + num4;
    f = num3 * num4;
    g = num3 / num4;
    int x, y, z;
    x = a + e;
    y = b + f;
    z = c + g;
    if (x == total || y == total || z == total) {
        return true;
    }
    return false;
}

int main() {
    for (int t = 1; t <= total; t++) {
        int count = 0;
        int s = sqrt(t);
        for (int i = 0; i <= s; i++) {
            for (int j = i; j <= s; j++) {
                for (int k = j; k <= s; k++) {
                    for (int l = k; l <= s; l++) {
                        if (makeTotalQ(i, j, k, l)) {
                            count++;
                        }
                    }
                }
            }
        }
        cout << "Total " << t << ": " << count << " sets" << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    float values[] = {0.375, 0.15, 0.984375};
    int n = sizeof(values)/sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        int* p = (int*)(&values[i]);
        cout << values[i] << " = " << *p << endl;
    }

    return 0;
}

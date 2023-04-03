#include <iostream>
#include <vector>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

int main() {
    vector<int> v1{1, 2, 3, 4, 5};
    vector<double> v2{1.1, 2.2, 3.3, 4.4, 5.5};
    vector<string> v3{"hello", "world", "!"};

    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;

    return 0;
}

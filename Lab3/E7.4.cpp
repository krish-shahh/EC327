#include <iostream>

using namespace std;

double* maximum(double* a, int size) {
    if (size == 0) {
        return nullptr;
    }
    double* max_ptr = &a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > *max_ptr) {
            max_ptr = &a[i];
        }
    }
    return max_ptr;
}

int main() {
    double arr[] = {1.2, 3.4, 5.6, 2.3, 4.5};
    int size = sizeof(arr) / sizeof(arr[0]);

    double* max_ptr = maximum(arr, size);
    if (max_ptr != nullptr) {
        cout << "The maximum value in the array is: " << *max_ptr << endl;
    }
    else {
        cout << "The array is empty." << endl;
    }

    return 0;
}

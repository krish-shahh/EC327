#include <iostream>

using namespace std;

int* read_data(int& size) {
    const int initial_size = 10;
    int* data = new int[initial_size];  // allocate initial array
    int index = 0;  // current index in array
    int capacity = initial_size;  // current capacity of array
    int value;
    char c;
    while (cin >> value) {  // read integers until non-integer is entered
        if (index == capacity) {  // if array is full, double its size
            int* temp = new int[capacity * 2];
            for (int i = 0; i < capacity; ++i) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }
        data[index] = value;
        ++index;
    }
    cin.clear();  // clear the input stream state after non-integer is entered
    cin >> c;  // read the 'Q' character
    delete[] data;  // free the initial array
    size = index;  // set size parameter to number of inputs
    int* result = new int[size];  // allocate correctly sized array
    for (int i = 0; i < size; ++i) {
        result[i] = data[i];
    }
    return result;
}

int main() {
    int size;
    int* data = read_data(size);

    cout << "Input values:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    delete[] data;
    return 0;
}
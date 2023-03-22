/*Write a function int* read_data(int& size) that reads data from cin until the user ter­ minates input by entering Q. The function should set the size reference parameter to the number of numeric inputs. Return a pointer to an array on the free store. That array should have exactly size elements. Of course, you won’t know at the out­
set how many elements the user will enter. Start with an array of 10 elements, and double the size whenever the array fills up. At the end, allocate an array of the cor­ rect size and copy all inputs into it. Be sure to delete any intermediate arrays.*/

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
    cout << "Input values (type Q to quit):" << endl;
    int* data = read_data(size);

    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    delete[] data;
    return 0;
}
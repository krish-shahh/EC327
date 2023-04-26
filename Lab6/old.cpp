#include <iostream>
#include <vector>
#include <string>
using namespace std;


template <typename Foo, int sz=5>
        int bar(Foo x) {
            vector<Foo> y;
            y.push_back(x);
            cout << y.size()+sz << endl;
        }

int main() {
    // Scenario 0a
    bar<int>(42); //prints 6 everyime

    // Scenario 0b
    bar<char, 10>('D'); // prints 11 everytime

    // Scenario 0c
    bar<string, 0>("krish"); // prints 1 every time

}

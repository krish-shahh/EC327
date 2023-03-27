#include <iostream>
#include "CircularDoubleLink.h"

using namespace std;

int main() {
    // Create a circular doubly-linked list of integers
    CircularDoubleLink<int> list;
    
    // Add some elements to the list
    list.append(1);
    list.append(2);
    list.append(3);
    
    // Print the list forwards
    cout << "List contents (forwards): ";
    list.printForwards();
    cout << endl;
    
    // Print the list backwards
    cout << "List contents (backwards): ";
    list.printBackwards();
    cout << endl;
    
    // Remove the last element from the list
    list.pop();
    
    // Print the list forwards again
    out << "List contents (forwards): ";
    list.printForwards();
    cout << endl;
    
    // Add another element to the list
    list.append(4);
    
    // Print the list backwards again
    cout << "List contents (backwards): ";
    list.printBackwards();
    cout << endl;
    
    return 0;
}

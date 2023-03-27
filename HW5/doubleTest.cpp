#include "DoubleLink.h"
#include <iostream>

using namespace std;

int main() {
    // Create a doubly-linked list of digits in a BU ID
    int id[] = {3, 1, 4, 1, 5, 9, 2, 6};
    DoubleLink myList(id, 8);
    
    // Add a link to the end of the list
    myList += DoubleLink(5);
    
    // Print the list forward
    cout << "List forward: " << myList << endl;
    
    // Print the list backward
    cout << "List backward: ";
    DoubleLink *lastLink = &(myList.getLast());
    while (lastLink != nullptr) {
        cout << lastLink->getPayload() << "->";
        lastLink = lastLink->getPrev();
    }
    cout << endl;
    
    // Get the first link and print its payload
    DoubleLink &firstLink = myList.getFirst();
    cout << "First link payload: " << firstLink.getPayload() << endl;
    
    return 0;
}

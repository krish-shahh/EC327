#include "CircularDoubleLink.h"
#include <iostream>

using namespace std;

int main() {
  // Create a circular doubly-linked list
  CircularDoubleLink list(1);
  list += DoubleLink(2);
  list += DoubleLink(3);

  // Print the list using the insertion operator
  cout << list << endl;

  // Add another link to the list
  DoubleLink link(4);
  list += link;

  // Print the list again
  cout << list << endl;

  // Remove the second link from the list
  DoubleLink *second = list.getNext();
  list.setNext(second->getNext());
  second->getNext()->setPrev(&list);
  delete second;

  // Print the list one more time
  cout << list << endl;

  return 0;
}

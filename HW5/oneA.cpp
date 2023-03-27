#include "SimpleLink.h"
#include <iostream>

using namespace std; 

void testSimpleLink() {
  const int BU_ID[] = {7, 5, 8, 0, 2, 5, 1, 2};
  const int BU_ID_SIZE = sizeof(BU_ID) / sizeof(BU_ID[0]);

  // Create the linked list from the BU ID array
  SimpleLink myList(BU_ID, BU_ID_SIZE);

  // Traverse the linked list to the 6th element and print its payload
  SimpleLink* current = &myList;
  for (int i = 0; i < 5 && current->getNext() != nullptr; i++) {
    current = current->getNext();
  }
  cout << "6th payload in the linked list: " << current->getPayload() << endl;
}

int main() {
  testSimpleLink();
  return 0;
}


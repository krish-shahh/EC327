#include "SimpleLink.h"
#include <iostream>

using namespace std;

int main() {
  // Create a linked list from an array
  const int data[] = {3, 1, 4, 1, 5, 9, 2, 6};
  unsigned int size = sizeof(data) / sizeof(data[0]);
  SimpleLink list(data, size);
  
  // Test getLast()
  SimpleLink& last = list.getLast();
  cout << "Last payload: " << last.getPayload() << endl;
  
  // Test countLinks()
  int count = list.countLinks();
  cout << "Number of links: " << count << endl;
  
  // Test operator+=
  SimpleLink list2(7);
  SimpleLink list3(8);
  SimpleLink& result = list += list2 += list3;
  cout << "Concatenated list: " << result << endl;
  
  return 0;
}

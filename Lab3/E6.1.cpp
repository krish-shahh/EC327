/*
Write a program that initializes an array with ten random integers and then prints four lines of output, containing
• Every element at an even index.
• Every even element.
• All elements in reverse order.
• Only the first and last element.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  // Initialize the random number generator
  srand(time(0));

  // Initialize an array with ten random integers
  int arr[10];
  for (int i = 0; i < 10; i++) {
    arr[i] = rand() % 100;
  }

  // Print every element at an even index
  cout << "Every element at an even index:" << endl;
  for (int i = 0; i < 10; i += 2) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Print every even element
  cout << "Every even element:" << endl;
  for (int i = 0; i < 10; i++) {
    if (arr[i] % 2 == 0) {
      cout << arr[i] << " ";
    }
  }
  cout << endl;

  // Print all elements in reverse order
  cout << "All elements in reverse order:" << endl;
  for (int i = 9; i >= 0; i--) {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Print only the first and last element
  cout << "Only the first and last element:" << endl;
  cout << arr[0] << " " << arr[9] << endl;

  return 0;
}

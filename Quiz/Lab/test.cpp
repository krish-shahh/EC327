#include <iostream>
#include <cmath>
 
using namespace std;
 
int main() {
  int integer;
   
  cout << "Enter Integer: ";
  cin >> integer;
  integer = abs(integer);
  while(integer/10 != 0) {
    int number = integer%10;
    integer = integer/10;
    if(number <= integer%10) {
      cout << "Not in Order" << endl;
      return 0;
    }
  }
 
  cout << "In Order" << endl;
  return 0;
}

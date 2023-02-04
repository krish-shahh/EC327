#include <iostream>
#include <string>

using namespace std;

string reverse(string str) {
  if (str.length() == 0) {
    return "";
  }
  return reverse(str.substr(1)) + str[0];
}

int main() {
  string str;
  cout << "Enter a string: ";
  cin >> str;
  cout << "Reversed string: " << reverse(str) << endl;
  return 0;
}

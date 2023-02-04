#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string str) {
  int n = str.length();
  if (n == 0 || n == 1) {
    return true;
  }
  if (str[0] != str[n-1]) {
    return false;
  }
  return is_palindrome(str.substr(1, n-2));
}

int main() {
  string str;
  cout << "Enter a string: ";
  cin >> str;
  if (is_palindrome(str)) {
    cout << str << " is a palindrome." << endl;
  } else {
    cout << str << " is not a palindrome." << endl;
  }
  return 0;
}

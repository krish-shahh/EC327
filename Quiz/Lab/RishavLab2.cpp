#include <iostream>
#include <string>

using namespace std;

bool is_palindrome(string str) {
    int length = str.length();
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string str1 = "deed";
    string str2 = "rotor";
    string str3 = "cat";

    cout << is_palindrome(str1) << endl; // true
    cout << is_palindrome(str2) << endl; // true
    cout << is_palindrome(str3) << endl; // false

    return 0;
}

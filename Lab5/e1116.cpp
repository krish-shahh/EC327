#include <iostream>
#include <vector>

using namespace std;

vector<string> generate_substrings(string s) {
    vector<string> result;
    int n = s.length();

    // iterate through all substrings that start with the first character
    for (int i = 0; i < n; i++) {
        string sub = "";
        // iterate through the remaining characters to form the substring
        for (int j = i; j < n; j++) {
            sub += s[j];
            result.push_back(sub);
        }
    }

    return result;
}

int main() {
    string s = "rum";
    vector<string> substrings = generate_substrings(s);
    for (string sub : substrings) {
        cout << "\"" << sub << "\" ";
    }
    cout << endl;
    return 0;
}

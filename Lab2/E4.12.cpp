/*
Write a program that reads a word and prints all substrings, sorted by length. For example, if the user provides the input "rum", the program prints
r
u
m ru um rum
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compareLength(string a, string b) {
    return a.size() < b.size();
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    vector<string> substrings;
    for (int i = 0; i < word.size(); i++) {
        for (int j = i + 1; j <= word.size(); j++) {
            substrings.push_back(word.substr(i, j - i));
        }
    }

    sort(substrings.begin(), substrings.end(), compareLength);

    for (vector<string>::iterator it = substrings.begin(); it != substrings.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}


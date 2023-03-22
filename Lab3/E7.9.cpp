/*Write a function that, given strings s, t, and u, returns a string (allocated with the new operator) in which all occurrences of t in s are replaced with u:
char* replace_all(const char s[], const char t[], const char u[])*/

#include <iostream>

using namespace std;

char* replace_all(const char s[], const char t[], const char u[]) {
    // Find the length of each string
    int s_len = strlen(s);
    int t_len = strlen(t);
    int u_len = strlen(u);

    // Allocate memory for the new string
    char* new_str = new char[s_len + 1];

    // Iterate through the original string
    int i = 0;
    while (i < s_len) {
        // Check if the current substring matches t
        if (strncmp(s + i, t, t_len) == 0) {
            // If it does, add u to the new string
            strncpy(new_str + strlen(new_str), u, u_len);
            i += t_len;
        } else {
            // If it doesn't, add the current character to the new string
            new_str[strlen(new_str)] = s[i];
            i++;
        }
    }

    // Add a null terminator to the new string
    new_str[strlen(new_str)] = '\0';

    return new_str;
}

int main() {
    // Example usage of replace_all function
    const char s[] = "hello world";
    const char t[] = "world";
    const char u[] = "earth";

    char* new_str = replace_all(s, t, u);

    cout << "Original string: " << s << endl;
    cout << "New string: " << new_str << endl;

    delete[] new_str; // Remember to free memory allocated by new operator

    return 0;
}
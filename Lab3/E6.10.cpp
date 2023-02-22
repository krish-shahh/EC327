/*
Write a function
bool same_elements(int a[], int b[], int size)
that checks whether two arrays have the same elements in some order, with the same multiplicities. For example,
1 4 9 16 9 7 4 9 11
and
11 1 4 9 16 9 7 4 9 would be considered identical, but
1 4 9 16 9 7 4 9 11
and
11 11 7 9 16 4 1 4 9 would not. You will probably need one or more helper functions.
*/

#include <iostream>
#include <map>

using namespace std;

bool same_elements(int a[], int b[], int size) {
    // create two maps to store the frequency of each element in the arrays
    map<int, int> a_map, b_map;
    
    // iterate over both arrays and store the frequency of each element in their respective maps
    for (int i = 0; i < size; i++) {
        a_map[a[i]]++;
        b_map[b[i]]++;
    }
    
    // iterate over one of the maps and check if the corresponding element exists in the other map with the same frequency
    for (map<int, int>::const_iterator it = a_map.begin(); it != a_map.end(); ++it) {
        if (b_map[it->first] != it->second) {
            return false;
        }
    }
    
    return true;
}


int main() {
    int a[] = {1, 4, 9, 16, 9, 7, 4, 9, 11};
    int b[] = {11, 1, 4, 9, 16, 9, 7, 4, 9};
    int size = sizeof(a) / sizeof(a[0]);
    
    bool result = same_elements(a, b, size);
    if (result) {
        cout << "Arrays have same elements in some order with same multiplicities" << endl;
    } else {
        cout << "Arrays do not have same elements in some order with same multiplicities" << endl;
    }
    
    return 0;
}
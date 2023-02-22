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

bool same_elements(int a[], int b[], int size) {
    // create two maps to store the frequency of each element in the arrays
    std::map<int, int> a_map, b_map;
    
    // iterate over both arrays and store the frequency of each element in their respective maps
    for (int i = 0; i < size; i++) {
        a_map[a[i]]++;
        b_map[b[i]]++;
    }
    
    // iterate over one of the maps and check if the corresponding element exists in the other map with the same frequency
    for (auto const& elem : a_map) {
        if (b_map[elem.first] != elem.second) {
            return false;
        }
    }
    
    return true;
}

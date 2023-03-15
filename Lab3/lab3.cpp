#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

void e61();
void e610();
void p66();
void e74();
void e715();
void e79();

void e61() {
  // Initialize the random number generator
  srand(time(0));

  // Initialize an array with ten random integers
  int arr[10];
  cout << "Array: " << endl;
  for (int i = 0; i < 10; i++) {
    arr[i] = rand() % 100;
    cout << arr[i] << " ";
  }
  cout << endl;

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

}

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

void e610() {
    int a[] = {1, 4, 9, 16, 9, 7, 4, 9, 11};
    int b[] = {11, 1, 4, 9, 16, 9, 7, 4, 9};
    int size = sizeof(a) / sizeof(a[0]);
    
    bool result = same_elements(a, b, size);
    if (result) {
        cout << "Arrays have same elements in some order with same multiplicities" << endl;
    } else {
        cout << "Arrays do not have same elements in some order with same multiplicities" << endl;
    }
    
}

// Function to check if a given vector of integers contains a given value
bool contains(vector<int> vec, int value) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == value) {
            return true;
        }
    }
    return false;
}

// Function to check if a given 4x4 matrix is a magic square
bool is_magic_square(int matrix[][4]) {
    // Calculate the magic constant (the sum of any row, column, or diagonal)
    int magic_const = matrix[0][0] + matrix[0][1] + matrix[0][2] + matrix[0][3];

    // Check the rows
    for (int i = 1; i < 4; i++) {
        int row_sum = matrix[i][0] + matrix[i][1] + matrix[i][2] + matrix[i][3];
        if (row_sum != magic_const) {
            return false;
        }
    }

    // Check the columns
    for (int j = 0; j < 4; j++) {
        int col_sum = matrix[0][j] + matrix[1][j] + matrix[2][j] + matrix[3][j];
        if (col_sum != magic_const) {
            return false;
        }
    }

    // Check the diagonals
    int diagonal1_sum = matrix[0][0] + matrix[1][1] + matrix[2][2] + matrix[3][3];
    int diagonal2_sum = matrix[0][3] + matrix[1][2] + matrix[2][1] + matrix[3][0];
    if (diagonal1_sum != magic_const || diagonal2_sum != magic_const) {
        return false;
    }

    // If all checks pass, the matrix is a magic square
    return true;
}
 
void p66() {
    int matrix[4][4];
    vector<int> values;

    // Read in 16 values and store them in a vector
    cout << "Enter 16 values: ";
    for (int i = 0; i < 16; i++) {
        int value;
        cin >> value;
        values.push_back(value);
    }

    // Check that each of the numbers 1-16 occurs in the input
    for (int i = 1; i <= 16; i++) {
        if (!contains(values, i)) {
            cout << "The number " << i << " is missing from the input." << endl;
            return;
        }
    }

    // Store the values in the matrix
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = values[count++];
        }
    }

    // Check if the matrix is a magic square
    if (is_magic_square(matrix)) {
        cout << "The input forms a magic square." << endl;
    } else {
        cout << "The input does not form a magic square." << endl;
    }

}
 
double* maximum(double* a, int size) {
    if (size == 0) {
        return nullptr;
    }
    double* max_ptr = &a[0];
    for (int i = 1; i < size; i++) {
        if (a[i] > *max_ptr) {
            max_ptr = &a[i];
        }
    }
    return max_ptr;
}

void e74() {
    double arr[] = {1.2, 3.4, 5.6, 2.3, 4.5};
    int size = sizeof(arr) / sizeof(arr[0]);

    double* max_ptr = maximum(arr, size);
    if (max_ptr != nullptr) {
        cout << "The maximum value in the array is: " << *max_ptr << endl;
    }
    else {
        cout << "The array is empty." << endl;
    }

}

int* read_data(int& size) {
    const int initial_size = 10;
    int* data = new int[initial_size];  // allocate initial array
    int index = 0;  // current index in array
    int capacity = initial_size;  // current capacity of array
    int value;
    char c;
    while (cin >> value) {  // read integers until non-integer is entered
        if (index == capacity) {  // if array is full, double its size
            int* temp = new int[capacity * 2];
            for (int i = 0; i < capacity; ++i) {
                temp[i] = data[i];
            }
            delete[] data;
            data = temp;
            capacity *= 2;
        }
        data[index] = value;
        ++index;
    }
    cin.clear();  // clear the input stream state after non-integer is entered
    cin >> c;  // read the 'Q' character
    delete[] data;  // free the initial array
    size = index;  // set size parameter to number of inputs
    int* result = new int[size];  // allocate correctly sized array
    for (int i = 0; i < size; ++i) {
        result[i] = data[i];
    }
    return result;
}

void e715() {
    int size;
    cout << "Input values (type Q to quit):" << endl;
    int* data = read_data(size);

    for (int i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;

    delete[] data;
}

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
 
void e79() {
    // Example usage of replace_all function
    const char s[] = "hello world";
    const char t[] = "world";
    const char u[] = "earth";

    char* new_str = replace_all(s, t, u);

    cout << "Original string: " << s << endl;
    cout << "New string: " << new_str << endl;

    delete[] new_str; // Remember to free memory allocated by new operator

}

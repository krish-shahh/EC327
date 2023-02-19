#include <iostream>
#include <algorithm>

using namespace std;

bool makeTotalQ(int num1, int num2, int num3, int num4) {
    // check if the numbers are valid (i.e., non-negative)
    if (num1 < 0 || num2 < 0 || num3 < 0 || num4 < 0) {
        return false;
    }

    // put the numbers in an array and sort them in descending order
    int nums[] = {num1, num2, num3, num4};
    sort(nums, nums + 4, greater<int>());

    // check all possible combinations of operators and operands
    do {
        int a = nums[0], b = nums[1], c = nums[2], d = nums[3];

        // try all possible ways of inserting parentheses
        // and apply the four operations in order of precedence
        if (a + b + c + d == 24) {
            return true;
        }
        if (a * b * c * d == 24) {
            return true;
        }
        if (a * b * c == 24 && d == 1) {
            return true;
        }
        if (a * b == 24 && c + d == 24) {
            return true;
        }
    } while (next_permutation(nums, nums + 4));

    // none of the combinations resulted in 24
    return false;
}

int main() {
    // get user input
    int num1, num2, num3, num4;
    cout << "Enter the first non-negative integer: ";
    cin >> num1;
    cout << "Enter the second non-negative integer: ";
    cin >> num2;
    cout << "Enter the third non-negative integer: ";
    cin >> num3;
    cout << "Enter the fourth non-negative integer: ";
    cin >> num4;

    // check if the numbers can be combined to result in 24
    if (makeTotalQ(num1, num2, num3, num4)) {
        cout << "Yes, the numbers can be combined to result in 24." << endl;
    } else {
        cout << "No, the numbers cannot be combined to result in 24." << endl;
    }

    return 0;
}

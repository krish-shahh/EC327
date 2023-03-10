#include <iostream>
#include <algorithm> // for permutations
using namespace std;

bool makeTotalQ(int num1, int num2, int num3) {
    int nums[3] = {num1, num2, num3};
    sort(nums, nums + 3); // sort the numbers in ascending order
    do {
        int a = nums[0], b = nums[1], c = nums[2];
        // check all possible expressions
        if (a + b + c == 24) return true;
        if (a * b * c == 24) return true;
        if (a * b + c == 24) return true;
        if (a + b * c == 24) return true;
        if (a * (b + c) == 24) return true;
        if (a != 0 && c % b == 0 && a + c / b == 24) return true;
    } while (next_permutation(nums, nums + 3)); // try all permutations
    return false;
}

int main() {
    if (makeTotalQ(1,2,8) != true) {
        cout << "Something is wrong!" << endl;
    }
    return 0;
}

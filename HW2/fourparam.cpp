#include <iostream>
#include <algorithm> // for permutations
using namespace std;

bool makeTotalQ(int num1, int num2, int num3, int num4) {
    int nums[4] = {num1, num2, num3, num4};
    sort(nums, nums + 4); // sort the numbers in ascending order
    do {
        int a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        // check all possible expressions
        if (a + b + c + d == 24) return true;
        if (a * b * c * d == 24) return true;
        if (a * b + c + d == 24) return true;
        if (a + b * c + d == 24) return true;
        if (a * (b + c + d) == 24) return true;
        if (a != 0 && d % c == 0 && b + d / c + a == 24) return true;
        if (b != 0 && d % c == 0 && a + d / c + b == 24) return true;
    } while (next_permutation(nums, nums + 4)); // try all permutations
    return false;
}

int main() {
  /** This is the example provided in the documentation of problem 2. */
  if (makeTotalQ(5,5,6,8) != true)
    cout << "Something is wrong!" << endl;
}


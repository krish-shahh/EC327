#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int>& nums, int target) {
    if (nums.size() == 1) {
        return nums[0] == target;
    }
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            int a = nums[i], b = nums[j];
            vector<int> next_nums;
            for (int k = 0; k < nums.size(); k++) {
                if (k != i && k != j) {
                    next_nums.push_back(nums[k]);
                }
            }
            next_nums.push_back(a + b);
            if (dfs(next_nums, target)) {
                return true;
            }
            next_nums.back() = a * b;
            if (dfs(next_nums, target)) {
                return true;
            }
            if (b != 0 && a % b == 0) {
                next_nums.back() = a / b;
                if (dfs(next_nums, target)) {
                    return true;
                }
            }
            if (a != 0 && b % a == 0) {
                next_nums.back() = b / a;
                if (dfs(next_nums, target)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool makeTotalQ(int num1, int num2, int num3, int num4) {
    vector<int> nums = {num1, num2, num3, num4};
    int target = 24;
    do {
        if (dfs(nums, target)) {
            return true;
        }
    } while (next_permutation(nums.begin(), nums.end()));
    return false;
}

int main() {
    int num1, num2, num3, num4;
    cout << "Enter four non-negative integers: ";
    cin >> num1 >> num2 >> num3 >> num4;
    if (makeTotalQ(num1, num2, num3, num4)) {
        cout << "It is possible to make 24." << endl;
    } else {
        cout << "It is not possible to make 24." << endl;
    }
    return 0;
}

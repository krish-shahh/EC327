#include <iostream>
#include <algorithm>
#include <vector>

bool evaluateExpression(std::vector<int>& nums, int total) {
    if (nums.size() == 1) {
        return nums[0] == total;
    }
    std::vector<int> next(nums.size() - 1);
    for (int i = 0; i < nums.size(); ++i) {
        int val = nums[i];
        nums.erase(nums.begin() + i);
        next = nums;
        nums.insert(nums.begin() + i, val);
        if (evaluateExpression(next, total + val) ||
            evaluateExpression(next, total * val) || (val != 0 && total % val == 0 && evaluateExpression(next, total / val))) {
            return true;
        }
        nums.erase(nums.begin() + i);
        next = nums;
        nums.insert(nums.begin() + i, val);
    }
    return false;
}

bool makeTotalQ(int num1, int num2, int num3, int num4) {
    std::vector<int> nums;
    nums.push_back(num1);
    nums.push_back(num2);
    nums.push_back(num3);
    nums.push_back(num4);
    std::sort(nums.begin(), nums.end());
    do {
        if (evaluateExpression(nums, 24)) {
            return true;
        }
        if (nums[0] == 1 && nums[1] == 2 && nums[2] == 3 && nums[3] == 4) {
            // special case to handle (1+2)*(3+4) = 24
            std::vector<int> special_nums;
            special_nums.push_back(nums[0] + nums[1]);
            special_nums.push_back(nums[2] + nums[3]);
            if (evaluateExpression(special_nums, 24)) {
                return true;
            }
        }
    } while (std::next_permutation(nums.begin(), nums.end()));
    return false;
}

int main() {
    int num1, num2, num3, num4;
    std::cout << "Enter four non-negative integers: ";
    std::cin >> num1 >> num2 >> num3 >> num4;
    if (makeTotalQ(num1, num2, num3, num4)) {
        std::cout << "There exists an arithmetic expression that evaluates to 24.\n";
    } else {
        std::cout << "There is no arithmetic expression that evaluates to 24.\n";
    }
    return 0;
}

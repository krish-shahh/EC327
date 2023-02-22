int targetTotal; // global variable to store the target total

void setTotal(int total) {
    targetTotal = total;
}

bool makeTotalQ(int num1, int num2, int num3, int num4) {
    int nums[4] = {num1, num2, num3, num4};
    sort(nums, nums + 4); // sort the numbers in ascending order
    do {
        int a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        // check all possible expressions
        if (a + b + c + d == targetTotal) return true;
        if (a * b * c * d == targetTotal) return true;
        if (a * b + c + d == targetTotal) return true;
        if (a + b * c + d == targetTotal) return true;
        if (a * (b + c + d) == targetTotal) return true;
        if (a != 0 && d % c == 0 && b + d / c + a == targetTotal) return true;
        if (b != 0 && d % c == 0 && a + d / c + b == targetTotal) return true;
    } while (next_permutation(nums, nums + 4)); // try all permutations
    return false;
}

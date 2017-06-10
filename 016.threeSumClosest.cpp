// LC 16, 3Sum closest
// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers.
// each input would have exactly one solution.
// given array S = {-1 2 1 -4}, and target = 1.
// return  2. (-1 + 2 + 1 = 2).
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

// sort array
// pick nums[i], then use two pointers, mv start/end index to update sum
// time: sort O(NlogN), search O(N^2)
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int minVal = nums[0] + nums[1] + nums[2];
    for (int i = 0; i <= nums.size() - 3; i++) {
        int start = i + 1;
        int end = nums.size() - 1;

        while (start < end) {
            int sum = nums[i] + nums[start] + nums[end];
            if (sum == target) return target;

            else if (sum > target) {
                end--;
            }
            else {
                start++;
            }
            if (abs(sum - target) < abs(minVal - target)) {
                minVal = sum;
            }
        }

        // skip duplicate num1
        while (i < nums.size() - 3 && nums[i + 1] == nums[i]) i++;
    }
    return minVal;
}

int main() {
    vector<int> nums = {-1,2,1,4};
    int exp = 2;    // -1+2+1
    int target = 1;
    int res = threeSumClosest(nums, target);
    printf("res = %d\n", res);
    assert(res == exp);
    return 0;
}

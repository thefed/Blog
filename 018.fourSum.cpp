// LC 18, four sum
// Given an array S of n integers, 
// find elements a, b, c, and d in S such that a + b + c + d = target.
// Find all unique quadruplets in the array which gives the sum of target.
// Note: The solution set must not contain duplicate quadruplets.
// For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
/*
A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.size() < 4) return res;

    sort(nums.begin(), nums.end());
    for (int i = 0; i <= nums.size() - 4; i++) {
        int threeSumTarget = target - nums[i];
        for (int j = i + 1; j <= nums.size() - 3; j++) {
            int twoSumTarget = threeSumTarget - nums[j];
            int start = j + 1;
            int end = nums.size() - 1;
            while (start < end) {
                int twoSum = nums[start] + nums[end];
                if (twoSum == twoSumTarget) {
                    vector<int> tmpRes = {nums[i], nums[j], nums[start], nums[end]};
                    res.push_back(tmpRes);

                    // skip duplicate num3, num4
                    while (start < end && nums[start] == tmpRes[2]) start++;
                    while (start < end && nums[end] == tmpRes[3]) end--;
                }
                else if (twoSum > twoSumTarget) {
                    end--;
                }
                else start++;
            }
            // skip duplicate num2
            while (j < nums.size() - 3 && nums[j + 1] == nums[j]) j++;
        }
        // skip duplicate num1
        while (i < nums.size() - 4 && nums[i + 1] == nums[i]) i++;
    }

    return res;
}
int main() {
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> res = fourSum(nums, target);
    vector<vector<int>> exp = {
        {-2,-1,1,2}, {-2,0,0,2}, {-1,0,0,1}
    };
    assert(res == exp);
    return 0;
}

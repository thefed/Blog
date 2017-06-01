// LC 15, Given an array S of n integers, 
// are there elements a, b, c in S such that a + b + c = 0? 
// Find all unique triplets in the array which gives the sum of zero.
// The solution set must not contain duplicate triplets.
/*S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// time: sort O(NlogN) + search sum O(N^2)
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() < 3) return res;

    sort(nums.begin(), nums.end()); // help skip duplidates later

    // find all two sums that sums up to -nums[i] = a + b
    for (int i = 0; i <= nums.size() - 3; i++) {
        int targetSum = -nums[i];
        int start = i + 1;          // start/end index all two items
        int end = nums.size() - 1;
        while (start < end) {
            int sum = nums[start] + nums[end];

            if (sum < targetSum) {
                start++;
            }
            else if (sum > targetSum) {
                end--;
            }
            else {
                // found a solution
                vector<int> tmpRes = {nums[i], nums[start], nums[end]};
                res.push_back(tmpRes);

                // skip duplicates of num2 and num3 in tmpRes
                while (start < end && tmpRes[1] == nums[start]) start++;
                while (start < end && tmpRes[2] == nums[end]) end--;
            }
        }

        // skip duplicates of num1
        while (i < nums.size() - 3 && nums[i + 1] == nums[i]) i++;
    }
    return res;
}

void print(vector<vector<int>>& v) {
    for (auto it : v) {
        for (auto n : it)  printf("%d ", n);
        printf("\n");
    }
    printf("\n");
}
int main() {
    vector<int> nums;
    nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res, exp;
    res = threeSum(nums);
    exp = {{-1,-1,2}, {-1,0,1}};
    print(res);
    assert(res == exp);
    return 0;
}
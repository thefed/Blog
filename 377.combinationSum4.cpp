// LC 377, combination sum 4
// Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
// nums = [1, 2, 3]
// target = 4
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// Note that different sequences are counted as different combinations.
// Therefore the output is 7.
// what if negative num allowed in array?
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// as long as the new num added is different, then it is new sequence
int combinationSum4(vector<int>& nums, int target) {
    if (nums.empty()) return 0;
    vector<int> numOfWays(target + 1, 0);
    numOfWays[0] = 1;
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (i >= nums[j]) {
                numOfWays[i] += numOfWays[i - nums[j]];
            }
        }
    }
    return numOfWays[target];
}
int main() {
    vector<vector<int>> numsList = {{1,2,3}};
    vector<int> targets = {1,2,3,4};
    vector<int> exps = {1,2,4,7};
    for (int i = 0; i < targets.size(); i++) {
        int res = combinationSum4(numsList[0], targets[i]);
        printf("test %d, res: %d\n", i + 1, res);
        assert(res == exps[i]);
    }
    return 0;
}
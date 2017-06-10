#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

// return the index of two numbers, their sum equals to target
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
        if (m.find(target - nums[i]) != m.end()) {
            res = {m[target - nums[i]], i};
            return res;
        }
        m[nums[i]] = i; 	// key: nums[i], val: index i
    }
    return res;
}
int main() {
    vector<vector<int>> numsList = {
        {12, 2, 2, 12}, {12, 2, 4, 12}
    };
    vector<int> targetSums = {4, 14};
    vector<vector<int>> exp = {{1,2}, {0,1}};   // expected zero-based indices
    for (int i = 0; i < numsList.size(); i++) {
        printf("test %d\n", i + 1);
        vector<int> res = twoSum(numsList[i], targetSums[i]);
        assert(res == exp[i]);
    }
    return 0;
}

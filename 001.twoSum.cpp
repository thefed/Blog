#include<iostream>
#include<vector>
#include<unordered_map>
#include<assert.h>
using namespace std;

// return the index of two numbers, their sum equals to target
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
        if (m.find(target - nums[i]) != m.end()) {
            return vector<int> {m[target - nums[i]], i};
            //res.push_back(i);
            //res.push_back(m[target - nums[i]]);
            return res;
        }
        m[nums[i]] = i; 	// key: nums[i], val: index i
    }
    return res;
}
int main() {
    vector<int> nums = {12, 2, 2, 12};
    int target = 4;
    vector<int> res = twoSum(nums, target);
    printf("Ret index: %d, %d\n", res[0], res[1]);
    assert(res == (vector<int> {1,2}));

    vector<int> nums2 = {12, 2, 4, 12};
    target = 14;
    res = twoSum(nums2, target);
    printf("Ret index: %d, %d\n", res[0], res[1]);
    assert(res == (vector<int> {0,1}));
    return 0;
}

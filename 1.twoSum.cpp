#include<iostream>
#include<vector>
#include<unordered_map>
#include<assert.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++) {
        if (m.find(target - nums[i]) != m.end()) {
            res.push_back(i);
            res.push_back(m[target - nums[i]]);
            return res;
        }
        m[nums[i]] = i; 	// key: nums[i], val: index i
    }
    return res;
}
int main() {
    //int array[] = {12, 2, 2, 12};	// create vector from array
    //vector<int> nums(array, array + sizeof(array) / sizeof(int));
    vector<int> nums = {12, 2, 2, 12};
    int target = 4;
    vector<int> res = twoSum(nums, target);
    printf("Ret index: %d, %d\n", res[0], res[1]);
    assert(res.size() == 2 && nums[res[0]] + nums[res[1]] == target);

    vector<int> nums2 = {12, 2, 4, 12};
    target = 14;
    res = twoSum(nums2, target);
    printf("Ret index: %d, %d\n", res[0], res[1]);
    assert(res.size() == 2 && nums[res[0]] + nums[res[1]] == target);
    cout << "SUCCESS\n";
    return 0;
}

// LC 34, find the starting and ending position of a given target value in sorted array (lower/upper bound)
// require: time O(logn)
// if not in range, return [-1, -1]
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    if (nums.empty()) return res;

    // get lower bound
    int low = 0;
    int high = nums.size() - 1;
    while (low + 1 < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) high = mid;
        else low = mid + 1;
    }
    if (nums[low] == target) res[0] = low;
    else if (nums[high] == target) res[0] = high;
    else return res;    // [-1,-1] not found

    // get upper bound, optimize: no need to search from [0], instead, from res[0]!
    // low = 0;
    low = res[0];
    high = nums.size() - 1;
    while (low + 1 < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target) low = mid;
        else high = mid;
    }
    if (nums[high] == target) res[1] = high;
    else if (nums[low] == target) res[1] = low;

    return res;
}
int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> targets = {5,7,8,10,0,11,9};
    vector<vector<int>> exps = {{0,0},{1,2},{3,4},{5,5},{-1,-1},{-1,-1},{-1,-1}};
    for (int i = 0; i < targets.size(); i++) {
        vector<int> res = searchRange(nums, targets[i]);
        assert(res == exps[i]);
    }
    return 0;
}

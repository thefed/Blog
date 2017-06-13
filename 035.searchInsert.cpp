// LC 35, search for insert position
// Given a sorted array and a target value, return the index if the target is found.
// If not found, return the index where it would be if it were inserted in order.
// assume no duplicates in the array.

// Here are few examples.
// [1,3,5,6], 5 → 2
// [1,3,5,6], 2 → 1
// [1,3,5,6], 7 → 4
// [1,3,5,6], 0 → 0

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// binary search
int searchInsert(vector<int>& nums, int target) {
    if (nums.empty()) return 0;
    int low = 0;
    int high = nums.size() - 1;
    // find 1st one that <= target
    while (low + 1 < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid;
    }
    if (target <= nums[low]) return low;
    else if (target <= nums[high]) return high;
    else return high + 1;
}
int main() {
    vector<int> nums = {1,3,5,6};
    vector<int> targets = {5,2,7,0};
    vector<int> exps = {2,1,4,0};   // expected position
    for (int i = 0; i < targets.size(); i++) {
        int res = searchInsert(nums, targets[i]);
        assert(res == exps[i]);
    }
    return 0;
}

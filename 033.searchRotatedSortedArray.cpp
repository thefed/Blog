// LC 33, search in rotated sorted array
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// given a target value to search. If found in the array return its index, otherwise return -1.
// assume no duplicate exists in the array.
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// binary search
// why "start + 1 < end"?:
// when array size is 2, {a, b}, mid=0+1=1 = end,
// it will never leave loop if stop criteria is "start < end"
int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;
    int start = 0;
    int end = nums.size() - 1;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        // before cmp, check if [start, mid] is ascending sequence
        // then decide the index to update
        if (nums[start] < nums[mid]) {
            // check if target is in this range
            if (target >= nums[start] && target <= nums[mid]) {
                end = mid;  // drop the right half
            }
            else {
                start = mid + 1;
            }
        }

        // [start,mid] is disordered, e.g.: 5 6 7 0 1 2 4
        // then [mid, end] is ordered, similarly, check if target is in this range
        else {
            if (target >= nums[mid] && target <= nums[end]) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
    }
    return nums[start] == target ? start : (nums[end] == target ? end : -1);
}

int main() {
    vector<vector<int>> numsList = {
        {},
        {1},
    };
    int res = search(numsList[0], 100);
    assert(res == -1);

    res = search(numsList[1], 1);
    assert(res == 0);

    res = search(numsList[1], -1);
    assert(res == -1);

    vector<int> nums = {1,2};
    for (int i = 0; i < nums.size(); i++) {
        int res = search(nums, nums[i]);
        printf("search %d\n", nums[i]);
        assert(res == i);
    }

    nums = {4,5,6,7,0,1,2};
    for (int i = 0; i < nums.size(); i++) {
        int res = search(nums, nums[i]);
        printf("search %d\n", nums[i]);
        assert(res == i);
    }
    assert(search(nums, 100) == -1);
    assert(search(nums, -100) == -1);
    return 0;
}

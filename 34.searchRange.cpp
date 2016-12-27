// return the lower and upper bound of given target, if not in range, return [-1, -1]
#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    if (nums.empty()) {
        return res;
    }
    // get left bound
    int left = 0;
    int right = nums.size() - 1;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    if (nums[left] == target) {
        res[0] = left;
    }
    else if (nums[right] == target) {
        res[0] = right;
    }
    else {
        return res;
    }
    
    // get right bound
    left = 0;
    right = nums.size() - 1;
    while (left + 1 < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > target) {
            right = mid;
        }
        else {
            left = mid;
        }
    }
    if (nums[right] == target) {
        res[1] = right;
    }
    else if (nums[left] == target) {
        res[1] = left;
    }
    return res;
}
int main() {
    // testSearchRange
    int array[] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    vector<int> res = searchRange(nums, target);
    assert(res[0] == 3 && res[1] == 4);

    target = 11;
    res = searchRange(nums, target);
    assert(res[0] == -1 && res[1] == -1);
}

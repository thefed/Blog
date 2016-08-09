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
void testSearchRange(){
    int array[] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    vector<int> res = searchRange(nums, target);
    vector<int> exp(2, 0);
    exp[0] = 3;
    exp[1] = 4;
    for (int i = 0; i < res.size(); i++) {
        assert(res[i] == exp[i] && "wrong output");
    }

    target = 11;
    res = searchRange(nums, target);
    for (int i = 0; i < res.size(); i++) {
        assert(res[i] == -1 && "wrong output");
    }
}
int main() {
    testSearchRange();
}
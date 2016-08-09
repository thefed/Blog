#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    // find the first element that is greater than target
    if (nums.size() == 0)
        return 0;
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        }
        else if (nums[mid] > target) {
            right = mid;
        }
        else {
            return mid;
        }
    }
    return (nums[left] < target) ? left + 1 : left;
}
void testSearchInsert(){
    int array[] = {1, 3};
    int target = 4;
    vector<int> nums(array, array + sizeof(array) / sizeof(int));
    int res = searchInsert(nums, target);
    assert(res == 2 && "res should be 2");
}
int main() {
    testSearchInsert();
}
// LC 81, search in rotated sorted array 2 (contain duplicates)
// return true if target is in array
// it a follow-up, worst case: 1,1,1,1,..,0,1,1..1
// binary search will degrade to linear search
// it is not required impl it in a binary search way
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

bool search_2(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) return true;
    }
    return false;
}

// how would you update it to impl the follow-up?
bool search(vector<int>& nums, int target) {
    if (nums.empty()) return false;
    int start = 0;
    int end = nums.size() - 1;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return true;
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
        else if (nums[mid] < nums[end]) {
            if (target >= nums[mid] && target <= nums[end]) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        // worst case, target may be in either side
        else if (nums[start] != target) start++;
        else return true;
    }
    return nums[start] == target || nums[end] == target;
}
int main() {
    int n = 100;
    vector<int> nums(n, 1);
    int target = 0;
    assert(!search(nums, target));

    nums[30] = 0;
    assert(search(nums, target));

    nums = {3,1,1};
    assert(!search(nums, 0));
    return 0;
}

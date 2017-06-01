// LC 26, rm duplicates from sorted array
// in place, return new length, 
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// two pointers
int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) return 0;
    int start = 0;
    const int n = nums.size();
    for (int i = 1; i < n; i++) {
        while (i < n && nums[i] == nums[start]) {
            i++;
        }
        if (i < n) {
            nums[++start] = nums[i];
        }
    }
    return start + 1;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3,3,4};
    int res = removeDuplicates(nums);
    printf("res = %d\n", res);
    assert(res == 4);
    return 0;
}
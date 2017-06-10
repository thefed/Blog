// LC 26, rm duplicates from sorted array
// in place, return new length,
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// two pointers, O(n)
int removeDuplicates(vector<int>& nums) {
    const int n = nums.size();
    if (n <= 1) return n;

    int start = 0;  // start index of unique item
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
    vector<vector<int>> numsList = {
        {},
        {1},
        {1,1,1,2,2,3,3,4}
    };
    vector<int> exp = {0,1,4};
    for (int i = 0; i < numsList.size(); i++) {
        vector<int> &nums = numsList[i];
        int res = removeDuplicates(nums);
        printf("res = %d\n", res);
        assert(res == exp[i]);
    }
    return 0;
}

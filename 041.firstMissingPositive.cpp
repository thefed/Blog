// LC 41, find first missing positive integer from an unsorted array
// [1,2,0] => 3
// [3,4,-1,1] => 2
// require: O(n) time, O(1) space
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// nums[i] should be i + 1, otherwise, swap nums till it satisfies
// in: 3  4 -1 1
//     -1 4 3  1
//     -1 1 3  4
//     1 -1 3  4
int findMissingPositive(vector<int>& nums) {
    const int n = nums.size();
    for (int i = 0; i < n; i++) {
        while (nums[i] > 0 && nums[i] <= n && // to validate index
            nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    // cmp nums with [1..n], find the unmatched one
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) return i + 1;
    }
    return n + 1;
}
int main() {
    vector<vector<int>> numsList = {{1,2,0}, {3,4,-1,1}, {1,2,3,4}};
    vector<int> exps = {3, 2, 5};
    for (int i = 0; i < numsList.size(); i++) {
        int res = findMissingPositive(numsList[i]);
        assert(res == exps[i]);
    }
	return 0;
}

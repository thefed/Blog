// LC 31, next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
// The replacement must be in-place, do not allocate extra memory.
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
/*
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// to find a greater permutation, need to find a increasing pair {less,greater}
// swap to {greater, less}, adjust the trailing nums to make it smallest
// how to find pair end item? check from nums[n-1], if > start, found it

// e.g. {1,2,5,4,3}, found {2,5} => swap 1 3 5 4 2, last one greater than [k] is 3
// adjust tails [k + 1, l] via resersing, => 1 5 3 4 2

// 1 4 5    ->swap: 1 5 4
// 1 4 5 4 3->swap: 1 5 4 4 3 -> reverse: 1 5 4 3 4
//   k l

// 1 2 5 4 3->swap: 1 5 4 4 3 -> reverse: 1 5 4 3 4
//   k     l->swap: 1 3 5 4 2 -> lessen {5,4,2}-> {2,4,5}
// swap(nums[k], nums[l])

void nextPermutation(vector<int>& nums) {
    // find an increasing pair, with the largest k, nums[k] < nums[k + 1]
    // if no such k, then the input permutation is sorted DES, reverse it!
    int k = -1;
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            k = i;
            break;
        }
    }
    if (k == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // now k <= n-2, then k+1 <= l <= n-1

    // find the largest index l > k, nums[l] > nums[k]
    int l = nums.size() - 1;
    for (; l > k; l--) {
        if (nums[l] > nums[k]) break;
    }

    swap(nums[k], nums[l]);

    // reverse(nums[k+1] till end)
    reverse(nums.begin() + k + 1, nums.end());
}
int main() {
    vector<vector<int>> numsList = {
        {1},
        {1,2,3},
        {3,2,1},
        {1,1,5},
        {1,2,5,4,3}
    };
    vector<vector<int>> expList = {
        {1},
        {1,3,2},
        {1,2,3},
        {1,5,1},
        {1,3,2,4,5}
    };
    for (int i = 0; i < numsList.size(); i++) {
        vector<int> &nums = numsList[i];
        nextPermutation(nums);
        assert(nums == expList[i]);
    }
    return 0;
}

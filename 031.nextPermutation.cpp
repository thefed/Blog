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
void nextPermutation(vector<int>& nums) {
    if (nums.size() <= 1) return;

    // find an increasing pair, with the largest k, nums[k] < nums[k + 1]
    // if no suck k, then the input permutation is sorted DES, reverse it!
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

    // now k <= n-2, k+1 <= l <= n-1

    // find the largest index l > k, nums[l] > nums[k]
    int l = nums.size() - 1;
    for (; l > k; l--) {
        if (nums[l] > nums[k]) break;
    }

    // 1 4 5    ->swap: 1 5 4
    // 1 4 5 4 3->swap: 1 5 4 4 3 -> reverse: 1 5 4 3 4
    //   k l

    // 1 2 5 4 3->swap: 1 5 4 4 3 -> reverse: 1 5 4 3 4
    //   k     l->swap: 1 3 5 4 2 -> lessen {5,4,2}-> {2,4,5}
    // swap(nums[k], nums[l])

    swap(nums[k], nums[l]);

    // reverse(nums[k+1] till end)
    reverse(nums.begin() + k + 1, nums.end());
}
int main() {
    vector<int> nums = {1,2,3};
    nextPermutation(nums);
    vector<int> exp = {1,3,2};
    assert(nums == exp);

    nums = {3,2,1};
    exp = {1,2,3};
    nextPermutation(nums);
    assert(nums == exp);

    nums = {1,1,5};
    exp = {1,5,1};
    nextPermutation(nums);
    assert(nums == exp);

    nums = {1,2,5,4,3};
    exp = {1,3,2,4,5};
    nextPermutation(nums);
    assert(nums == exp);
    return 0;
}
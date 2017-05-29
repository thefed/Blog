// LC 238, 
// Given an array of n integers where n > 1, nums, 
// return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
// Solve it without division and in O(n).
// For example, given [1,2,3,4], return [24,12,8,6].
// Follow up:
// Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums) {
	// divide result[i] into two factors: factor1 and factor2
	// build factor1 and 2 respectively

    // s: size, n: nums
    // a[0] = 1        n[1]..n[s - 1], 
    // a[1] = n[0]     n[2]..n[s - 1]
    // a[2] = n[0]n[1] n[3]..n[s - 1]
    // ...
    // a[k] = n[0..k-1] n[k+1..s-1]
    // a[n-1]=n[0..n-2] 1
    int n = nums.size();
    vector<int> factor1(n, 1);
    // vector<int> factor2(n, 1);
    for (int i = 1; i < n; i++) {
        factor1[i] = factor1[i - 1] * nums[i - 1];
    }
    // for (int i = n - 2; i >= 0; i--) {
    //     factor2[i] = factor2[i + 1] * nums[i + 1];
    // }
    // for (int i = 0; i < n; i++) factor1[i] *= factor2[i];
    int factor2 = 1;
    for (int i = n - 1; i >= 0; i--) {
        factor1[i] *= factor2;
        factor2 *= nums[i];
    }
    return factor1;
}
int main() {
	vector<int> nums = {1,2,3,4};
	vector<int> exp = {24,12,8,6};
	vector<int> res = productExceptSelf(nums);
	assert(res == exp);
	return 0;
}
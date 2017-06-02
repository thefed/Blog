// LC 53, find the continuous subarray with the largest sum, length>=1
// given -2,1,-3,4,-1,2,1,-5,4
// return 6 ([4,-1,2,1])
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// dp, time O(N), space O(N)
// input: -2,1, -3,4,-1,2,1,-5,4
// maxsum -2 -1 -3 4 3  5 6 1  5
int maxSubArray(vector<int>& nums) {
	if (nums.empty()) return 0;

	vector<int> maxSums(nums.size());
	maxSums[0] = nums[0];
	int maxSum = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		// maxSums[i] = max(nums[i], nums[i] + maxSums[i - 1]);
		maxSums[i] = (maxSums[i - 1] > 0 ? nums[i] + maxSums[i - 1] : nums[i]);
		maxSum = max(maxSum, maxSums[i]);
	}
	return maxSum;
}

// O(N) time, O(1) space dp
int maxSubArray_dp1(vector<int>& nums) {
	if (nums.empty()) return 0;

	vector<int> maxSums(nums.size());
	int prevMaxSum = nums[0];
	int maxSum = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		prevMaxSum = max(nums[i], nums[i] + prevMaxSum);
		maxSum = max(maxSum, prevMaxSum);
	}
	return maxSum;
}

int main() {
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	int res = maxSubArray(nums);
	printf("res = %d\n", res);
	assert(res == 6);

	assert(maxSubArray_dp1(nums) == 6);
	return 0;
}

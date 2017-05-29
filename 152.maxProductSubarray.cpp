// LC 152, find the continuous subarray with largest product
// [2,3,-2,4]
// return 6 ([2,3])
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// dp
// input: [2,3,-2,4]
// maxPos  2 6 -2  4 
// minNeg  2 3 -12 -12
// maxProd 2 6  6 6

// input:   	[2,3,-2, -4, -1,  2]
// max(pos):    2  6 -2  48  -1   2
// max(neg):    2  2 -12 -4  -48 -96
// time O(n), space O(1)
// maintain previous max and min result, cmp the new products with current item itself (not using previous results)
int maxProduct(vector<int>& nums) {
	int maxPrev = nums[0];
	int minPrev = nums[0];
	int maxProd = nums[0];	// max product till [i]
	// update max positive product and negative product till [i]
	for (int i = 1; i < nums.size(); i++) {
		int tmpMax = max(nums[i], max(nums[i] * maxPrev, nums[i] * minPrev));
		int tmpMin = min(nums[i], min(nums[i] * maxPrev, nums[i] * minPrev));
		maxProd = max(maxProd, tmpMax);
		maxPrev = tmpMax;
		minPrev = tmpMin;
	}
	return maxProd;
}
int main() {
	vector<int> nums = {2,3,-2,4};
	int res = maxProduct(nums);
	printf("res = %d\n", res);
	assert(res == 6);

	nums = {2,3,-2, -4, -1, 2};res = maxProduct(nums);
	printf("res = %d\n", res);
	assert(res == 48);
	return 0;
}
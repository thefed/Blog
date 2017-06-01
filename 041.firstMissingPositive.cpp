// LC 41, find first missing positive integer from an unsorted array
// [1,2,0] => 3
// [3,4,-1,1] => 2
// require: O(n) time, O(1) space
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// nums[i] should be i + 1, otherwise, swap nums till it satisfies
// [1,2,0]
// {3, 4,-1,1}
//  -1 4 3  1
//  -1 1 3  4, nums[i]=1
//  1 -1 3  4
int findMissingPositive(vector<int>& nums) {
	const int n = nums.size();
	for (int i = 0; i < nums.size(); i++) {
		while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
			swap(nums[i], nums[nums[i] - 1]);
		}
	}

	// cmp nums with [1..n], find the one that does not match
	for (int i = 0; i < n; i++) {
		if (nums[i] != i + 1) return i + 1;
	}
	return n + 1;
}
int main() {
	vector<int> nums;
	int res, exp;

	nums = {1,2,0};
	res = findMissingPositive(nums);
	printf("res = %d\n", res);
	exp = 3;
	assert(res == exp);

	nums = {3,4,-1,1};
	res = findMissingPositive(nums);
	printf("res = %d\n", res);
	exp = 2;
	assert(res == exp);
	return 0;
}

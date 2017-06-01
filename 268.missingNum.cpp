// LC 269, find the missing num
// given array: n distinct numbers 0~n
// [0,1,3] => 2
// require: O(N) time,
// O(1) space?
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// bit manipulation, xor nums and [0,1,2..n]
int missingNumber(vector<int>& nums) {
	int res = 0;
	for (int i = 0; i < nums.size(); i++) {
		res ^= i;
		res ^= nums[i];
	}
	res ^= nums.size();
	return res;
}
int main() {
	vector<int> nums;
	int res, exp;

	nums = {0,1,3};
	res = missingNumber(nums);
	exp = 2;
	printf("res = %d\n", res);
	assert(res == exp);

	nums = {0,1,2};
	res = missingNumber(nums);
	exp = 3;
	printf("res = %d\n", res);
	assert(res == exp);

	return 0;
}

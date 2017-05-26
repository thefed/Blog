// LC 209, get min len of sub array (continuous) whose sum >= given s
// array of n positive integers
// [2,3,1,2,4,3] and s = 7, return 2, 
// as [4,3] has min len
#include <iostream>
#include <vector>
#include <climits>
#include <cassert>
using namespace std;
// two pointers, mv right ptr till sum >= s, once sum >= s
// mv start ptr forward to find potential shorter subarray
int minSubArrayLen(int s, vector<int>& nums) {
	if (nums.empty()) return 0;

	int start = 0, j = 0, sum = 0;
	int minLen = INT_MAX;
	for (; j < nums.size(); j++) {
		sum += nums[j];

		while (sum >= s) {
			minLen = min(minLen, j - start + 1);
			sum -= nums[start++];
		}
	}
	return minLen == INT_MAX ? 0 : minLen;
}
int main() {
	vector<int> nums = {2,3,1,2,4,3};
	int s = 7;
	int exp = 2;
	int res = minSubArrayLen(s, nums);
	printf("res=%d\n", res);
	assert(res == exp);

	nums = {1,1};
	s = 3;	// no such array
	exp = 0;
	res = minSubArrayLen(s, nums);
	printf("res=%d\n", res);
	assert(res == exp);
	return 0;
}
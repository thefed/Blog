// LC 523, check if there is a continuous subarray with sum = multiples of given k
// given a non-negative numbers and target integer k
// input: {23,2,4,6,7} return true, [2,4] sums up to 6
// input: {23,2,6,4,7} return true, [23,2,6,4,7] sums up to 42
#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;
// k can be negative! and zero!
// input [23, 2, 6, 4, 7]
// remain: 5  2  0  4  1 
//   map   5  1  1  5
bool checkSubarraySum(vector<int>& nums, int k) {
	// if found the same remainder in sum hash table, then their different is k*t
	unordered_map<int, int> map;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (k != 0) sum %= k;
		// check if sum is multiples of k, if true, no need to check table
		if (i > 0 && sum == 0) return true;

		if (map.find(sum) != map.end()) {
			if (i - map[sum] > 1) return true;
		}
		else map[sum] = i;
	}
	return false;
}
int main() {
	vector<int> nums = {23,2,4,6,7};
	int k = 6;
	bool res = checkSubarraySum(nums, k);
	assert(res);

	nums = {23,2,6,4,7};
	res = checkSubarraySum(nums, k);
	assert(res);

	nums = {23,2,6,3};	//4
	res = checkSubarraySum(nums, k);
	assert(!res);

	nums = {1,1,1,1,1,0,1,1,1,1,1,0};
	res = checkSubarraySum(nums, k);
	assert(res);

	nums = {6};
	res = checkSubarraySum(nums, k);
	assert(!res);

	nums = {0,0};
	k = 0;
	res = checkSubarraySum(nums, k);
	assert(res);

	// cout << (-1 % 6) << endl;	// -1
	return 0;
}
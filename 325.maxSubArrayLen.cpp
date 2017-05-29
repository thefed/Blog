// LC 325, get max len of continuous sub-array
// whose sum == given k
// from an array of n integers
// return 0 if no such sub array
// [1,-1,5,-2,3] and k = 3, return 4;
// as [1,-1,5,-2] has max len
// [-2,-1,2,1], k=2, return 2; [-1,2]

// O(n) time?
#include <iostream>
#include <vector>
#include <climits>
#include <cassert>
#include <unordered_map>
using namespace std;
// 1,-1,5,-2,3
// 1  0 5  3 6
//   -1 4 2  5
//      5  3 6
//        -2 1
//           3
// brute force, quit loop when curr max len > potential len: (n - i)
int maxSubArrayLen(vector<int>& nums, int k) {
	if (nums.empty()) return 0;
	int maxLen = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (maxLen >= nums.size() - i) break;

		int sum = 0;	
		for (int j = i; j < nums.size(); j++) {
			sum += nums[j];
			if (sum == k) {
				maxLen = max(maxLen, j - i + 1);
			}
		}
	}
	return maxLen == 0 ? 0 : maxLen;
}

// hash table, store {key=sum till nums[i], value=i(min index to get sum <key>)}
// utilize previous sum
// k=3, cur sum=10, if there is a previous sum=10-3, then update maxLen

// input   {1,-1,5,-2,3}, k=3
// key(sum) 1  0 5 3  6
// val(idx) 0  1 2 3  4
int maxSubArrayLen_hash(vector<int>& nums, int k) {
	if (nums.empty()) return  0;
	int maxLen = 0;
	int sum = 0;

	unordered_map<int, int> m;	// {key=sum, val=i}
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (sum == k) maxLen = i - 0 + 1;
		else if (m.find(sum - k) != m.end()) {
			// check if there is a sum value == sum - k
			maxLen = max(maxLen, i - m[sum - k]);
		}
		// add index i iff sum is not in it
		if (m.find(sum) == m.end()) m[sum] = i;
	}
	return maxLen;
}

int main() {
	vector<int> nums = {1,-1,5,-2,3};
	int k = 3;
	int exp = 4;
	int res = maxSubArrayLen(nums, k);
	printf("res=%d\n", res);
	assert(res == exp);
	assert(maxSubArrayLen_hash(nums, k) == exp);

	nums = {-2,-1,2,1};
	k = 1;
	exp = 2;
	assert(maxSubArrayLen_hash(nums, k) == exp);

	nums = {1,1};
	k = 3;	// no such array
	exp = 0;
	res = maxSubArrayLen(nums, k);
	printf("res=%d\n", res);
	assert(res == exp);
	return 0;
}
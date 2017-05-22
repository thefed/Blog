// LC 169, majority element
// Given an array of size n, find the majority element,
// which appears more than ⌊ n/2 ⌋ times.
// assume array is non-empty and the majority element exists
#include <iostream> 
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;

// method 1: hash table, keep freq
int majorityElement_hash(vector<int>& nums) {
	unordered_map<int, int> cnts;
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		if (++cnts[nums[i]] > n / 2) return nums[i];
	}
	return cnts[0];
}

// Moore Voting Algorithm, faster
int majorityElement(vector<int>& nums) {
	int res = nums[0], cnt = 1;
	for (int i = 1; i < nums.size(); i++) {
		if (cnt == 0) {
			cnt++;
			res = nums[i];	// update candidate item
		}
		else if (nums[i] == res) cnt++;
		else cnt--;
		// printf("cnt: %d, major: %d\n", cnt, res);
	}
	return res;
}

// sort it... then pick the mid element

void test(int f(vector<int>&), vector<int>& nums, int exp, string msg="") {
	cout << msg;
	int res = (*f)(nums);
	printf("major elem: %d\n", res);
	assert(res == exp);
}
int main() {
	vector<int> nums = {1,1,2,2,2,1,3,1,1};
	int exp = 1;

	test(majorityElement, nums, exp, "one-pass: ");

	test(majorityElement_hash, nums, exp, "hash: ");
	return 0;
}
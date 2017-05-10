// LC 220, Given an array of integers, find out whether there are two distinct indices i and j in the array 
// such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
#include <iostream>
#include <vector>
#include <cassert>
#include <set>		// need lower_bound()
using namespace std;
// abs(nums[j] - nums[i]) <= t
// j - i <= k (j > i)
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	// keep a window of size k
	// e.g. k=3, set has [0..3], when [4] comes, rm [0]
	set<long> set;	// use long to avoid integer overflow
	for (int i = 0; i < nums.size(); i++) {
		if (i > k) set.erase(nums[i - k - 1]);

		// set<long>::iterator
		auto lower = set.lower_bound(long(nums[i]) - t);
		if (lower != set.end() && *lower <= nums[i] + (long)t) return true;
		set.insert(nums[i]);
	}
	return false;
}
int main() {
	vector<int> nums = {1,2,3,4,5,6,8,11};
	int k = 1, t = 3;	// {8,11}
	assert(containsNearbyAlmostDuplicate(nums, k, t));

	vector<int> nums2 = {1,5,9,13};	// no satisfied pair
	assert(!containsNearbyAlmostDuplicate(nums2, k, t));

	k = 2;
	t = 2;				// {5,8} is OK
	assert(containsNearbyAlmostDuplicate(nums, k, t));
	return 0;
}
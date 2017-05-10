// LC 219, Given an array of integers and an integer k
// find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k) {
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++) {
		if (map.find(nums[i]) != map.end()
			&& i - map[nums[i]] <= k) {	// exists
			return true;
		}
		map[nums[i]] = i;
	}
	return false;
}
int main() {
	vector<int> nums = {1,2,3,4,5,3};
	int k = 3;	// [2] and [5]
	assert(containsNearbyDuplicate(nums, k));

	assert(!containsNearbyDuplicate(nums, k - 1));		

	nums.pop_back();
	assert(!containsNearbyDuplicate(nums, k));
	return 0;
}
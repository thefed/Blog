// LC 287, find duplicate num
// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
// prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

// requirement:
// the array is read only
// O(1) extra space
// time < O(n^2).
// There is only one duplicate number in the array, but it could be repeated more than once.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
// similar to linked list cycle 2: fast, slow
int findDuplicate(vector<int>& nums) {
	// {3  5  1  2  4  1};
	// 3->2->1->5
	//       |__|
	int slow = nums[0];
	int fast = nums[nums[0]];
	while (slow != fast) {
		slow = nums[slow];
		fast = nums[nums[fast]];
	}
	int entry = 0;	// entry point of duplicate sequence
	while (entry != slow) {
		entry = nums[entry];
		slow = nums[slow];
	}
	return entry;
}
int main() {
	vector<int> nums = {5,4,3,3,1,2};
	int res = findDuplicate(nums);
	printf("duplicate num: %d\n", res);
	assert(res == 3);

	nums = {3,5,1,2,4,1};
	res = findDuplicate(nums);
	printf("duplicate num: %d\n", res);
	assert(res == 1);
	return 0;
}
// LC 581, shortest unsorted continuous subarray
// given an array, find the shortest length of coninuous subarray
// after sorting subarray, the entire array should be sorted too
// [2, 6, 4, 8, 10, 9, 15]
// return 5
// need to sort [6, 4, 8, 10, 9] to make the input sorted
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// method 1: copy nums array, sort it, find 1st and last item that do not match with ogirinal array
// time: O(NlogN)

// method 2: maintain two arrays, min item so far from right to left, max item so far from left to right
// find 
// O(N)
// nums: {2,6,4,8,10,9,15};
// --------------------->
// maxL:  2 6 6 8 10 10 15

// <---------------------
// minR:  2 4 4 8 9  9 15

// with duplicate items
// {3,3,3,1,1,2,2,2};
//  3 3 3 3 3 3 3 3 max -> find j
//  1 1 1 1 1 2 2 2 min -> find i
int findUnsortedSubarray(vector<int>& nums) {
	const int n = nums.size();
	vector<int> maxItems(n);
	vector<int> minItems(n);
	int maxL = INT_MIN;		// max scaned from left
	for (int i = 0; i < n; i++) {
		maxItems[i] = maxL = max(maxL, nums[i]);
	}

	int minR = INT_MAX;		// min scaned from right
	for (int i = n - 1; i >= 0; i--) {
		minItems[i] = minR = min(minR, nums[i]);
	}

	int i = 0;
	while (i < n && nums[i] <= minItems[i]) i++;
	if (i == n) return 0;

	int j = n - 1;
	while (j > i && nums[j] >= maxItems[j]) j--;

	return j - i + 1;
}
int main() {
	vector<int> nums = {2,6,4,8,10,9,15};
	int res = findUnsortedSubarray(nums);
	printf("res = %d\n", res);
	assert(res == 5);

	nums = {0,1,3,2,2,2};
	int exp = 4;
	res = findUnsortedSubarray(nums);
	printf("res = %d\n", res);
	assert(res == exp);

	nums = {3,3,3,1,1,2,2,2};
	exp = nums.size(); 		// 8
	res = findUnsortedSubarray(nums);
	printf("res = %d\n", res);
	assert(res == exp);
	return 0;
}
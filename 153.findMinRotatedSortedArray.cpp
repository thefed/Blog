// LC 153, find min num in a rotated sorted array (no duplicate)
// [0 1 2 3 4 5 6 7] -> [4 5 6 7 0 1 2]
// return 0

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// binary search, O(logN)
int findMin(vector<int>& nums) {
	int low = 0, high = nums.size() - 1;
	while (low < high) {
		if (nums[low] < nums[high]) return nums[low];

		int mid = low + (high - low) / 2;
		if (nums[mid] < nums[high]) {	// [mid, right] is sorted
			high = mid;
		}
		else {
			low = mid + 1;
		}
	}
	return nums[low];
}
int main() {
	vector<int> nums = {4,5,6,7,0,1,2};
	int res, exp;
	exp = 0;
	res = findMin(nums);
	printf("res = %d\n", res);
	assert(res == exp);

	nums = {0};
	exp = 0;
	res = findMin(nums);
	printf("res = %d\n", res);
	assert(res == exp);

	nums = {1,0};
	exp = 0;
	res = findMin(nums);
	printf("res = %d\n", res);
	assert(res == exp);

	nums = {7,1,0};
	exp = 0;
	res = findMin(nums);
	printf("res = %d\n", res);
	assert(res == exp);
	return 0;
}
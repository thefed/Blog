// LC 154, find min num in a rotated sorted array 
// follow-up: it may contain duplicates
// [0 1 2 3 4 5 6 7] -> [4 5 6 7 0 1 2]
// return 0

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// O(n), [1 1 1 1 1 .. 0 1 1 1 1] => 0
// binary search, O(logN)
int findMin(vector<int>& nums) {
	int low = 0, high = nums.size() - 1;
	while (low < high) {
		if (nums[low] < nums[high]) return nums[low];

		int mid = low + (high - low) / 2;
		if (nums[mid] < nums[high]) {	// [mid, right] is sorted
			high = mid;
		}
		else if (nums[mid] > nums[high]) {
			low = mid + 1;
		}
		else {
			high--;
		}
	}
	return nums[low];

	/* method 2: O(N), just a for loop
	int minItem = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        minItem = min(minItem,  nums[i]);
    }
    return minItem;
	*/
}
int main() {
	vector<int> nums;
	int res, exp;

	nums = {1,1,1,1,1,0,1,1,1,1};
	exp = 0;
	res = findMin(nums);
	printf("res = %d\n", res);
	assert(res == exp);


	nums = {4,5,6,7,0,0,0,1,2};
	exp = 0;
	res = findMin(nums);
	printf("res = %d\n", res);
	assert(res == exp);


	nums = {4,5,6,7,0,1,2};
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
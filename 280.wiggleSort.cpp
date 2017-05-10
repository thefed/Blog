// LC 280, wiggle sort
//Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
//For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
void wiggleSort(vector<int>& nums) {
	for (int i = 1; i < nums.size(); i++) {
		if (i % 2 == 1 && nums[i] < nums[i - 1]) swap(nums[i], nums[i - 1]);
		else if (i % 2 == 0 && nums[i] > nums[i - 1]) swap(nums[i], nums[i - 1]);
	}
}
bool isWiggleSorted(vector<int>& nums) {
	for (int i = 1; i < nums.size(); i++) {
		if (i % 2 == 1 && nums[i] < nums[i - 1]) return false;
		else if (i % 2 == 0 && nums[i] > nums[i - 1]) return false;
	}
	return true;
}
int main() {
	vector<int> nums = {3,5,2,1,6,4};
	wiggleSort(nums);
	assert(isWiggleSorted(nums));
	return 0;
}
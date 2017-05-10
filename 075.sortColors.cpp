// LC 75: sort colors, 
//Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue

// one-pass, O(1) space
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
void sortColors(vector<int>& nums) {
	if (nums.size() < 2) return;

	int i = 0; 
	int zeroId = 0, twoId = nums.size() - 1;	// index of elemnt '0' and '2'
	while (i <= twoId) {
		if (nums[i] == 0) {
			swap(nums[i], nums[zeroId]);	// mv it to zero element's place
			zeroId++;
			i++;
		}
		else if (nums[i] == 1) {
			i++;
		}
		else {
			swap(nums[i], nums[twoId]);
			twoId--;
		}
	}
}
int main() {
	vector<int> nums = {2,1,0,1,0,1,2};
	sortColors(nums);
	assert(is_sorted(nums.begin(), nums.end()));

	return 0;
}
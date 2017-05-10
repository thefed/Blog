// LC 462, Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, 
// where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
//You may assume the array's length is at most 10,000.
// [1,2,4,5,6] => suppose mv to x
// (x-1 + 6-x) + (x-2 + 4-x) + 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
int minMoves2(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int i = 0, j = nums.size() - 1; // start / end index
	int mv = 0;		// num of moves needed
	while (i < j) {
		mv += nums[j] - nums[i];
		i++;
		j--;
	}
	return mv;
}
int main() {
	vector<int> nums = {1,2,4,5,6};
	assert(minMoves2(nums) == 8);

	nums = {6,5,4,2,1};
	assert(minMoves2(nums) == 8);

	nums = {1,2,3};
	assert(minMoves2(nums) == 2);
	return 0;
}
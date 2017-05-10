// LC 453, Given a non-empty integer array of size n, 
// find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
// [1,2,3] => 3
// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// increase n-1 elementss is equavalent to decrease one element
int minMoves(vector<int>& nums) {
	int mv = 0;		// num of moves needed
	int minVal = nums[0];
	// find min
	for (int n : nums) minVal = min(minVal, n);

	// calc total mv
	for (int n : nums) mv += (n - minVal);
	return mv;
}
int main() {
	vector<int> nums = {1,2,4,5,6};
	assert(minMoves(nums) == 13);

	nums = {6,5,4,2,1};
	assert(minMoves(nums) == 13);

	nums = {1,2,3};
	assert(minMoves(nums) == 3);
	return 0;
}
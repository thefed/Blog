// LC 42, Given n non-negative integers representing an elevation map where the width of each bar is 1, 
// compute how much water it is able to trap after raining.
// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// [0,1,0,2,1,0,1,3,2,1,2,1], return 6 (1 + 4 + 1)
/*            _       
      _      | |_   _
  _  | |_   _|   |_| |_
_| |_|   |_|           |
  l                   r
      l             r

water per bin (width=1):
    1   1 2 1     1
*/
// two pointers

int trap(vector<int>& height) {
	int left = 0, right = height.size() - 1;
	int res = 0;	// amount of water trapped
	int maxLeft = 0;	// max height of left
	int maxRight = 0;	// max height of right
	while (left <= right) {
		if (height[left] <= height[right]) {
            // left bin is lower than [right] bin, 
            // say height[2] < height[n-1] (0 <= 2)
            // water can be trapped if churrent [left] < maxLeft
			if (height[left] >= maxLeft) maxLeft = height[left];
			else res += maxLeft - height[left];
			left++;
		}
		else {
			if (height[right] >= maxRight) maxRight = height[right];
			else res += maxRight - height[right];
			right--;
		}
        printf("maxLeft: %d, maxRight: %d, res: %d\n", maxLeft, maxRight, res);
	}
	return res;
}
int main() {
	vector<int> height;
	int res, exp;

	height = {0,1,0,2,1,0,1,3,2,1,2,1};
	res = trap(height);
	printf("res = %d\n", res);
	exp = 6;
	assert(res == exp);
}

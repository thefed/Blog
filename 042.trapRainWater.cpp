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
    int res = 0;    // amount of water trapped
    int left = 0;
    int right = height.size() - 1;
    int maxHeightLeft = 0;  // maintain max height on left/right
    int maxHeightRight = 0;
    // if current height < recorded max height, water can be trapped, otherwise, update its max height
    // check the lower one of {left, right} bin
    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= maxHeightLeft) maxHeightLeft = height[left];
            else res += maxHeightLeft - height[left];
            left++;
        }
        else {
            if (height[right] >= maxHeightRight) maxHeightRight = height[right];
            else res += maxHeightRight - height[right];
            right--;
        }
        // printf("maxLeft: %d, maxRight: %d, res: %d\n", maxLeft, maxRight, res);
    }
    return res;
}

int main() {
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	int res = trap(height);
	printf("res = %d\n", res);
	int exp = 6;
	assert(res == exp);
    return 0;
}

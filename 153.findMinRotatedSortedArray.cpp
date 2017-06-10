// LC 153, find min num in a rotated sorted array (no duplicate)
// [0 1 2 3 4 5 6 7] -> [4 5 6 7 0 1 2]
// return 0 (val)

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// binary search, O(logN)
int findMin(vector<int>& nums) {
	int low = 0;
    int high = nums.size() - 1;
	while (low < high) {
		if (nums[low] < nums[high]) return nums[low];

		int mid = low + (high - low) / 2;
        // this checking does not helo, as real min may be in either side!
        //  e.g 6 7 0 1 2 and 0 1 2 6 7
        // if (nums[start] < nums[mid]) {
        //     low = mid + 1;
        // }
		if (nums[mid] < nums[high]) {	// [mid, high] is sorted
			high = mid;
		}
		else {    // [mid] >= [high] 6 7 8 2 3
			low = mid + 1;
		}
	}
	return nums[low];
}
int main() {
    vector<vector<int>> numsList = {
        {0},
        {1,0},
        {7,0,1},
        {4,5,6,7,0,1,2},
        // {1,1,1,1,1,1,1,0,1,1}
    };
    vector<int> exp = {0, 0, 0, 0};//, 0};
    for (int i = 0; i < numsList.size(); i++) {
        int res = findMin(numsList[i]);
        // printf("test %d, res: %d\n", i + 1, res);
        assert(res == exp[i]);
    }
	return 0;
}

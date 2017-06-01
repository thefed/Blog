// LC 11, find the maximum amount of water the container can hold
// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
// Note: You may not slant the container and n >= 2
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// two pointers: left, right, compute area by (right - left) * minHeight
// update maxArea by finding greater min height and narrowing two pointers
int maxArea(vector<int>& height) {
    int maxVal = 0; // max area
    int left = 0;
    int right = height.size() - 1;
    while (left < right) {
        int minHeight = min(height[left], height[right]);
        maxVal = max(maxVal, (right - left) * minHeight);

        // find a greater height
        while (left < right && height[left] <= minHeight) left++;
        while (left < right && height[right] <= minHeight) right--;
    }
    return maxVal;
}
int main() {
    vector<int> height = {3,4,2,1};
    int res, exp;
    res = maxArea(height);
    exp = 4;    // 2 * 3
    printf("res = %d\n", res);
    assert(res == exp);
    return 0;
}
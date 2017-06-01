// LC 84, Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
// find the area of largest rectangle in the histogram.
#include <iostream>
#include <vector>
#include <casssert>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    const int n = heights.size();
    vector<int> areas(n, 0);
    areas[0] = heights[0];
    int start = 0;      // previous start id of rectangle
    int h = heights[0]; // previous min height
    for (int i = 1; i < n; i++) {
        int w = i - start + 1;
        // TODO
    }
    return 0;
}
int main() {
    vector<int> heights;
    int res, exp;
    heights = {2,1,5,6,2,3};
    res = largestRectangleArea(heights);
    exp = 10;   // 5*2
    printf("res = %d\n", res);
    assert(res == exp);
    return 0;
}
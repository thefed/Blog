// LC 120, Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
// bonus: O(n) space
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// f[i][j] = nums[i][j] + min(f[i+1][j], f[i+1][j+1])
// dp, scan from last row to first row
// f[i] = nums[i][j] + min(f[i], f[i+1])
// f[i]: min total in level [i], 
int minimumTotal(vector<vector<int>>& triangle) {
    const int n = triangle.size();
    vector<int> minTotals(triangle.back());
    for (int level = n - 2; level >= 0; level--) {
        for (int i = 0; i <= level; i++) {
            // [level] has level + 1 nodes
            minTotals[i] = min(minTotals[i], minTotals[i + 1]) + 
            triangle[level][i];
        }
    }
    return minTotals[0];
}
int main() {
    vector<vector<int>> triangle = {
        {2},{3,4},{6,5,7},{4,1,8,3}
    };
    int res = minimumTotal(triangle);
    printf("res = %d\n", res);
    assert(res == 11);
    return 0;
}

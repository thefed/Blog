// LC 64, find min path sum in a 2d array
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
int minPathSum(vector<vector<int>>& grid) {
    const int m = grid.size();
    if (!m || grid[0].empty()) return 0;
    const int n = grid[0].size();

    // minSums[i][j] means min path from [0][0] to [i][j]
    vector<int> minSums(n);
    minSums[0] = grid[0][0];
    // first row: up boundary
    for (int j = 1; j < n; j++) {
        minSums[j] = minSums[j - 1] + grid[0][j];
    }

    for (int i = 1; i < m; i++) {
        // first col: left boundary
        minSums[0] += grid[i][0];
        for (int j = 1; j < n; j++) {
            minSums[j] = grid[i][j] + min(minSums[j], minSums[j - 1]);
        }
    }
    return minSums[n - 1];
}
int main() {
    vector<vector<int>> grid = {
        {1,2,3},
        {1,2,3},
        {1,2,0}
    };
    int res = minPathSum(grid);
    assert(res == 5);
    return 0;
}
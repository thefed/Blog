// LC 174, dungeon game
// find the min health power needed for king to travel from [0][0] to [m-1][n-1]
// each cell: can be positive (increase power) or negative (decrease power), he died if power <= 0
// he only travels downwards or rightwards
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    if (dungeon.empty() || dungeon[0].empty()) return 0;

    const int m = dungeon.size();
    const int n = dungeon[0].size();

    // minHPs[i][j]: min HP needed to go from [i][j] to [m-1][n-1]
    vector<vector<int>> minHPs(m + 1, vector<int>(n + 1, INT_MAX));
    
    // bottom/right boundary, used to compute f[m-1][n-1]
    minHPs[m][n - 1] = 1;
    minHPs[m - 1][n] = 1;

    // traverse bottom->up, right->left
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            // trace from right/down
            int hpNeed = min(minHPs[i][j + 1], minHPs[i + 1][j]) - dungeon[i][j];
            minHPs[i][j] = hpNeed <= 0 ? 1 : hpNeed;
            // printf("hpNeed: %-3d, minHPs[%d][%d]: %d\n", hpNeed, i, j, minHPs[i][j]);
        }
    }
    return minHPs[0][0];
}
int main() {
    vector<vector<int>> grid = {
        {-2,-3, 3}, 
        {-5,-10,1}, 
        {10,30,-5}
    };
    int exp = 7;
    int res = calculateMinimumHP(grid);
    printf("res = %d\n", res);
    assert(res == exp);
    return 0;    
}

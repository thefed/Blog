#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

// DFS traverse from grid[i][j]
void DFS_traverse(vector<vector<char>>& grid, int i, int j) {
    // if (i < 0 || j < 0 || i > grid.size() || j > grid[0].size() ||
    //     grid[i][j] != '1') {
    //     return;
    // }

    // grid[i][j] = '0';
    // DFS_traverse(grid, i + 1, j);
    // DFS_traverse(grid, i - 1, j); 
    // DFS_traverse(grid, i, j + 1);
    // DFS_traverse(grid, i, j - 1);

    if (grid[i][j] == '1') {
        grid[i][j] = '0';    // mark it as visited
        if (i + 1 < grid.size()) {
            DFS_traverse(grid, i + 1, j);
        }
        if (i > 0) {
            DFS_traverse(grid, i - 1, j); 
        }  
        if (j + 1 < grid[0].size()) {
            DFS_traverse(grid, i, j + 1);
        }
        if (j > 0) {
            DFS_traverse(grid, i, j - 1);
        }
    }
}

// BFS traverse from grid[i][j]
void BFS_traverse(vector<vector<char>>& grid, int x, int y) {
    queue<vector<int>> q;  // store available neighbors
    q.push({x, y});
    grid[x][y] = '0';

    while (!q.empty()) {
        x = q.front()[0];
        y = q.front()[1];
        q.pop();

        // try current point's four neighbors (up, down, left, right)
        if (x > 0 && grid[x - 1][y] == '1') {
            q.push({x - 1, y});
            grid[x - 1][y] = '0';
        }
        if (x + 1 < grid.size() && grid[x + 1][y] == '1') {
            q.push({x + 1, y});
            grid[x + 1][y] = '0';
        }
        if (y > 0 && grid[x][y - 1] == '1') {
            q.push({x, y - 1});
            grid[x][y - 1] = '0';
        }
        if (y + 1 < grid[0].size() && grid[x][y + 1] == '1') {
            q.push({x, y + 1});
            grid[x][y + 1] = '0';
        }
    }
}

// if (grid.empty() || grid[0].empty()) {
//     return 0;
// }
int numIslands(vector<vector<char> > &grid) {
    int res = 0;    
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                res++;
                BFS_traverse(grid, i, j);
            }
        }
    }
    return res;
}

void test1() {
    vector<vector<char> > grid {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    int exp = 1;    // expected number of islands
    int res = numIslands(grid);
    cout << "res = " << res << endl;
    assert(res == exp);
}

void test2() {
    vector<vector<char> > grid {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    int exp = 3;    // expected number of islands
    int res = numIslands(grid);
    cout << "res = " << res << endl;
    assert(res == exp);
}
int main() {
    test1();
    test2();
}

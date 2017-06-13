// LC 51, solve N queens, Given an integer n, return all distinct solutions to the n-queens puzzle.
// Each solution contains a distinct board configuration of the n-queens' placement, 
// 'Q': queen, '.': an empty space
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <ctime>
using namespace std;
void print(vector<vector<string>> &v) {
    for (int i = 0; i < v.size(); i++) {
        printf("Solution %d:\n", i + 1);
        for (int j = 0; j < v[0].size(); j++) {
            printf("%s\n", v[i][j].c_str());
        }
        printf("\n");
    }
}
void print(int *arr, int len) {
    for (int i = 0; i < len; i++){
        printf(" %d", arr[i]);
    }
    printf("\n");
}
// DFS method
int solCnt = 0;
int sol[8] = {0};
void DFS(int row, int N) {
    vector<vector<string> > res;
    // check from given row, find available places
    for (int col = 0; col < N; col++) {
        bool isAvailable = true;
        // check previous rows, horizontal, vertical, diagnal
        for (int i = 0; i < row; i++) {
            if (col == sol[i] || col - sol[i] == row - i || col - sol[i] == i - row) {
                isAvailable = false;
                break;
            }
        }
        if (!isAvailable) continue;
        sol[row] = col; // reach last row, find one solution
        if (row == N - 1) {
            solCnt++;
            //print(sol, N);
        }
        else {
            DFS(row + 1, N);
        }
    }
}

// return true if the queen can be placed at cell [row][col], time: O(n)
bool isAvailable(vector<string> &grid, int row, int col) {
    int n = grid.size();
    // check if curr col is available
    for (int i = 0; i < row; i++) if (grid[i][col] == 'Q') return false;
    // check if curr 45 diagonal is available
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
       if (grid[i][j] == 'Q') return false;
    // check if curr 135 diagonal is available
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (grid[i][j] == 'Q') return false;
    return true;
}

// recursive method, check if a queen can be placed in O(n) time
void placeQueen_On(vector<vector<string>> &res, vector<string> &grid, int row, int n) {
    if (row == n) {
        res.push_back(grid); return;
    }
    // check all columns
    for (int col = 0; col < n; col++) {
        if (isAvailable(grid, row, col)) {
            grid[row][col] = 'Q';
            placeQueen_On(res, grid, row + 1, n);
            grid[row][col] = '.';
        }
    }
}
// check if a queen can be placed in O(n) time
vector<vector<string>> solveNQueensBF(int n) {
    vector<vector<string> > res;
    vector<string> grid(n, string(n, '.'));
    placeQueen_On(res, grid, 0, n);
    return res;
}

// note: vector<bool> is unpreferred here, as it needs more calculation, despite it is space efficient

// check if a queen can be placed in O(1) time
// need to use three auxiliary arrays (current col/main-diagnal/anti-diagonal is available)
void placeQueen(vector<vector<string>>& res, vector<string> &grid, vector<char> &cols, vector<char> &d45, vector<char> &d135, int row, const int n) {
    if (row == n) {
        res.push_back(grid); return;
    }
    // check next column
    for (int col = 0; col < n; col++) {
        // indices of 45 and 135 diagonal
        int d45_idx = row + col;
        int d135_idx = n - 1 - row + col;
        if (cols[col] && d45[d45_idx] && d135[d135_idx]) {
            // set queen and update flags
            cols[col] = d45[d45_idx] = d135[d135_idx] = 0;
            grid[row][col] = 'Q';
            placeQueen(res, grid, cols, d45, d135, row + 1, n);
            cols[col] = d45[d45_idx] = d135[d135_idx] = 1;
            grid[row][col] = '.';
        }
    }
}
vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > res;
    vector<string> grid(n, string(n, '.'));
    vector<char> cols(n, 1), d45(2 * n - 1, 1), d135(2 * n - 1, 1);
    placeQueen(res, grid, cols, d45, d135, 0, n);
    return res;
}

// pass three auxiliary arrays as a single one, no performance improvement observed..
void solveNQueens1Vec(vector<vector<string>> &res, vector<string>& grid, vector<char>& availables, int row) {
    const int n = grid.size();
    if (row == n) { res.push_back(grid); return;}
    for (int col = 0; col < n; col++) {
        int d45_idx = row + col + n;
        int d135_idx = 4 * n - 2 - row + col;   // n - 1 - row + col + (3 * n - 1);
        if (availables[col] && availables[d45_idx] && availables[d135_idx]) {
            availables[col] = availables[d45_idx] = availables[d135_idx] = 0;
            grid[row][col] = 'Q';
            solveNQueens1Vec(res, grid, availables, row + 1);
            grid[row][col] = '.';
            availables[col] = availables[d45_idx] = availables[d135_idx] = 1;
        }
    }
}

vector<vector<string>> solveNQueensWith1Vec(int n) {
    vector<vector<string>> res;
    vector<string> grid(n, string(n, '.'));
    // the first n flags are cols, the last 2 (2n - 1) items are d45, d135
    vector<char> availables(n + 4 * n - 2, 1);
    solveNQueens1Vec(res, grid, availables, 0);
    return res;
}

// profiling
void test_perf(vector<vector<string>> f(int), int n, string msg="") {
    clock_t start = clock();
    vector<vector<string>> res = (*f)(n);
    cout << msg;
    printf(": %.3f ms\n", 1000 * (double) (clock() - start) / CLOCKS_PER_SEC);
}
// cmp performance of solving n-queens (by execution time)
void cmp_perf(int n) {
    printf("Solve %d-queen:\n", n);
    test_perf(solveNQueens, n, "pass 3 char vectors");
    test_perf(solveNQueensWith1Vec, n, "pass 1 char vector");
    test_perf(solveNQueensBF, n, "brute force, check n cols/diagonals in O(n)");
    printf("\n");
}
int main() {
    // int n = 12;  // num of queens
    // DFS(0, n);
    //assert(solCnt == 92);

    vector<int> nums = {3,4,8};
    vector<int> exps = {0,2,92};    // num of distinct solutions
    for (int i = 0; i < nums.size(); i++) {
        vector<vector<string>> res = solveNQueens(nums[i]);
        assert(res.size() == exps[i]);    
        if (nums[i] == 4) print(res);   // display result for n=4
    }   

    cmp_perf(8);
    cmp_perf(12);
    return 0;
}
/*
Solution 1:
.Q..
...Q
Q...
..Q.

Solution 2:
..Q.
Q...
...Q
.Q..

Solve 8-queen:
pass 3 char vectors: 0.430 ms
pass 1 char vector: 0.412 ms
brute force, check n cols/diagonals in O(n): 2.083 ms

Solve 12-queen:
pass 3 char vectors: 147.097 ms
pass 1 char vector: 153.195 ms
brute force, check n cols/diagonals in O(n): 1153.921 ms
*/

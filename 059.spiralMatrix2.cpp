// LC 59, spiral matrix 2
// given integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.
// Given n = 3,
// You should return the following matrix:
// [[ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]]
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res;
    if (n <= 0) return res;
    // if (n == 1) {
    //     res = {{1}};
    //     return res;
    // }

    int k = 1;  // item value to be filled to matrix
    int total = n * n;
    int row_s = 0;
    int row_e = n - 1;
    int col_s = 0;
    int col_e = n - 1;
    res.resize(n, vector<int>(n));
    while (k <= total) {
        // right
        for (int i = col_s; i <= col_e; i++) res[row_s][i] = k++;
        row_s++;
        // down
        for (int i = row_s; i <= row_e; i++) res[i][col_e] = k++;
        col_e--;

        // left
        if (row_s > row_e) break;
        for (int i = col_e; i >= col_s; i--) res[row_e][i] = k++;
        row_e--;

        // up
        if (col_s > col_e) break;
        for (int i = row_e; i >= row_s; i--) res[i][col_s] = k++;
        col_s++;
    }
    return res;
}

int main() {
    vector<int> nums = {0,1,2,3};
    vector<vector<vector<int>>> exps = {
        {},// {{}}
        {{1}},
        {{1,2},{4,3}},
        {{1,2,3},{8,9,4},{7,6,5}}
    };
    for (int i = 0; i < nums.size(); i++) {
        vector<vector<int>> res = generateMatrix(nums[i]);
        printf("test %d\n", i + 1);
        assert(res == exps[i]);
    }
    return 0;
    return 0;
}
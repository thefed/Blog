// LC 54, spiral matrix (traversal)
// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
// Given the following matrix:
// [[ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]]
// You should return [1,2,3,6,9,8,7,4,5].
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// [[1 2 3 ]
//  [4 5 6]]
//
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    const int m = matrix.size();
    if (m == 0 || matrix[0].empty()) {
        // printf("empty\n");
        return res;
    }
    const int n = matrix[0].size();

    int k = 0;  // index of item in result array
    int row_s = 0;  // start/end index of row/col
    int row_e = m - 1;
    int col_s = 0;
    int col_e = n - 1;
    int total = m * n;
    res.assign(total, 0);
    while (k < total) {
        // right
        for (int i = col_s; i <= col_e; i++) res[k++] = matrix[row_s][i];
        row_s++;

        // down
        for (int i = row_s; i <= row_e; i++) res[k++] = matrix[i][col_e];
        col_e--;

        if (row_e < row_s) break;
        // left
        for (int i = col_e; i >= col_s; i--) res[k++] = matrix[row_e][i];
        row_e--;
    
        // up
        if (col_e < col_s) break;
        for (int i = row_e; i >= row_s; i--) res[k++] = matrix[i][col_s];
        col_s++;
    }
    return res;
}
int main() {
    vector<vector<vector<int>>> matrixes = {
        {{}},
        {{1}},
        {{1,2,3,4,5}},
        {{1},{2},{3},{4},{5}},
        {{1,2}, {3,4}},

        {{1,2,3}, {4,5,6}},
        {{1,2},{3,4},{5,6}},
        {{1,2,3},{4,5,6},{7,8,9}}
    };
    vector<vector<int>> exps = {
        {},
        {1},
        {1,2,3,4,5},
        {1,2,3,4,5},
        {1,2,4,3},

        {1,2,3,6,5,4},
        {1,2,4,6,5,3},
        {1,2,3,6,9,8,7,4,5}
    };
    for (int i = 0; i < matrixes.size(); i++) {
        vector<int> res = spiralOrder(matrixes[i]);
        printf("test %d\n", i + 1);
        assert(res == exps[i]);
    }
    return 0;
}

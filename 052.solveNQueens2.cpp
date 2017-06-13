// LC 52, return the total number of distinct N-queen solutions
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// backtrack utility function
void solveNQueens(int row, vector<char>& cols, vector<char>& mainDia, vector<char>& antiDia, int n, int& solCnt) {
    if (row == n) {
        solCnt++;
        return;
    }
    // if (row == 0) n /= 2;    // when n is even, in 1st pass, only need to try cols[0, n/2-1], symmetrical
    for (int col = 0; col < n; col++) {
        int mainId = col + (n - 1 - row);  // index of main diagonal direction
        int antiId = col + row;            // index of anti-diagonal direction
        if (cols[col] && mainDia[mainId] && antiDia[antiId]) {
            cols[col] = mainDia[mainId] = antiDia[antiId] = 0;  // mark as occupied
            solveNQueens(row + 1, cols, mainDia, antiDia, n, solCnt);
            cols[col] = mainDia[mainId] = antiDia[antiId] = 1;  // mark as free
        }
    }
}
// return num of N-queen solutions
int totalNQueens(int n) {
    int solCnt = 0; // num of solutions
    vector<char> cols(n, 1);    // 1: cols[i] is available; otherwise: 0
    vector<char> mainDia(2 * n - 1, 1); // main diagonal
    vector<char> antiDia(mainDia);      // anti-diagonal

    // solveNQueens(0, cols, mainDia, antiDia, n, solCnt);
    solveNQueens(0, cols, mainDia, antiDia, n, solCnt);
    return solCnt;
}
int main() {
    vector<int> nums = {3, 4, 8, 12};   // when n is even, 1/2 solutions are symmetrical
    vector<int> exps = {0, 2, 92, 14200};
    for (int i = 0; i < nums.size(); i++) {
        int res = totalNQueens(nums[i]);
        printf("test %d, res: %d\n", i + 1, res);
        assert(res == exps[i]);
    }
    return 0;
}

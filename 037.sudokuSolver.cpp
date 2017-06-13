// LC 37, fill empty cells ('.') with proper numbers to solve sudoku
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

// how to optimize time to O(n^k)?
// use three auxiliary arrays to check conflicts in O(1), instead of check n rows, n cols, n cells in the box
// use emptyPos array to get next empty cell position: O(1), instead of (n^2), two for loops
// 23 -> 12 (O(1) check conflicts) -> 3ms (O(1) get next empty cell)

// or even store a num candidates bitset for each cell, when one cell is updated, update the affected cells' bitsets
// e.g. given {5 3 x; x x 6; x 9 8}, x can be chosen from {1,2,4,7}
typedef vector<vector<char>> VVC;
// return true if current board can be solved by filling cells
bool solve(VVC& board, VVC& rows, VVC& cols, VVC& boxes, vector<int>& emptyPos, int k) {
    // scan board, to place num at empty cells
    // for (int i = 0; i < board.size(); i++) {
    //     for (int j = 0; j < board[0].size(); j++) {
    //         if (board[i][j] == '.') {   // fill it

    if (k == emptyPos.size()) return true;
    // fetch next empty cell position [i][j]
    int j = emptyPos[k] % 9;
    int i = emptyPos[k] / 9;
                // pick a num in [1, 9]
                char c;
                for (c = '1'; c <= '9'; c++) {
                    int num = c - '0' - 1;
                    int box_id = i / 3 * 3 + j / 3;
                    // if no conflicts when num 'c' is placed at [i][j]
                    // check conflicts, time: O(1)
                    if (!rows[i][num] && !cols[j][num] && !boxes[box_id][num]) {
                        board[i][j] = c;
                        rows[i][num] = cols[j][num] = boxes[box_id][num] = 1;
                        if (solve(board, rows, cols, boxes, emptyPos, k + 1)) {
                            return true;
                        }
                        // otherwise, rm this num, reset auxiliary array
                        else {
                            board[i][j] = '.';
                            rows[i][num] = cols[j][num] = boxes[box_id][num] = 0;
                        }
                    }
                }
                // if no valid num can be placed
                return false;
    //         }
    //     }
    // }
    // return true;
}

// time: O(n^k), n=9 (9 options for each cell), k: num of empty cells to fill
void solveSudoku(vector<vector<char>>& board) {
    // obtain hash table of used cells (1: used, 0: not used yet)
    const int n = board.size();
    if (n == 0 || board[0].empty()) return;

    int emptyCnt = 0;   // num of empty cells to be filled
    // rows[i][j] means num 'j+1' is used in rows[i], i in [0,8]
    vector<vector<char>> rows(n, vector<char>(n, 0));
    vector<vector<char>> cols(rows), boxes(rows);

    vector<int> emptyPos;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != '.') {
                emptyCnt++;
                int num = board[i][j] - '0' - 1;  // should be in [0,8]
                int box_id = i / 3 * 3 + j / 3;
                // unsolvable, exit
                if (rows[i][num] || cols[j][num] || boxes[box_id][num]) return;
                rows[i][num] = cols[j][num] = boxes[box_id][num] = 1;
            }
            else {
                emptyPos.push_back(i * n + j);
            }
        }
    }
    // printf("%d empty cells to be filled\n", emptyCnt); // 30
    // backtrack
    bool res = solve(board, rows, cols, boxes, emptyPos, 0);
    // printf("solvable ? %d\n", int(res));
}

// utility function to check sudoku solution
bool isValidSudoku(vector<vector<char>>& board) {
    const int n = board.size();
    // rows[i][j] means num 'j+1' is used in rows[i], i in [0,8]
    vector<vector<char>> rows(n, vector<char>(n, 0));
    vector<vector<char>> cols(rows), boxes(rows);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '0' - 1;  // should be in [0,8]
                if (num < 0 || num > 8) return false;
                int box_id = i / 3 * 3 + j / 3;
                if (rows[i][num] || cols[j][num] || boxes[box_id][num]) return false;
                // mark num 'c' as used
                rows[i][num] = cols[j][num] = boxes[box_id][num] = 1;
            }
        }
    }
    return true;
}

void setBoard(vector<vector<char>>& b, vector<string>& rows) {
    for (int i = 0; i < rows.size(); i++) {
        b[i].assign(rows[i].begin(), rows[i].end());
    }
}
void printBoard(vector<vector<char>>& b) {
    for (int i = 0; i < b.size(); i++) {
        if (i > 0 && i % 3 == 0) printf("\n");
        for (int j = 0; j < b[i].size(); j++) {
            if (j > 0 && j % 3 == 0) printf(" ");
            printf("%c ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main() {
    const int n = 9;    // n x n board
    vector<vector<char>> board(n, vector<char>(n));
    vector<string> rows = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79"
    };
    setBoard(board, rows);

    solveSudoku(board);
    printBoard(board);
    assert(isValidSudoku(board));
    return 0;
}

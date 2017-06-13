// LC 36, validate if given filled cells are valid sudoku

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
using namespace std;
// time: O(n^2), space: O(n^2)
bool isValidSudoku(vector<vector<char>>& board) {
    // char rows[81] = {0};     // index recalculation vs 2d array access
    char rows[9][9] = {{0}};  // rows[i][j] means num 'j+1' is used in rows[i], i in [0,8]
    char cols[9][9] = {{0}};
    char boxes[9][9] = {{0}};
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
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

    bool res = isValidSudoku(board);
    assert(res);

    board[8][8] = '5';
    res = isValidSudoku(board);
    assert(!res);
    return 0;
}

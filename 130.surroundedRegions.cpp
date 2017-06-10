// LC 130,
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;
class Solution {
    void traverse(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] != 'O') return;
        
        board[i][j] = '1';
        int m = board.size();
        int n = board[0].size();
        
        if (i > 0) traverse(board, i - 1, j);
        if (i < m - 1) traverse(board, i + 1, j);
        if (j > 0) traverse(board, i, j - 1);
        if (j < n - 1) traverse(board, i, j + 1);
    }
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
       
        int m = board.size();
        int n = board[0].size();
        if (m == 1 || n == 1) return;
        // mark all four neighors' connected components as '1'
        for (int i = 0; i < m; i++) {
            traverse(board, i, 0);
            traverse(board, i, n - 1);
        }
        
        for (int j = 1; j < n - 1; j++) {
            traverse(board, 0, j);
            traverse(board, m - 1, j);
        }
        
        // mark the remaining 'O' as 'X'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        
        // reset cells marked as '1' back to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }
};
void print(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
void setBoard(vector<vector<char>>& board, vector<string>& rows) {
    for (int i = 0; i < rows.size(); i++) {
        vector<char> row;
        for (int j = 0; j < rows[i].size(); j++) {
            // printf("%c ", rows[i][j]);
            row.push_back(rows[i][j]);
        }
        board.push_back(row);
    }
}
int main() {
    vector<vector<char>> board;
    vector<string> rows = {"XOXOXO","OXOXOX","XOXOXO","OXOXOX"};
    setBoard(board, rows);
    print(board);
    Solution sol;
    sol.solve(board);
    print(board);
    return 0;
}
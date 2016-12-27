// solve N queens
#include<iostream>
#include<vector>
#include<string>
#include<assert.h>
#include<time.h>
using namespace std;
void print2DVec(const vector<vector<string> > &v) {
    for (int i = 0; i < v.size(); i++) {
        printf("Solution %d:\n", i);
        for (int j = 0; j < v[0].size(); j++) {
            printf("%s\n", v[i][j].c_str());
        }
        printf("\n");
    }
}
void printArr(int *arr, int len) {
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
            //printArr(sol, N);
        }
        else {
            DFS(row + 1, N);
        }
    }
}
bool isAvailable(const vector<string> &grid, int row, int col) {
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
void solveNQueensBFHelper(vector<vector<string> > &res, vector<string> &grid, int row, int n) {
    if (row == n) {
        res.push_back(grid); return;
    }
    // check all columns
    for (int col = 0; col < n; col++) {
        if (isAvailable(grid, row, col)) {
            grid[row][col] = 'Q';
            solveNQueensBFHelper(res, grid, row + 1, n);
            grid[row][col] = '.';
        }
    }
}
vector<vector<string> > solveNQueensBF(int n) {
    vector<vector<string> > res;
    vector<string> grid(n, string(n, '.'));
    solveNQueensBFHelper(res, grid, 0, n);
    return res;
}

void solveNQueensDFS(vector<vector<string> > &res, vector<string> &grid, vector<char> &cols, vector<char> &d45, vector<char> &d135, int row, const int n) {
//void solveNQueensDFS(vector<vector<string> > &res, vector<string> &grid, vector<int> &cols, vector<int> &d45, vector<int> &d135, int row, const int n) {
//void solveNQueensDFS(vector<vector<string> > &res, vector<string> &grid, vector<bool> &cols, vector<bool> &d45, vector<bool> &d135, int row, const int n) {
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
            solveNQueensDFS(res, grid, cols, d45, d135, row + 1, n);
            cols[col] = d45[d45_idx] = d135[d135_idx] = 1;
            grid[row][col] = '.';
        }
    }
}
vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > res;
    vector<string> grid(n, string(n, '.'));
    //vector<int> cols(n, 1), d45(2 * n - 1, 1), d135(2 * n - 1, 1);
    vector<char> cols(n, 1), d45(2 * n - 1, 1), d135(2 * n - 1, 1);
    //vector<bool> cols(n, true), d45(2 * n - 1, true), d135(2 * n - 1, true);  // slower than vector<int>
    solveNQueensDFS(res, grid, cols, d45, d135, 0, n);
    return res;
}

//void solveNQueens1Vec(vector<vector<string> > &res, vector<string> &grid, vector<bool> &availables, int row) {
void solveNQueens1Vec(vector<vector<string> > &res, vector<string> &grid, vector<char> &availables, int row) {
    int n = grid.size();
    if (row == n) { res.push_back(grid); return;} 
    for (int col = 0; col < n; col++) {
        int d45_idx = row + col + n;
        //int d135_idx = n - 1 - row + col + (n + 2 * n - 1);
        int d135_idx = 4 * n - 2 - row + col;
        if (availables[col] && availables[d45_idx] && availables[d135_idx]) {
            availables[col] = availables[d45_idx] = availables[d135_idx] = 0;
            grid[row][col] = 'Q';
            solveNQueens1Vec(res, grid, availables, row + 1);
            grid[row][col] = '.';
            availables[col] = availables[d45_idx] = availables[d135_idx] = 1;
        }
    }
}

vector<vector<string> > solveNQueensWith1Vec(int n) {
    vector<vector<string> > res;
    vector<string> grid(n, string(n, '.'));
    // the first n flags are cols, the last 2 (2n - 1) items are d45, d135
    vector<char> availables(n + 4 * n - 2, 1);
    solveNQueens1Vec(res, grid, availables, 0);
    return res;
}
int main() {
    int N = 12;  // N queens
    DFS(0, N);
    //assert(solCnt == 92);
    // measure running time
    clock_t start = clock();  
    vector<vector<string> > res;
    res = solveNQueens(N);
    //assert(res.size() == 0);
    //assert(res.size() == 92);
    printf("flag method: %f ms\n", 1000 * (double) (clock() - start) / CLOCKS_PER_SEC);

    //start = clock();  
    //res = solveNQueensBF(N);
    ////assert(res.size() == 92);
    //printf("bf method: %f ms\n", 1000 * (double) (clock() - start) / CLOCKS_PER_SEC);

    start = clock();  
    res = solveNQueensWith1Vec(N);
    // assert(res.size() == 92);
    printf("1 vec method: %f ms\n", 1000 * (double) (clock() - start) / CLOCKS_PER_SEC);
    //print2DVec(res);
    return 0;
}

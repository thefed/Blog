// LC 79, word search
// given board:
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]
// find word "ABCCED" can be a path in board, can only go up/down/left/right
#include<iostream>
#include<vector>
#include<string>
#include<assert.h>
using namespace std;
bool isFound(vector<vector<char> >& b, int i, int j, string word) {
    // cout << b[i][j] << ", " << word[0] << endl;
    if (i >= 0 && j >= 0 && i < b.size() && j < b[0].size() && b[i][j] == word[0] && b[i][j] != 0) {
        if (word.size() == 1) {  // the last char
            return true;            
        }
        char temp = b[i][j];
        b[i][j] = 0;    // mark as visited
        // try neighbors
        string w = word.substr(1);
        if (isFound(b, i - 1, j, w) || isFound(b, i + 1, j, w) || isFound(b, i, j - 1, w) || isFound(b, i, j + 1, w)) {
            return true;
        }
        b[i][j] = temp; // restore board
    }
    return false;
}
bool exist(vector<vector<char> >& board, string word) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (isFound(board, i, j, word)) {
                return true;
            }
        }
    }
    return false;
}
void convert2DArrayToVec(const vector<string>& vec1, vector<vector<char> > &vec2) {
    for (int i = 0; i < vec1.size(); i++) {
        vector<char> v;
        for (int j = 0; j < vec1[i].size(); j++) {
            v.push_back(vec1[i][j]);
        }
        vec2.push_back(v);
    }
}
void printVec(const vector<vector<char> > &vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[j].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
void test() {
    string arr[] = {"ABCE","SFCS","ADEE"};
    vector<string> tempVec(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<vector<char> > board;
    convert2DArrayToVec(tempVec, board);
    string word = "ABCCED";
    bool actual = exist(board, word);
    assert(actual == true && "wrong output");
    cout << "SUCCESS\n";
}
int main() {
    test();
}

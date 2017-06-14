// LC 66, plus one
// Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
// You may assume the integer do not contain any leading zero, except the number 0 itself.
// The digits are stored such that the most significant digit is at the head of the list.

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] == 9) {
            digits[i] = 0;
        }
        else {
            digits[i]++;        // only need to modify that digit
            return digits;
        }
    }
    // otherwise
    vector<int> res = {1};
    res.insert(res.end(), digits.begin(), digits.end());
    return res;
}
int main() {
    vector<vector<int>> digitsList = {
        {0},
        {9},
        {1,9},
        {9,9},
        {1,9,9}
    };
    vector<vector<int>> exps = {
        {1},
        {1,0},
        {2,0},
        {1,0,0},
        {2,0,0}
    };
    for (int i = 0; i < exps.size(); i++) {
        vector<int> res = plusOne(digitsList[i]);
        assert(res == exps[i]);
    }
    return 0;
}
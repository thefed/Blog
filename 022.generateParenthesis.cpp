// LC 22, generate parenthesis
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// For example, given n = 3, a solution set is:
/*[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]*/
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

// backtracking
// add pairs

// left/right: num of left/right parenthesis added
void addPairs(vector<string>& res, string tmpRes, int left, int right, int n) {
    if (tmpRes.size() == 2 * n) {
        res.push_back(tmpRes);
        return;
    }

    if (left < n) {
        addPairs(res, tmpRes + "(", left + 1, right, n);
    }
    if (right < left) {
        addPairs(res, tmpRes + ")", left, right + 1, n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    if (n == 0) return res;
    if (n == 1) {
        res = {"()"};
        return res;
    }
    string tmpRes;
    addPairs(res, tmpRes, 0, 0, n);
    return res;
}
int main() {
    assert(generateParenthesis(0).empty());
    int n = 1;
    vector<string> res = generateParenthesis(n);
    vector<string> exp = {"()"};
    assert(res == exp);

    n = 2;
    res = generateParenthesis(n);
    exp = {"(())", "()()"};
    assert(res == exp);

    return 0;
}
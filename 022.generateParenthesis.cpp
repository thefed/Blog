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

// backtrack
// add pairs

// left/right: num of left/right parenthesis added
void addPairs(vector<string>& res, string tmpRes, int left, int right, int n) {
    if (tmpRes.size() == 2 * n) {
        res.push_back(tmpRes);
        return;
    }
    // note: the backtrack start condition
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
    vector<int> ns = {0,1,2};
    vector<vector<string>> exp = {
        {},
        {"()"},
        {"(())", "()()"}
    };
    for (int i = 0; i < ns.size(); i++) {
        int &n = ns[i];
        vector<string> res = generateParenthesis(n);
        assert(res == exp[i]);
    }
    return 0;
}

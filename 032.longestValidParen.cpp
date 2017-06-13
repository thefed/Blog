// LC 32 longest valid parentheses
// Given a string containing only '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
// follow-up: what if string contains "()" and "[]"? even "{}"?
// ()()([][)
// ()([)]
//   2345

#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <stack>
using namespace std;
void print(const vector<int> &v) {
	for (auto it : v) printf("%d ", it);
	printf("\n");
}

// dp method?

class Solution {
public:
    // method: stack, when s contains "[]{}", idea is the same
    // time: O(n), space: O(n), worst case: entire str: all '('
    int longestValidParentheses(string s) {
        if (s.size() <= 1) return 0;
        const int n = s.size();
        int longest = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(i);
            // found a match, rm open brace index
            else if (!st.empty() && s[st.top()] == '(') st.pop();   // matched
            // empty or top item does not match with ')'
            else st.push(i);
        }
        // finally check indices in stack
        // the valid substrs are between the indices in stack
        int right = n, left = 0;
        // if stack is empty, then entire stirng is valid
        while (!st.empty()) {
            left = st.top(); st.pop();
            longest = max(longest, right - left - 1);
            right = left;
        }
        longest = max(longest, right);
        return longest;
    }
};
void test(Solution &sol, const string s, int exp) {
	int len = sol.longestValidParentheses(s);
	printf("len = %d\n", len);
	assert(len == exp);
	printf("\n");
}
int main() {
	Solution sol;
    vector<string> strs = {"","(",")(","()",")()","(())())",")()())",")(((((()())()()))()(()))("};
    vector<int> exp     = {0,  0,   0,   2,   2,   6,       4,        22};
    for (int i = 0; i < strs.size(); i++) {
        test(sol, strs[i], exp[i]);
    }
	return 0;
}

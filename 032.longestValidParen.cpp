// LC 32 longest valid parentheses
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

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1) return 0;
        const int n = s.size();
        int longest = 0;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push(i);
            else {
                if (!st.empty()) {
                    if (s[st.top()] == '(') st.pop();   // matched
                    else st.push(i);    // record the index of unmatched ')' 
                }
                else st.push(i);        // record the index of unmatched ')' 
            }
        }
        // finally check stack
        if (st.empty()) return n;   // the whole string is longest
        else {
            // the mached substrs are between the indices in stack
            int right = n, left = 0;
            while (!st.empty()) {
                left = st.top(); st.pop();
                longest = max(longest, right - left - 1);
                right = left;
            }
            longest = max(longest, right);
        }
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
	test(sol, "", 0);
	test(sol, "(", 0);
	test(sol, ")(", 0);
	test(sol, "()", 2);
	test(sol, ")()", 2);
	test(sol, "(())())", 6);

	string s1 = ")()())";
	test(sol, s1, 4);

	string s2 = ")(((((()())()()))()(()))(";
	test(sol, s2, 22);
	return 0;
}
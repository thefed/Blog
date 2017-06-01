// LC 10, impl regular expression matching with support for '.' and '*'.
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true
// Hide Company Tags
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

// backtracking method
bool isMatch(string s, string p) {
    if (p.empty()) return s.empty();

    if (p[1] == '*') {
        // zero preceding element
        // more preceding elements
        return isMatch(s, p.substr(2)) || 
        (!s.empty() && (p[0] == s[0] || p[0] == '.') && isMatch(s.substr(1), p));
    }
    else {
        // check if p[0] == s[0] || '.''
        return !s.empty() && (p[0] == s[0] || p[0] == '.') &&
            isMatch(s.substr(1), p.substr(1));
    }
}

// dp method
bool isMatch_dp(string s, string p) {
    if (p.empty()) return s.empty();

    int m = s.size(), n = p.size();
    // f[i][j]: s[0..i-1] matches p[0..j-1]
    vector<vector<char>> f(m + 1, vector<char>(n, 0));
    // calc boundaries
    f[0][0] = 1;
    // for (int i = 1; i <= m; i++) {
    //     f[i][0] = 0;    // p empty, s non-empty
    // }
    for (int j = 1; j <= n; j++) {
        // s is empty, need p to be ".*" pattern to match
        f[0][j] = (j > 1 && p[j - 1] == '*' && f[0][j - 2]);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] != '*') {
                f[i][j] = f[i - 1][j - 1] && (p[j - 1] == '.' || p[j - 1] == s[i - 1]);
            }
            else {
                // zero preceding element: f[i][j-2]
                // more preceding elements: f[i-1][j]
                f[i][j] = f[i][j - 2] || 
                    (f[i - 1][j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1]));
            }
        }
    }
   
    return f[m][n];
}

int main() {
    assert(isMatch("", ""));
    assert(!isMatch("abc", ""));

    string s = "aa", p = "a";
    assert(!isMatch(s, p));

    p = "aa";
    assert(isMatch(s, p));

    s = "aaa";
    assert(!isMatch(s, p));

    p = "a*";
    assert(isMatch(s, p));

    s = "aa";
    p = ".*";
    assert(isMatch(s, p));

    s = "ab";
    assert(isMatch(s, p));

    s = "aab";
    p = "c*a*b";
    assert(isMatch(s, p));
    
    // dp method test
    assert(isMatch_dp(s, p));
    /*
    string p = "A";
    cout << (int)p[1] << endl;  // output 0
    */
    return 0;
}

// LC 46, impl wildcard matching with support for '.' and '*'.
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).
// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", "?*") → true
// isMatch("ab", "?*") → true
// isMatch("aab", "c*a*b") → false
// Hide Company Tags
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

// dp method
bool isMatch(string s, string p) {
    if (p.empty()) return s.empty();
    int m = s.size(), n = p.size();
    // f[i][j]: s[0..i-1] matches p[0..j-1]
    vector<vector<char>> f(m + 1, vector<char>(n + 1, 0));
    // calc boundary values
    f[0][0] = 1;
    // f[i][0] = 0 already
    for (int j = 1; j <= n; j++) {  // s is empty
        f[0][j] = (p[j - 1] == '*' && f[0][j - 1]);
    }

    // s=aaa, p=a*
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                // matches empty char
                // matched any sequence
                f[i][j] = f[i][j - 1] || 
                    f[i - 1][j];    // use "*" to match a char, keep j the same
            }
            else {
                f[i][j] = ((p[j-1] == s[i - 1] || p[j - 1] == '?') && f[i - 1][j - 1]);
            }
        }
    }

    return f[m][n];
}

// backtracking method

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
    p = "?*";
    assert(isMatch(s, p));

    s = "ab";
    assert(isMatch(s, p));

    s = "aab";
    p = "c*a*b";
    assert(!isMatch(s, p));

    s = "abbaaaabbbbbababbbbbbbbaaabaabbabaabbaaabbbbabbbbab";
    p = "a*aaba***b**a*a********b";
    assert(isMatch(s, p));    

    /*
    string p = "A";
    cout << (int)p[1] << endl;  // output 0
    */
    return 0;
}

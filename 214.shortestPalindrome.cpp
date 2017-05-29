// LC 214, Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. 
// Find and return the shortest palindrome you can find by performing this transformation.

// Given "aacecaaa", return "aaacecaaa".
// Given "abcd", return "dcbabcd".
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

bool isPalindrome(string& s) {
    if (s.size() <= 1) return true;
    int i = 0, j = s.size() - 1;
    while (i < j && s[i] == s[j]) { i++; j--; }
    return i >= j;
}
void print(vector<int>& v) {
    for (int i : v) printf("%d ", i);
    printf("\n");
}
vector<int> computeKMP(string s) {
    const int n = s.size();
    vector<int> lps(n, 0);
    int len = 0;    // length of previoud longest prefix
    for (int i = 1; i < n;) {
        if (s[i] == s[len]) lps[i++] = ++len;
        else if (len != 0) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}

// converted to: find a longest palindrome substr from [0]
// "aacecaaa" longest palindrome substr: "aacecaa", then add "a" to input
// trick: create a string: s + "#" + reversed_s
// s = "catacb" => "catacb#bcatac"
// get kmp table:   0000100012345
// get last index 5 => palindrom substr.length = 5!
// if the reversed part matches with the prefix, then that is the palindrome substr

string shortestPalindrome_kmp(string s) {
    string s_reversed = s;
    reverse(s_reversed.begin(), s_reversed.end());
    string str = s + "#" + s_reversed;
    vector<int> lps = computeKMP(str);
    int suffix_len = s.size() - lps.back();
    return s_reversed.substr(0, suffix_len) + s;
}

// brute force, time O(n^2)
string shortestPalindrome(string s) {
    if (s.size() <= 1) return s;
    if (isPalindrome(s)) return s;
    
    // find max length of palindrome start from  [0]
    int maxLen = 1, n = s.size();
    int i;
    for (i = 2; i <= n; i++) {
        string prefix = s.substr(0, i);
        if (isPalindrome(prefix)) {
            // cout << "isPalindrome: " << prefix << endl;
            maxLen = max(maxLen, i);
        }
    }
    if (maxLen == n) return s;
    // then [0..i-1] is palindrome
    i = maxLen;
    string postfix = s.substr(i);
    // cout << postfix << endl;
    reverse(postfix.begin(), postfix.end());
    return postfix + s;
}
int main() {
    string s = "aacecaaa";
    string exp = "aaacecaaa";
    string res = shortestPalindrome(s);
    assert(res == exp);

    s = "abcd";
    exp = "dcbabcd";
    res = shortestPalindrome(s);
    assert(res == exp);

    // how about "aaa....ab"? to avoid time limit exceeded?
    s = "aaaaaaab";
    exp = "b" + s;
    res = shortestPalindrome(s);
    assert(res == exp);

    assert(computeKMP("aaaab") == (vector<int> {0,1,2,3,0}));

    assert(shortestPalindrome_kmp(s) == exp);
    return 0;
}
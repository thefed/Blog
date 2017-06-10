// LC 28, impl substr, find needle in a haystack
// return the index of the first occurrence, -1 if not exist
#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;
// KMP, return longest proper prefix/suffix array of pattern 's'
// O(n)
vector<int> computeKMP(string& s) {
    const int n = s.size();
    vector<int> lps(n, 0);
    // lps[0] = 0;

    int len = 0;    // length of previous longest prefix suffix
    for (int i = 1; i < n; ) {
        if (s[i] == s[len]) lps[i++] = ++len;

        else if (len != 0) {    // not  match
            len = lps[len - 1]; // do not increment i here
        }
        else {
            lps[i] = 0;
            i++;
        }
    }
    return lps;
}

// in: a a a b, find "aaab"
//kmp: 0 1 2 1
vector<int> cmpKMP(string& s) {
    int n = s.size();
    vector<int> lps(n, 0);
    int len = 0;    // matched prefix length till [i]
    for (int i = 1; i < n; i++) {
        if (s[i] == s[len]) lps[i++] = ++len;
        else if (len > 0) len = lps[len - 1];
        else lps[i++] = 0;
    }
    return lps;
}
// KMP solution: O(m), m = haystack.size()
int strStr_kmp(string haystack, string needle) {
    const int m = haystack.size();
    const int n = needle.size();
    if (!n) return 0;

    vector<int> lps = computeKMP(needle);

    for (int i = 0, j = 0; i < m; ) {
        // printf("i = %d, j = %d\n", i, j);
        if (haystack[i] == needle[j]) { // match
            i++;
            j++;
        }
        if (j == n) return i - j;       // found index

        if (i < m && haystack[i] != needle[j]) {
            if (j > 0) j = lps[j - 1];  // skip previous sub-pattern
            else i++;   // does not match from needle[0]
        }
    }
    return -1;
}

// brute force, O(kn), k=m-n
int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    const int m = haystack.size(), n = needle.size();
    // brute force
    for (int i = 0; i < m - n + 1; i++) {
        // check if [i] is the correct index
        int j = 0;
        while (j < n && needle[j] == haystack[i + j]) j++;
        if (j == n) return i;
    }
    return -1;
}

// test kmp matched longest prefix length method
void test_kmp() {
    vector<string> strs = {"aaab", "ababc", "aabaaa"};
    vector<vector<int>> exps = {
        {0,1,2,0},
        {0,0,1,2,0},
        {0,1,0,1,2,2}
    };
    for (int i = 0; i < strs.size(); i++) {
        assert(computeKMP(strs[i]) == exps[i]);
    }
}
int main() {
    test_kmp();

    vector<string> hays = {"abc abcdabcde","aaaaaab"};
    vector<string> needles = {"abcde",     "aaab"};
    for (int i = 0; i < hays.size(); i++) {
        string &hay = hays[i];
        string &needle = needles[i];
        int exp = hay.find(needle); // call std::string::find
        int res = strStr(hay, needle);
        assert(res == exp);

        res = strStr_kmp(hay, needle);
        assert(res == exp);
    }
    return 0;
}

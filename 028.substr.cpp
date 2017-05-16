// LC 28, impl substr, find needle in a haystack
// return the index of the first occurrence, -1 if not exist
#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;
// KMP, return longest proper prefix/suffix array of pattern 's'
vector<int> computeKMP(string s) {
    const int n = s.size();
    vector<int> lps(n, 0);
    // lps[0] = 0;

    int len = 0;    // length of previous longest prefix suffix
    for (int i = 1; i < n; ) {
        if (s[i] == s[len]) lps[i++] = ++len;

        else if (len != 0) {   // not  match
                len = lps[len - 1];
                // do not increment i here
        }
        else {
            lps[i] = 0;
            i++;
        }   
    }
    return lps;
}

int strStr_kmp(string haystack, string needle) {
    const int m = haystack.size(), n = needle.size();
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
            else i++;
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
int main() {
    string hay = "abc abcdabcde";
    string needle = "abcde";
    int exp = hay.find(needle); // 8
    int res = strStr(hay, needle);
    assert(res == exp);

    hay = "aaaaaab";
    needle = "aaab";
    exp = hay.find(needle); // 8
    res = strStr(hay, needle);
    assert(res == exp);

    // test kmp computation
    assert(computeKMP(needle) == (vector<int> {0,1,2,0}));
    assert(computeKMP("ababc") == (vector<int> {0,0,1,2,0}));
    assert(computeKMP("aabaaa") == (vector<int> {0,1,0,1,2,2}));

    assert(strStr_kmp(hay, needle) == exp);
    return 0;
}

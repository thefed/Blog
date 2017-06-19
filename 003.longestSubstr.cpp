// LC 3, longest substring without repeating chars
/*
"abcabcbb" => "abc", return 3
"bbbbb" => "b", return 1.
"pwwkew", the answer is "wke", return 3, not sub sequence
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;
// hash table, O(n)
int lengthOfLongestSubstring(string s) {
    vector<char> positions(128, -1);    // positions[i]: last position of char i
    int start = -1; // last position of char[0]
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++) {
    	// i: end index
        if (positions[s[i]] > start) {	// exists, char appeared at position: v[s[i]]
            start = positions[s[i]];
        }
        positions[s[i]] = i;	// update new index
        maxLen = max(maxLen, i - start);
        // printf("s: %d, i: %d, max: %d\n", start, i, maxLen);
    }
    return maxLen;
}
int main() {
    vector<string> strs = {"abcabcbb", "abba", "bbbbb", "pwwkew"};
    vector<int> exp     = {3,2,1,3};    // => "abc", "ab", "b", "wke"
    int res;
    for (int i = 0; i < strs.size(); i++) {
        res = lengthOfLongestSubstring(strs[i]);
        printf("test %d, '%-8s', res: %d\n", i + 1, strs[i].c_str(), res);
        assert(res == exp[i]);
    }
    return 0;
}

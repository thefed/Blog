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
int lengthOfLongestSubstring(string s) {
	cout << s << endl;
    vector<char> v(128, -1);
    int start = -1, maxLen = 0;
    for (int i = 0; i < s.size(); i++) {
    	// i: end index
        if (v[s[i]] > start) {	// exists, char appeared at position: v[s[i]]
            start = v[s[i]];
        }
        v[s[i]] = i;	// update new index
        maxLen = max(maxLen, i - start);		
        // printf("s: %d, i: %d, max: %d\n", start, i, maxLen);
    }
    return maxLen;
}
int main() {
	string s1 = "abcabcbb";		// => "abc"
	int len1 = lengthOfLongestSubstring(s1);
	assert(len1 == 3);

	string s2 = "abba";
	int len2 = lengthOfLongestSubstring(s2);
	assert(len2 == 2);

	assert(lengthOfLongestSubstring("bbbbb") == 1);
	assert(lengthOfLongestSubstring("pwwkew") == 3);
}
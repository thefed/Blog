// LC 76, min window substring
// Given a string S and a string T, find the minimum window in S 
// which will contain all the characters in T in complexity O(n).

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".
// Note:
// If there is no such window in S that covers all characters in T, return the empty string "".

// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cassert>
using namespace std;
// ADOBECODEBANC
// A..B.C
//    B.....BA
//      C....A
//          B..C
string minWindow(string s, string t) {
	vector<int> map(128, 0);
	for (char c : t) map[c]++;	// count freq of t

	int begin = 0, end = 0;
	int counter = t.size();
	int len = INT_MAX;	// window size
	int old_start = 0;
	while (end < s.size()) {
		if (map[s[end++]]-- > 0) {
			// meet 2nd 'B', map['B'] = -1, found 'B', means 'B' can be replaced later
			// meet 2nd 'A', map['A'] = 0, cnt=0
			// map[s[end]]--;
			counter--;	// found a matched char
		}
		// end++;

		while (counter == 0) {	// all chars in t are matched
			if (end - begin < len) {	// update len
				len = end - begin;
				old_start = begin;	// 6-0, o_s=0
			}
			// increase begin till meeting an replacable char (freq==0)
			if (map[s[begin++]]++ == 0) {// invalidate start char
				// ADOBE
				// 1, map['A'] = 1
				//    1, map['B'] = 0
				counter++;		// rollback counter, to be matched
			}
			printf("begin: %d, end: %d, \n", begin, end);
		}
	}
	return len == INT_MAX ? "" : s.substr(old_start, len);
}
int main() {
	string s = "ADOBECODEBANC";
	string t = "ABC";
	string exp = "BANC";
	string res = minWindow(s, t);
	assert(res == exp);
	return 0;
}
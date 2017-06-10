// LC 5, return the longest palindrome string in input string s
// "babad" => "bab" or "aba"
// "cbbd" => "bb"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

// find repeated sequence from [i], expand it leftwards and rightwards, update max length
// time: O(n)
// abaacccaddaccadda
string longestPalindrome(string s) {
	if (s.size() <= 1) return s;
	const int len = s.size();
	int left = 0, right = 0;	// final left/right-most index of palindrome
	int i = 0;				    // start index
	while (i < len) {
		int start = i, end = i;	// current start/end index of palindrome
		i++;
		// search repeated chars sequence from [i]
		while (i < len && s[i] == s[start]) i++;
		end = i - 1;

		// found a sequence of repeated chars [start, end]
		// expand it towards left and right
		while (start >= 1 && end < len - 1 && s[start - 1] == s[end + 1]) {
			start--;
			end++;
		}

		// update final left/right index of palindrome
		if (end - start > right - left) {
			left = start;
			right = end;
		}
	}
	return s.substr(left, right - left + 1);
}
int main() {
    vector<string> strs = {"", "a", "babad", "cbbd", "dcbaaabcef"};
    vector<string> exps = {"", "a", "bab", "bb", "cbaaabc"};
    for (int i = 0; i < strs.size(); i++) {
        string res = longestPalindrome(strs[i]);
        printf("test %d, '%-10s', res: %s\n", i + 1, strs[i].c_str(), res.c_str());
        assert(res == exps[i]);
    }
	return 0;
}

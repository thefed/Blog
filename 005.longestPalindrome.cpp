// LC 5, return the longest palindrome string in input string s
// "babad" => "bab" or "aba"
// "cbbd" => "bb"
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
string longestPalindrome(string s) {
	if (s.size() <= 1) return s;
	const int len = s.size();
	int left = 0, right = 0;	// final left/right most index of palindrome
	int i = 0;				// start index
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
	assert(longestPalindrome("") == "");
	assert(longestPalindrome("a") == "a");

	string s1 = "babad";
	string res1 = longestPalindrome(s1);
	assert(res1 == "bab");

	string s2 = "cbbd";
	string res2 = longestPalindrome(s2);
	assert(res2 == "bb");

	assert(longestPalindrome("dcbaaabcef") == "cbaaabc");
	return 0;
}
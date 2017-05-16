// LC 151, reverse words
// Given s = "the sky is blue",
// return "blue is sky the".
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

void reverseWords(string& s) {
	// rm leading and trailing spaces
	int left = 0, right = s.size() - 1; 
	while (s[left] == ' ') left++;
	while (s[right] == ' ') right--;
	s = s.substr(left, right - left + 1);

	reverse(s.begin(), s.end());

	// reverse each word
	int start = 0;	// start index of a word
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			reverse(s.begin() + start, s.begin() + i);
			// mv "start" to next word's start position
			i++;
			// rm extra spaces if any (s.size() will decrease)
			while (s[i] == ' ') s.erase(s.begin() + i);
			start = i;
		}
	}
	// reverse last word
	reverse(s.begin() + start, s.end());
}

int main() {
	string s = "the sky is blue";
	string exp = "blue is sky the";
	cout << "original: " << s << endl;
	reverseWords(s);
	cout << "output: " << s << endl;
	assert(exp == s);
	return 0;
}
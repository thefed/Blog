// LC 65, check if a given string is vaild numeric value
// "0" true
// " 0.1 " true
// "abc" false
// "1  a" false
// "2e10" true
// It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

#include <iostream>
#include <string>
#include <cassert>
using namespace std;
bool isNumber(string s) {
	// rm leading and trailing spaces, trim()
	int left = 0, right = s.size() - 1;
	while (left <= right && s[left] == ' ') left++;
	while (right >= left && s[right] == ' ') right--;
	s = s.substr(left, right - left + 1);
	if (s.empty()) return false;

	bool hasNum = false;
	bool hasPoint = false;
	bool hasE = false;	// contains 'e' or not
	bool numAfterE = true;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i])) {
			hasNum = true;
			// set numAfterE = true; if modified by meeting 'e'
			numAfterE = true;
		}
		else if (s[i] == '.') {
			if (hasPoint || hasE) return false;
			hasPoint = true;
		}
		else if (s[i] == 'e') {
			if (hasE || !hasNum) return false;	// e must follow nums
			hasE = true;
			numAfterE = false;	// need extra nums to set it to true
		}
		else if (s[i] == '-' || s[i] == '+') {
			// should appear at position [0]
			if (i != 0 && s[i - 1] != 'e') return false;
		}
		else return false;
	}
	return hasNum && numAfterE;
}
int main() {
	assert(isNumber("0"));
	assert(isNumber(" 0 "));
	assert(isNumber(" 0.1 "));

	assert(!isNumber("   "));
	assert(!isNumber("abc"));
	assert(!isNumber("1  a"));
	assert(isNumber("2e10"));

	assert(isNumber("-1e-5"));
	assert(isNumber("-1e-5"));
	assert(isNumber("+1.5"));
	return 0;
}

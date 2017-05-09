// LC 6, zigzag conversion of a string, return a string (read line by line)
/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
// n=4, period=2*n
/*	"paypal is hiring"
p     i     n 	[0],[6],[12]
a   l s   i g   [1],[5], [7][11], [13]
y a   h r       [2],[4], [8],[10], [14?]
p     i         [3], [9], [15?]
*/

string convert(string s, int n) {
	if (n == 1) return s;
	string res;
	int period = 2 * n - 2;
	const int len = s.size();
	for (int row = 0; row < n; row++) {
		int i = 0;
		// the 1st and last rows contain only 1 item per row
		if (row == 0 || row == n - 1) {
			while (row + i * period < len) {
				res += s[row + i * period];
				i++;
			}
		}
		else {	// each peroid has 2 items per row
			while (row + i * period < len) {
				res += s[row + i * period];
				int next_id = period - row + i * period;
				if (next_id < len) {
					res += s[next_id];
				}
				else break;
				i++;
			}
		}
	}
	return res;
}

int main() {
	string s1 = "PAYPALISHIRING";
	assert(convert(s1, 1) == s1);	

	int nRows = 3;
	string res1 = convert(s1, nRows);
	assert(res1 == "PAHNAPLSIIGYIR");

	assert(convert(s1, 4) == "PINALSIGYAHRPI");
	return 0;
}
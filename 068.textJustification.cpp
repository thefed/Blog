// LC 68, text justification (formatting)
// Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
// For the last line of text, it should be left justified and no extra space is inserted between words.

// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.
// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;
void print(vector<string>& strs, string msg="") {
	cout << msg;
	for (string &s : strs) cout << s << endl;
	cout << endl;
}
vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<string> res;
	for (int i = 0; i < words.size(); ) {
		// suppose k words can fit in current line
		// find k, words[i..i+k-1] can fit in a line
		int k = 0;
		int len = 0;	// current line length
		for (; i + k < words.size() && len + words[i + k].size() + k <= maxWidth; k++) {
			len += words[i + k].size();
		}
		// if (i == 0) { 
		// 	assert(k == 3);
		// 	assert(len == 8);
		// }
		// else if (i == 3) {
		// 	assert(k == 3);
		// 	assert(len == 13);
		// }
		// else if (i == 6) {
		// 	assert(k == 1);
		// 	assert(len == 14);
		// }
		// when k=3, len=4+2+2+7+(k) = 18 > 16, adjust len=8
		// add words[0..2] to line string
		string line = words[i];
		for (int j = 1; j < k; j++) {
			if (i + k == words.size()) {
				// k words in last line,  add only 1 space btw
				line += " ";
			}
			else
			{
				int space_cnt_avg = (maxWidth - len) / (k - 1);
				// total spaces = 8, k-1=3, avg=2, => [3 3 2]
				int space_len = space_cnt_avg + (j <= ((maxWidth - len) % (k - 1)));
				line += string(space_len, ' ');
			}
			line += words[i + j];
		}
		// cout << "line size: " << line << line.size() << endl;

		line += string(maxWidth - line.size(), ' ');	// in case last line is shorter
		res.push_back(line);
		i += k;
	}
	return res;
}
int main() {
	vector<string> words = {"This","is","an","example","of","text","justification."};
	int maxWidth = 16;
	vector<string> res = fullJustify(words, maxWidth);
	vector<string> exp = {
		"This    is    an",
   		"example  of text",
   		"justification.  "
	};
	print(res, "split lines: \n");
	assert(res == exp);

	// test 2: more than 1 word in last line
	words = {"What","must","be", "shall", "be."};
	maxWidth = 12;
	exp = {
		"What must be",
		"shall be.   "
	};
	res = fullJustify(words, maxWidth);
	print(res, "split lines: \n");
	assert(res == exp);
	return 0;
}

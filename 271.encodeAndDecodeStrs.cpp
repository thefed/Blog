// LC 271, encode and decode strings
// encode a list of strings to a string
// decode a string back to a list of strings,
// cannot use class members/global variables, etc.
#include <string>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

// concatenate strings with lengths and special chars
string encode(vector<string>& strs) {
	string encoded; // encodes output string
    for (string &str : strs) {
        int len = str.size();
        encoded += to_string(len) + "_" + str;
    }
    return encoded;
}

// Decodes a single string to a list of strings.
vector<string> decode(string s) {
    vector<string> strs;
    int start = 0;
    while (start < s.size()) {
        int pos = s.find_first_of("_", start);
        int len = stoi(s.substr(start, pos - start));
        start = pos + 1;
        strs.push_back(s.substr(start, len));
        start += len;
    }
    return strs;
}

int main() {
	vector<string> strs = {"hello", "tr_y", "world"};
	string encoded = encode(strs);
	cout << encoded << endl;
	assert(encoded == "5_hello4_tr_y5_world");
	vector<string> res = decode(encoded);
	assert(res == strs);
	return 0;
}

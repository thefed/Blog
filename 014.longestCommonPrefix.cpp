// LC 14, longest common prefix of a list of strings
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    
    // find min-len str
    int min_id = 0, minLen = strs[0].size();
    for (int i = 1; i < strs.size(); i++) {
        if (strs[i].size() < minLen) {
            minLen = strs[i].size();
            min_id = i;
        }
    }
    string prefix = strs[min_id];

    for (int i = 0; i < strs.size(); i++) {
        while (strs[i].substr(0, prefix.size()) != prefix) {
            prefix = prefix.substr(0, prefix.size() - 1);
            if (prefix.empty()) return "";
        }
    }
    return prefix;
}
int main() {
	vector<string> strs = {"a", "b"};
	assert(longestCommonPrefix(strs) == "");

	strs = {"ca", "a"};
	assert(longestCommonPrefix(strs) == "");

	strs = {"abcd", "abc", "ab", "a"};
	assert(longestCommonPrefix(strs) == "a");

	strs = {"abcd", "abc", "ab", "a", "d"};
	assert(longestCommonPrefix(strs) == "");
	return 0;
}
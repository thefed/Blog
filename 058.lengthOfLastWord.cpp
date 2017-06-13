// LC 58, find the length of last word
// Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
// If the last word does not exist, return 0.
// Note: A word is defined as a character sequence consists of non-space characters only.
// Given s = "Hello World", return 5.
#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;
int lengthOfLastWord(string s) {
    int start = 0;
    int end = s.size() - 1;
    while (start <= end && s[end] == ' ') end--;
    int len = 0;    // length of last word
    while (start <= end && s[end] != ' ') {
        len++;
        end--;
    }
    return len;
    // int last_space = s.rfind(' ', end);
    // return (last_space == string::npos) ? end - start + 1 : end - last_space;
}
int main() {
    vector<string> strs = {"", "  ", "hi world", "  hi ", " hi  world  ", " hi  worxd", " hi exam  word "};
    vector<int> exps =     {0, 0, 5, 2, 5, 5, 4};
    for (int i = 0; i < strs.size(); i++) {
        int res = lengthOfLastWord(strs[i]);
        printf("test %d, res: %d\n", i + 1, res);
        assert(res == exps[i]);
    }
    return 0;
}
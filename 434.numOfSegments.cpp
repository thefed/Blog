// LC 434, find num of segments in string
// Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
// Please note that the string does not contain any non-printable characters.
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;
class Solution {
public:
// " hi "
// " hi this"
    int countSegments(string s) {
        // int start = 0;
        // int end = s.size() - 1;
        int cnt = 0;    // num of segments
        // while (start <= end && s[start] == ' ') start++;
        // while (start <= end && s[end] == ' ') end--;
        // for (int i = start; i <= end;) {
        //     while (i <= end && !isspace(s[i])) i++;
        //     cnt++;
        //     while (i <= end && isspace(s[i])) i++;
        // }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) cnt++;
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<string> strs = {"", " ", "hi", " hi ", " this is, a seq "};
    vector<int> exps =  {0,0,  1, 1, 4};
    for (int i = 0; i < strs.size(); i++) {
        int res = sol.countSegments(strs[i]);
        assert(res == exps[i]);
    }
    return 0;
}
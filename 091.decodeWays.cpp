// LC 91, num of decode ways of a string
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// "12" -> AB or L, num of decoding is 2
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

//"100", "103", "1132", "11302"
// method: dp
// f[i]: num of decodings for s.substr(0, i), (ends at position [i-1])
// f[i] = {
//      (f[i - 1] > 0 && s[i] != '0') ? f[i - 1]*1 +
//      (f[i - 2] > 0 && isValid(s[i-1],s[i])) ? f[i-1]*decode(s[i-1],s[i])
// }
// boundary case: f[0] = s[0] == '0' ? 0 : 1;

// return true if a valid letter can be decoded from c1 and c2
inline bool isValid(char c1, char c2) {
    return ((c1 == '2' && c2 <= '6') || c1 == '1');   // [20, 26], [10,19]
}

int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;

    // decodings[i]: num of decodings of substr with length i: [0,i-1]
    vector<int> decodings(s.size() + 1, 0);
    decodings[0] = 1;
    decodings[1] = 1;
    for (int i = 2; i <= s.size(); i++) {
        // curr char: s[i - 1]
        if (decodings[i - 1] > 0 && s[i - 1] != '0') {
            decodings[i] += decodings[i - 1];
        }
        if (decodings[i - 2] > 0 && isValid(s[i - 2], s[i - 1])) {
            decodings[i] += decodings[i - 2];
        }
    }
    return decodings[s.size()];
}
int main() {
    vector<string> strs = {"", "0","1","9", "12","20","30", "123", "1230"};
    vector<int> exp = {0,0, 1,1, 2,1,0, 3, 0};
    int res;
    for (int i = 0; i < strs.size(); i++) {
        res = numDecodings(strs[i]);
        printf("test %d: '%-5s', res: %d\n", i + 1, strs[i].c_str(), res);
        assert(res == exp[i]);
    }
    return 0;
}

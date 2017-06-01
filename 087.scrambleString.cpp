// LC 87, given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
// We say that "rgtae" is a scrambled string of "great".
// we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
/*
     great
    /     \
   gr     eat
   /\    /   \
  g r    e   at
            / \
            a t
swap(two children of any non-leaf node)
=> "rgeat" => "rgtae"
*/
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;
bool isScramble(string s1, string s2) {
    if (s1 == s2) return true;

    const int n = s1.size();
    // get chars freq distribution, cmp them
    vector<int> cnt1(26, 0), cnt2(26, 0);
    for (int i = 0; i < n; i++) {
        cnt1[s1[i] - 'a']++;
        cnt2[s2[i] - 'a']++;
    }
    if (cnt1 != cnt2) return false;

    // i: length of matched substring
    // two ways to pair, either euqal-length left/right
    // or s1's left substr and s2's right substr (as swaped)
    for (int i = 1; i < n; i++) {
        if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
            isScramble(s1.substr(i), s2.substr(i))) return true;
        if (isScramble(s1.substr(0, i), s2.substr(n - i)) && 
            isScramble(s1.substr(i), s2.substr(0, n - i))) return true;
    }
    return false;
}
int main() {
    string s1 = "great";
    string s2 = "rgeat";
    bool res;
    res = isScramble(s1, s2);
    cout << res << endl;
    assert(res);

    s2 = "rgtae";
    res = isScramble(s1, s2);
    cout << res << endl;
    assert(res);

    s1 = "abcd";
    s2 = "bdca";
    res = isScramble(s1, s2);
    cout << res << endl;
    assert(res);
    return 0;
}
// LC 49, group anagrams
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cassert>
#include <set>
using namespace std;
class Solution {
public:
    // "bcccaa" => "aabccc", sort chars
    string sortStr(string &s) {
        int count[26] = {0}, n = s.size();
        for (char c : s) count[c - 'a']++;
        int id = 0; // index of output string
        string res(n, 'a');
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < count[i]; j++)
                res[id++] += i; // i=0,set to 'a'; i=2, set to 'c'
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, multiset<string>> mp;
        for (string s : strs) {
            // string t = s;
            // sort(t.begin(), t.end());   // sort can be optimized!

            string t = sortStr(s);
            mp[t].insert(s);    // {key, set of strings}
        }
        for (auto m : mp) {
            vector<string> anagram(m.second.begin(), m.second.end());
            res.push_back(anagram);
        }
        return res;
    }
};
void print(const vector<vector<string>> &v) {
    for (auto &it: v) {
        for (string s : it) {
            cout << s << ", ";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = sol.groupAnagrams(strs);
    vector<vector<string>> exp = {
        {"ate", "eat","tea"},
        {"nat","tan"},
        {"bat"}
    };
    print(res);
    sort(res.begin(), res.end());
    sort(exp.begin(), exp.end());
    assert(res == exp);
    return 0;
}

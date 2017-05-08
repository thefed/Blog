#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<unordered_map<char, int>, int> mm;
        for (int i = 0; i < strs.size(); i++) {
            unordered_map<char, int> m;
            for (char c : strs[i]) m[c]++;
            auto it = mm.find(m);
            if (it == mm.end()) {   // not appeared
                mm[m] = res.size(); // 0,1..
                res.push_back(vector<string> ());
                res.back().push_back(strs[i]);
            }
            else {  // add it to result
                res[it->second].push_back(strs[i]);
            }
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
    vector<vector<string>> res = sol.groupAnagrams();
    vector<vector<string>> exp = {{"ate", "eat","tea"},
  {"nat","tan"},
  {"bat"}};
  print(res);
    assert(res == exp);
    return 0;
}
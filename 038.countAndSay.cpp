#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
string countAndSay(int n) {
    string res = "1";

    // iterate (n - 1) times
    for (int k = 0; k < n - 1; k++) {
        string s = res;
        res = "";
        if (s.size() == 1) {
            res = to_string(1) + s[0];
        }
        else {
            int i;
            for (i = 0; i < s.size() - 1; i++) {
                int cnt = 1;    // count the number of repetive chars
                while (i < s.size() - 1 && s[i] == s[i + 1]) {
                    i++;
                    cnt++;
                }
                // now either i == s.size() - 1 or s[i] != s[i + 1]
                // from i to end, all the same chars
                res += to_string(cnt) + s[i];
            }
            // check if last char equals the previous one
            if (s[s.size() - 1] != s[s.size() - 2]) {
                res += to_string(1) + s[s.size() - 1];
            }
        }
        cout << res << endl;
    }
    return res;
}
int main() {
    vector<int> nums = {1,2,3,4,5};
    vector<string> exps = {"1","11","21","1211","111221"};
    for (int i = 0; i < nums.size(); i++) {
        string res = countAndSay(nums[i]);
        assert(res == exps[i]);
    }
}

// LC 340, find length of longest substr with at most k distinct chars
// "eceba", k=2 => 3 ("ece")
// "ecebbba", k=2 => 4 ("ebbb")
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;
// slide window
int lengthOfLongestSubstringKDistinct(string s, int k){
    int cnt[256] = {0};
    int res = 0;    // returned length
    int charCnt = 0;    // num of distinct chars used
    int start = 0;  // start index of substr
    for (int i = 0; i < s.size(); i++) {
        if (cnt[s[i]] == 0) charCnt++;
        cnt[s[i]]++;

        if (charCnt > k) {
            // printf("start: %d->", start);
            // decrement cnt, increment start anyway
            while (--cnt[s[start++]] > 0);  // start 0->2, 2->3
            /* equivalent to the following...
            cnt[s[start]]--;
            while (cnt[s[start]] > 0) {
                start++;
                cnt[s[start]]--;
            }
            start++;
            */
            // printf("%d\n", start);
            charCnt--;
        }
        res = max(res, i - start + 1);
    }
    return res;
}
int main() {
    vector<string> strs = {"eceba", "ecebbba"};
    vector<int> exps = {3, 4};
    int k = 2;
    for (int i = 0; i < strs.size(); i++) {
        int res = lengthOfLongestSubstringKDistinct(strs[i], k);
        printf("test %d, res: %d\n", i + 1, res);
        assert(res == exps[i]);
    }
    return 0;
}

// LC 228, summary ranges
// Given a sorted integer array without duplicates, return the summary of its ranges.
// given [0,1,2,4,5,7], return ["0->2","4->5","7"].
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;
vector<string> summaryRanges(vector<int>& nums) {
    vector<string> res;
    if (nums.empty()) return res;
    string s = to_string(nums[0]);
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        int curr = i;
        while (i < n && nums[i] == nums[i - 1] + 1) i++;
        if (i > curr) { // can be merged
            s += "->";
            s += to_string(nums[i - 1]);
        }
        res.push_back(s);
        if (i < n) s = to_string(nums[i]);
        else return res;
    }
    res.push_back(s);
    return res;
}
int main() {
    vector<vector<int>> numsList = {
        {},
        {0},
        {0,1},
        {0,5},
        {0,1,2,4,5},
        {0,1,2,4,5,7},
    };
    vector<vector<string>> exps = {
        {},
        {"0"},
        {"0->1"},
        {"0","5"},
        {"0->2", "4->5"},
        {"0->2", "4->5", "7"},
    };
    for (int i = 0; i < numsList.size(); i++) {
        vector<string> res = summaryRanges(numsList[i]);
        printf("test %d\n", i + 1);
        assert(res == exps[i]);
    }
    return 0;
}


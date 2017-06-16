// LC 77, combinations
// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
// If n = 4 and k = 2, a solution is:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// k: num of items to be filled in tmpResult
void combineRemains(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmpRes, int k, int start) {
    // if (tmpRes.size() == k) {    // the same
    if (k == 0) {
        res.push_back(tmpRes);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        tmpRes.push_back(nums[i]);  // create tmpResult starting with nums[i]: 1, 2..
        // if [i] is start item in result, then next item should be chosen start from [i+1]
        combineRemains(nums, res, tmpRes, k - 1, i + 1);
        tmpRes.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> tmpRes;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) nums[i] = i + 1;
    combineRemains(nums, res, tmpRes, k, 0);
    return res;
}
int main() {
    int n = 4;
    int k = 2;
    vector<vector<int>> exp = {
        {1,2},{1,3},{1,4},{2,3},{2,4},{3,4}
    };
    vector<vector<int>> res = combine(n, k);
    assert(res == exp);
    return 0;
}
// LC 39, combination sum
// Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
// find all unique combinations in C where the candidate numbers sums to T.
// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// For example, given candidate set [2, 3, 6, 7] and target 7, 
// A solution set is: 
// [
//   [7],
//   [2, 2, 3]
// ]
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void getSumFrom(vector<int>& candidates, vector<vector<int>>& res, vector<int>& tmpRes, int target, int start) {
    if (target == 0) {
        res.push_back(tmpRes);
        return;
    }
    
    for (int i = start; i < candidates.size(); i++) {
        if (target >= candidates[i]) {
            tmpRes.push_back(candidates[i]);
            getSumFrom(candidates, res, tmpRes, target - candidates[i], i);
            tmpRes.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> tmpRes;
    
    getSumFrom(candidates, res, tmpRes, target, 0);
    
    return res;
}

int main() {
    vector<int> candidates = {2,3,6,7};
    vector<vector<int>> exp = {{2,2,3},{7}};
    int target = 7;
    vector<vector<int>> res = combinationSum(candidates, target);
    assert(res == exp);
    return 0;
}
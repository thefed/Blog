// LC 40, combination sum 2
// Given a collection of candidate numbers (C) and a target number (T), 
// find all unique combinations in C where the candidate numbers sums to T.

// Each number in C may only be used once in the combination.

// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
// A solution set is: 
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
void print(vector<int>& v) {
    for (int i : v) printf("%d ", i);
    printf("\n");
}
void getSumFrom(vector<int>& candidates, vector<vector<int>>& res, vector<int>& tmpRes, int target, int start) {
    // printf("target: %d, from [%d]\n", target, start);
    if (target == 0) {
        // printf("add: \n");
        // print(tmpRes);
        res.push_back(tmpRes);
        return;
    }
    
    for (int i = start; i < candidates.size() && target >= candidates[i]; i++) {
        if (i == start || candidates[i] != candidates[i - 1]) {
            tmpRes.push_back(candidates[i]);
            getSumFrom(candidates, res, tmpRes, target - candidates[i], i + 1);
            tmpRes.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> tmpRes;
    
    getSumFrom(candidates, res, tmpRes, target, 0);
    
    return res;
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> exp = {
        {1,1,6},
        {1,2,5},
        {1,7},
        {2,6}
    };
    int target = 8;
    vector<vector<int>> res = combinationSum2(candidates, target);
    assert(res == exp);
    return 0;
}

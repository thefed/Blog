// LC 70, climb stairs
// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Note: Given n will be a positive integer.
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
using namespace std;
int climbStairs(int n) {
    // if (n == 1) return 1;
    // if (n == 2) return 2;
    if (n <= 2) return n;
    // f[i] : from f[i - 1] or f[i - 2]
    
    int prev = 2;       // [i - 1]
    int prevPrev = 1;   // [i - 2]
    int curr;           // num of ways to get current step [i]
    for (int i = 3; i <= n; i++) {
        curr = prev + prevPrev;
        prevPrev = prev;
        prev = curr;
    }
    return curr;
}
int main() {
    vector<int> nums = {1,2,3,4,5};
    vector<int> exps = {1,2,3,5,8};
    for (int i = 0; i < nums.size(); i++) {
        int res = climbStairs(nums[i]);
        assert(res == exps[i]);
    }
    return 0;
}
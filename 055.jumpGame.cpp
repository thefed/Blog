// LC 55, can jump to final position
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// chech if can jump to last item, nums[i]: max steps that it can jump, nums[0] = 2, => [2]
// greedy
bool canJump(vector<int>& nums) {
    int max_reach_pos = 0;
    int i;
    for (i = 0; i < nums.size(); i++) {
        if (i > max_reach_pos) return false;
        max_reach_pos = max(max_reach_pos, i + nums[i]);
        if (max_reach_pos >= nums.size() - 1) return true;  // reach last item before scaning all
    }
    return i == nums.size();
}
int main() {
    vector<vector<int>> numsList = {
        {2,3,1,1,4},
        {3,2,1,0,4},
        {1,1,1,0,0},
        {1,1,1,1,0}
    };
    vector<char> exps = {1, 0, 0, 1};
    for (int i = 0; i < numsList.size(); i++) {
        bool res = canJump(numsList[i]);
        printf("test %d, res: %d\n", i + 1, int(res));
        assert(res == exps[i]);
    }
    return 0;
}

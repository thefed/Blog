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
        if (i > max_reach_pos) break;
        max_reach_pos = max(max_reach_pos, nums[i] + i);
    }
    return i == nums.size();
}
int main() {
    vector<int> nums1 = {2,3,1,1,4};
    assert(canJump(nums1));

    vector<int> nums2 = {3,2,1,0,4};
    assert(!canJump(nums2));
    
    const int N = 25000;
    vector<int> nums3(N, 1);
    nums3.push_back(0);
    nums3.push_back(0);
    assert(!canJump(nums3));
}

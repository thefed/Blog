#include<iostream>
#include<vector>
#include<deque>
#include<assert.h>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums,  int k) {
    vector<int> res;
    //if (nums.empty()) return res;
    //if (k == 1) return nums;
    deque<int> dq;
    for (int i = 0; i < nums.size(); i++) {
        // delete curr max value's index if invalid
        // e.g. i=3,k=3,i-k=0, if front=0, then nums[0] is not in curr windowm, need to be deleted 
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        // delete the indices the elements smaller than curr from the tail of deque
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        // once i >= 2, the max value is stored at the deque's front
        if (i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}
// initialize: deque:empty, res:empty
// +0 => 0
// -0 +1 => 1
// +2 => 1 2;       res +nums[1]
// +3 => 1 2 3;     res +nums[1]
// -1 -2 -3 => 4;   res +nums[4]
// +5 => 4 5;       res +nums[4]
// -4 -5 + 6 => 6;  res +nums[6]
// -6 + 7 => 7;     res +nums[7]
int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7}; 
    int k = 3;  // window size
    vector<int> res = maxSlidingWindow(nums, k);
    vector<int> exp = {3, 3, 5, 5, 6, 7};   // expected return value
    assert(res == exp);
    return 0;
}

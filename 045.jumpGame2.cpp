// LC 45, min steps needed to jump to last item
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
void print(const vector<int>& v) {
    for (int i: v) printf("%d ", i);
    printf("\n");
}
// return the minimum number of jumps to reach [n-1]
int jump(vector<int>& nums) {
    vector<int> v;
    int max_reach_pos = 0;

    int last_reach = 0;
    int i;
    int cnt = 0;

    int tmp = 0;
    for (i = 0; i < nums.size() ; i++) {
        if (i > max_reach_pos) return -1;
        // {5,6,0,4,2,4,1,0,0,4};
        // {2,3,1,2,4};
        if (nums[i] + i > max_reach_pos) {
            max_reach_pos = nums[i] + i;
            tmp = i;

            if (max_reach_pos >= nums.size()) {
                v.push_back(i);
                cnt++;
                printf("reach end in the middle: ");
                print(nums);
                print(v);
                return cnt; 
            }
        }

        if (i == last_reach) {
            last_reach = max_reach_pos;
            v.push_back(tmp);
            cnt++;
        }
    }
    printf("return: \n");
    print(v);
    return cnt;
}
int main() {
    vector<int> nums1 = {2,3,1,2,1};
    int exp = 3;
    int cnt = jump(nums1);
    // printf("cnt = %d\n", cnt);
    assert(cnt == exp);

    nums1 = {1,2,1,0,4};
    int res = jump(nums1);
    // printf("res: %d\n", res);
    assert(res == -1);

    nums1 = {5,6,0,4,2,4,1,0,0,4};
    res = jump(nums1);
    // printf("res: %d\n", res);
    assert(res == 3);

    nums1 = {0,0,0};
    res = jump(nums1);
    // printf("res: %d\n", res);
    assert(res == -1);

    nums1 = {1,1,1,2,0};
    res = jump(nums1);
    assert(res == 4);
    return 0;
}

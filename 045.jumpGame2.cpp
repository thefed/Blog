// LC 45, find the min steps needed to jump from start to last item (assume can reach end [n - 1])
// Given an array of non-negative integers, initial position: array[0]
// array[i]: represents your maximum jump length at that position.
// Given array A = [2,3,1,1,4], the min num of jumps to reach the last index is 2 ([0] -> [1] -> [4])

// follow-up: the path to reach end? [0] -> [1] -> [4]; what if reaching the end is not guaranteed?
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void print(vector<int>& v) {
    for (int i: v) printf("%d ", i);
    printf("\n");
}

// follow-up: return the path to reach end; return empty vector if it cannot reach end
vector<int> jump2(vector<int>& nums) {
    vector<int> path;      // store the visited indices (to get min steps)
    int i;
    int max_reach_pos = 0;
    int last_reach = 0;
    int prev_jump_pos = 0;  // previous jump position [i] when the max if updated (i + nums[i])
    for (i = 0; i < nums.size() - 1; i++) {
        if (i > max_reach_pos) return vector<int>();
        if (nums[i] + i > max_reach_pos) {
            max_reach_pos = nums[i] + i;
            prev_jump_pos = i;

            if (max_reach_pos >= nums.size() - 1) {
                path.push_back(i);
                path.push_back(nums.size() - 1);
                return path;
            }
        }

        if (i == last_reach) {
            last_reach = max_reach_pos;
            path.push_back(prev_jump_pos);
        }
    }
    if (max_reach_pos < nums.size() - 1) return vector<int>();
    path.push_back(nums.size() - 1);
    return path;
}

// greedy
// return the minimum number of jumps to reach [n-1]
int jump(vector<int>& nums) {
    int stepCnt = 0;        // num of steps to reach end
    int max_reach_pos = 0;  // max reachable position
    int prev_max_reach = 0; // previous position (where max_reach_pos is updated)
    int i;
    for (i = 0; i < nums.size() - 1; i++) {
        // if (i + nums[i] > max_reach_pos) {
        //     max_reach_pos = i + nums[i];
        //     if (max_reach_pos >= nums.size() - 1) {
        //         stepCnt++;
        //         return stepCnt;
        //     }
        // }
        max_reach_pos = max(max_reach_pos, i + nums[i]);
        if (i == prev_max_reach) {
            prev_max_reach = max_reach_pos;
            stepCnt++;
        }
    }
    return stepCnt;
}
void test_jump2() {
    vector<vector<int>> numsList = {
        {2,3,1,2,1},
        {1,2,1,0,4},
        {1,2,1,1,4},
        {5,6,0,4,2,4,1,0,0,4},
        {0,0,0},
        {1,1,2,1,0},
        {0},
        {1},
        {1,2,0,0,1}
    };
    vector<vector<int>> exps = {
        {0,1,4},
        {},
        {0,1,3,4},
        {0,5,9},
        {},
        {0,1,2,4},
        {0},
        {0},
        {}
    };
    for (int i = 0; i < numsList.size(); i++) {
        vector<int> res = jump2(numsList[i]);
        printf("f, test %d, res: ", i + 1);
        print(res);
        assert(res == exps[i]);
    }
}
int main() {
    vector<vector<int>> numsList = {
        {2,3,1,2,1},
        {1,2,1,1,4},
        {5,6,0,4,2,4,1,0,0,4},
        {1,1,1,2,0},
        {0},
        {1}
    };
    vector<int> exps = {2, 3, 2, 4, 0, 0};
    for (int i = 0; i < numsList.size(); i++) {
        int res = jump(numsList[i]);
        printf("test %d, res: %d\n", i + 1, res);
        assert(res == exps[i]);
    }

    test_jump2();
    return 0;
}

// 442. Find All Duplicates in an Array
/*
Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
Find all the elements that appear twice in this array.
require: O(n) time, O(1) space
Example:
Input:
[4,3,2,7,8,2,3,1]
Output:
[2,3]
*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// in   4 3  2  7  8 2   3  1
// mark        -7    
//           -2
//        -3
//                      -3
//                         -1
//        -3: fliped, add {2}
//        -2: fliped, add {3}
// flip the sign of nums[nums[i] - 1]
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0) {
            res.push_back(abs(index + 1));
        }
        nums[index] = -nums[index];
    }
    return res;
}
void print(vector<int>& v, string msg="") {
    cout << msg;
    for (int i : v) printf("%d ", i);
    printf("\n");
}
int main() {
    vector<int> nums = {4,3,2,7,3,2,8,1};
    vector<int> res = findDuplicates(nums);
    vector<int> exp = {2,3};
    print(res);
    print
    return 0;
}
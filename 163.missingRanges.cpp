// LC 163, find missing ranges
// Given a sorted integer array where the range of elements are in the inclusive range [lowerer, upper], return its missing ranges.
#include <iostream>
#include <vector>
#include <cassert>
#include <string>
using namespace std;
// utility function to build range string
string getRange(int a, int b) {
    return a == b ? to_string(a) : to_string(a) + "->" + to_string(b);
}

// what if "next++" and "nums[i] + 1" overflower?
// replace type of "next" to long
// e.g. {INT_MAX}, lower=0,upper=INT_MAX

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> res;

    // int next = lower; // next expected integer
    long next = lower;
    for (int i = 0; i < nums.size(); i++) {
        // not within the range
        // if (nums[i] < next) continue;

        if (nums[i] == next) {
            next++; // next expected integer
        }
        else if (nums[i] > next) {  // > next, found a missing range
            res.push_back(getRange(next, nums[i] - 1));
            next = (long)nums[i] + 1;
        }
    }

    if (next <= upper) res.push_back(getRange(next, upper));

    return res;
}
void print(vector<string>& v) {
    for (string& s : v) cout << s << " ";
    cout << endl;
}
int main() {
    vector<int> nums = {-1,0,1,3,50,75};
    int lower = 0;
    int upper = 99;
    vector<string> res = findMissingRanges(nums, lower, upper);
    vector<string> exp = {"2","4->49","51->74","76->99"};
    print(res);
    assert(res == exp);
    return 0;
}

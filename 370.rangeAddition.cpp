// LC 370, range addition
// Assume you have an array of length n initialized with all 0's and are given k update operations.
// Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.
// Return the modified array after all k operations were executed.
// e.g. length 5: [0 0 0 0 0 ]
// updates = {
    // {1,3,2},
    // {2,4,3},
    // {0,2,-2}
// }
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// in: [0 0 0 0 0 ] + {1,3, 2}
// res:[0 2 0 0 -2] 
// sum:[0 2 2 2 0]
// + {2,4,3}
// res:[0 2 3 0 -2]
// sum:[0 2 5 5 3]
// + {0,2,-2}
//res:[-2 2 3 2 -2]
//sum:[-2 0 3 5 3]

// only record record the affected start index and end index's next position
// then calc accumulated sum, so the increments will be propogated till 'end'
// last element ([end+1]) should discard the increment, thus minus increment at [end+1] (if valid index)
// time: O(m + n), m: length, n: updates.size
vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> res(length, 0);
    for (auto& update : updates) {
        int &start = update[0];
        int &end = update[1];
        int &increment = update[2];
        res[start] += increment;
        if (end + 1 < length) {
            res[end + 1] -= increment;
        }
    }

    for (int i = 1; i < length; i++) {
        res[i] += res[i - 1];
    }
    return res;
}
// 
int main() {
    vector<vector<int>> updates = {
        {1,3,2},    // => {0,2,2,2,0}
        {2,4,3},
        {0,2,-2}
    };
    int length = 5;
    vector<int> exp = {-2,0,3,5,3};
    vector<int> res = getModifiedArray(length, updates);
    assert(res == exp);
    return 0;
}
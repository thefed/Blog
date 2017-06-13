// LC 56, merge intervals
// Given a collection of intervals, merge all overlapping intervals.
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
struct Interval {
    int start, end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool operator==(const Interval& i1, const Interval& i2) {
    return i1.start == i2.start && i1.end == i2.end;
}

vector<Interval> merge(vector<Interval>& intervals) {
    vector<Interval> res;
    if (intervals.empty()) return res;
    auto comp = [](const Interval &i1, const Interval &i2){ 
        return i1.start < i2.start; 
    };
    // sort intervals by start val
    sort(intervals.begin(), intervals.end(), comp);

    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
        Interval &prevInt = res.back();
        // mergable
        if (intervals[i].start <= prevInt.end) {
            prevInt.end = max(prevInt.end, intervals[i].end);
        }
        // otherwise, create a new interval
        else {
            res.push_back(intervals[i]);
        }
    }
    return res;
}
int main() {
    vector<Interval> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<Interval> res = merge(intervals);
    vector<Interval> exp = {{1,6}, {8,10}, {15,18}};
    assert(res == exp);
    return 0;
}
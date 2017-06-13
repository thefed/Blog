// LC 57, insert interval
// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
// You may assume that the intervals were initially sorted according to their start times.
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
struct Interval{
    int start, end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool operator==(const Interval& i1, const Interval& i2) {
    return i1.start == i2.start && i1.end == i2.end;
}
// {{1,3},{6,9}, +{2,5}
// linear search, O(n)
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> res;
    int &s = newInterval.start;
    int &e = newInterval.end;

    // find the last interval whose end < new.start
    int i = 0;
    const int n = intervals.size();
    while (i < n && intervals[i].end < s) res.push_back(intervals[i++]);

    // {1,3} + {2,5} or {0,5} or {2,50}
    // create new merged interval, merge all intervals whose start <= e
    Interval mergedInt = {s, e};
    int &min_s = mergedInt.start;
    int &max_e = mergedInt.end;
    while (i < n && intervals[i].start <= e) {
        min_s = min(min_s, intervals[i].start);
        max_e = max(max_e, intervals[i].end);
        i++;
    }
    res.push_back(mergedInt);

    // add remaining intervals if any
    if (i < n) res.insert(res.end(), intervals.begin() + i, intervals.end());
    return res;
}
int main() {
    vector<vector<Interval>> intervalsList = {
        {{1,3},{6,9}},
        {{1,2},{3,5},{6,7},{8,10},{12,16}}
    };
    vector<Interval> newIntervals = {{2,5}, {4,9}}; // inserted intervals
    vector<vector<Interval>> exps = {
        {{1,5}, {6,9}},
        {{1,2},{3,10},{12,16}}
    };
    for (int i = 0; i < intervalsList.size(); i++) {
        vector<Interval> res = insert(intervalsList[i], newIntervals[i]);
        printf("test %d\n", i + 1);
        assert(res == exps[i]);
    }
    return 0;
}
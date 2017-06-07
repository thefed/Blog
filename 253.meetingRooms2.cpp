// LC 253, Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

// Given [[0, 30],[5, 10],[15, 20]],
// return 2.
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <set>
using namespace std;

struct Interval {
    int start, end;
    Interval(int s, int e) : start(s), end(e) {}
};
// time: sort O(nlogn), scan intervals: O(n)
int minMeetingRooms(vector<Interval>& intervals) {
    if (intervals.empty()) return 0;
    auto cmp = [] (const Interval& i1, const Interval& i2) {return i1.start < i2.start; };
    sort(intervals.begin(), intervals.end(), cmp);

    const int n = intervals.size();
    int minRooms = 1;   // min num of rooms needed, 
    int i = 1;          // index of start/end time of meeting
    
    set<int> ends = {intervals[0].end}; // {key: [i].end}
    // a room can be reused if intervals[i].start >= any of the stored ongoing end times
    for (; i < n; i++) {
        // find the first item <= [i].end, {10,20,30}
        if (ends.empty() || intervals[i].start < *(ends.begin())) {
            ends.insert(intervals[i].end);    // need a new rm, and it ends at [i].end time
            minRooms++;
        }
        else {  // can reuse a rm
            ends.erase(ends.begin());
            ends.insert(intervals[i].end);
        }
    }
    return minRooms;
}
int main() {
    vector<Interval> intervals = {{0,30},{5,10},{15,20}};
    int res = minMeetingRooms(intervals);
    printf("res = %d\n", res);
    assert(res == 2);

    intervals = {{0,30},{5,10},{9,20},{11,25},{21,25}};
    // room 1: {0,30}; rm 2: {5,10},{11,25}; rm 3: {9,20},{21,25}
    res = minMeetingRooms(intervals);
    printf("res = %d\n", res);
    assert(res == 3);
    return 0;
}

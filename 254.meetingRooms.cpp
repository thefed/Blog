// LC 254, find if intervals overlap
// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
// {{1,3}, {5,7}, {2,4}, {6,8}},
// return false, as {1,3} and {2,4} overlap
// {{1,3}, {7,9}, {4,6}, {10,13}}, true, no overlap
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
struct Interval {
    int start, end;
    Interval(int s, int e) : start(s), end(e) {}
};

// brute force: O(n^2), cmp intervals[i] with its successors
// time: O(nlogn) sort, O(n) cmp
bool canAttendMeetings(vector<Interval>& intervals) {
    auto cmp = [] (const Interval& i1, const Interval& i2) {
        return i1.start < i2.start;
    };
    sort(intervals.begin(), intervals.end(), cmp);
    
    // cmp [i]'s start with its previous one's end time
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].start < intervals[i - 1].end) return false;
    }
    return true;
}
int main() {
    vector<Interval> intervals = {{1,3}, {5,7}, {2,4}, {6,8}};
    assert(!canAttendMeetings(intervals));

    intervals = {{1,3}, {7,9}, {4,6}, {10,13}};
    assert(canAttendMeetings(intervals));
    return 0;
}
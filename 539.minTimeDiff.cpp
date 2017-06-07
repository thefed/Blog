// LC 539, find min time different (in terms of minutes)
// Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
// {"23:59", "00:00"} => 1
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;
// return the diff in terms of minutes of start and end time, end > start
int getDiff(const string& start, const string& end) {
    int hour = (end[0] - start[0])*10 + (end[1] - start[1]);
    int minute = (end[3] - start[3])*10 + (end[4] - start[4]);
    return 60 * hour + minute;
}
int findMinDifference(vector<string>& timePoints) {
    sort(timePoints.begin(), timePoints.end());
    
    const int n = timePoints.size();
    // cmp each pair from {[i],[i+1]}, 0 <= i <= n-2, and {[0],[n-1]}
    int minDiff = getDiff(timePoints[n - 1], "24:00") + getDiff("00:00", timePoints[0]);
    
    for (int i = 0; i < n - 1; i++) {
        int diff = getDiff(timePoints[i], timePoints[i + 1]);
        minDiff = min(minDiff, diff);
    }
    return minDiff;
}
int main() {
    vector<string> times = {"23:59", "00:00"};
    int res = findMinDifference(times);
    printf("res = %d\n", res);
    assert(res == 1);

    times = {"05:01", "10:01", "13:02", "01:01", "23:01"};
    res = findMinDifference(times);
    printf("res = %d\n", res);
    assert(res == 120);    // 2 hours
    return 0;
}
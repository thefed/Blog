// LC 149, get the max num of points on a line
// given points on a 2-D space
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
struct Point{
	int x, y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
// get largest common divisor, if a or b == 0, return the other
int getLCD(int a, int b) {
	if (a == 0) return b;	// 24, 9
	else return getLCD(b % a, a);
}

// use map<int, map<int,int>> to store {a, {b, cnt}}, where slope = b/a
int maxPoints(vector<Point>& points) {
    int res = 0;    // max num of points in a line
    unordered_map<int, unordered_map<int, int>> map;
    for (int i = 0; i < points.size(); i++) {
    	// reset map
    	map.clear();

        int duplicatePoint = 1;     // mark curr point as 1 
        // find local max num of points in the same line
        int localMax = 0;

        for (int j = i + 1; j < points.size(); j++) {
        	int x = points[i].x - points[j].x;
        	int y = points[i].y - points[j].y;
        	if (x == 0 && y == 0) {
                duplicatePoint++; 
            }
            else {
            	int divisor = getLCD(x, y);
            	if (divisor != 0) {
            		x /= divisor;
            		y /= divisor;
            	}

            	// e.g. k=1/3
            	if (map.find(x) != map.end()) {
            		if (map[x].find(y) != map[x].end()) {
            			map[x][y]++;
            		}
            		else {	// e.g. k=5/3  is not in
            			map[x][y] = 1;
            		}
            	}
            	else {	// add {a, {b, cnt}} to it
            		// unordered_map<int, int> m = {y, 1};
            		map[x][y] = 1;
            	}

            	// update local max
            	localMax = max(localMax, map[x][y]);
            }
        }
        
        // update global max result
        res = max(res, localMax + duplicatePoint);
    }
    return res;
}

// use map<double,int> looses precision, when slopes are close
// this solution is incorrect
int maxPoints_dbl(vector<Point>& points) {
    int res = 0;    // max num of points in a line
    for (int i = 0; i < points.size(); i++) {
        int duplicatePoint = 1;     // mark curr point as 1 
        unordered_map<double, int> map;
        for (int j = i + 1; j < points.size(); j++) {
        	int x = points[i].x - points[j].x;
        	int y = points[i].y - points[j].y;
        	if (x == 0 && y == 0) {
                duplicatePoint++;                    
            }
            else if (x == 0) {
                map[INT_MAX]++;
            }
            else {
                map[(points[i].y - points[j].y) / double(points[i].x - points[j].x)]++;
            }
        }
        
        // find local max num of points in the same line
        int localMax = 0;
        for (auto it = map.begin(); it != map.end(); it++) localMax = max(localMax, it->second);
        localMax += duplicatePoint;
        
        // update global result
        res = max(res, localMax);
    }
    return res;
}
int main() {
	int d = getLCD(24, 9);
	assert(d == 3);

	vector<Point> points = {{0,0}, {1,0}, {0,1}};
	int exp = 2;
	int res = maxPoints(points);
	assert(res == exp);

	// double type slope value does not work... loose precision
	// need to store slope as b/a (fraction)
	points = {{0,0},{94911151,94911150},{94911152,94911151}};
    res = maxPoints(points);
    assert(res == exp);

	points = {{0,0},{-1,-1},{2,2}};
	res = maxPoints(points);
    assert(res == 3);
	return 0;
}

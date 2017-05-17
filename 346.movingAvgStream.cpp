// LC 346, return mv average from stream of window size k
// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

// For example,
// MovingAverage m = new MovingAverage(3);
// m.next(1) = 1
// m.next(10) = (1 + 10) / 2
// m.next(3) = (1 + 10 + 3) / 3
// m.next(5) = (10 + 3 + 5) / 3

#include <iostream>
#include <queue>
#include <cassert>
using namespace std;
class MovingAverage {
private:
	int m_size;
	int sum;
	queue<int> q;	// or circular array
	vector<int> w;	// window size=k
	int cnt;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : m_size(size), sum(0) {
        cnt = 0;
    }
    
    double next2(int val) {
        if (q.size() < m_size) {
        	q.push(val);
        	sum += val;
        	return double(sum) / q.size();
        }
        else { // substract front, rm it, add new
        	sum = sum - q.front() + val;
        	q.pop();
        	q.push(val);
        	return double(sum) / m_size;
        }
    }

    double next(int val) {
    	if (w.size() < m_size) {
    		cnt++;	// next item's index
    		w.push_back(val);
    		sum += val;
    		return double(sum) / w.size();
    	}
    	else {
    		int front = cnt % m_size;	// front index
    		sum = sum - w[front] + val;
    		w[front] = val;
    		cnt++;
    		return double(sum) / m_size;
    	}
    }
};
int main() {
	MovingAverage m(3);
	assert(m.next(1) == 1.0);
	assert(m.next(10) == double(1+10)/2);
	assert(m.next(3) == double(1+10+3)/3);
	assert(m.next(5) == double(10+3+5)/3);
	return 0;
}
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<assert.h>
#include<limits.h>
using namespace std;
class MinStack {
private:
    vector<int> st;
    map<int, int> mymap;
    int minVal;
public:
    /** initialize your data structure here. */
    MinStack() {
    	minVal = INT_MAX;
    }
    
    void push(int x) {
        st.push_back(x);
        mymap[x]++;
        minVal = min(minVal, x);
    }
    
    void pop() {
        mymap.erase(st.back());   // erase by key
        minVal = mymap.begin()->first;
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minVal;
    }
};
void test() {
	MinStack minStack;// = new MinStack();
	minStack.push(0);
	minStack.push(1);
	minStack.push(1);
	minStack.pop();
	int actual = minStack.getMin();
	assert(actual == 0 && "wrong output");

	minStack.push(-1);
	actual = minStack.getMin();
	assert(actual == -1 && "wrong output");	
}
int main() {
	test();
}
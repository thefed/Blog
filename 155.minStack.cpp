// LC 155, impl min stack, 
// require: push/pop/top/getMin() all O(1)
#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // min
#include <cassert>
#include <climits>
#include <stack>
using namespace std;
// method 1: use a vector and a map
class MinStack {
    private:
        vector<int> st;
        map<int, int> mymap;    // stores all elements as keys in ASC order and their frequencies as values
        int minVal;
    public:
        /** initialize your data structure here. */
        MinStack() {
            minVal = INT_MAX;
        }

        void push(int x) {
            st.push_back(x);
            mymap[x]++;
            minVal = min(minVal, x);    // update minVal if needed
        }

        void pop() {
            mymap[st.back()]--;
            if (mymap[st.back()] == 0) {
                mymap.erase(st.back());   // erase by key, log(N), not O(1) time!
            }
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

// method 2: use only a stack
class MinStack2 {
private: 
    int minVal;
    stack<int> st;
public:
    MinStack2() : minVal(INT_MAX) {}

    // when x <= min, need to update min
    // trick: push an extra "min" before pushing x
    // such that when popping x (x == min), we can fetch old min value from top
    void push(int x) {
        if (x <= minVal) {
            st.push(minVal);
            minVal = x;
        }
        st.push(x);
    }

    void pop() {
        int top = st.top();
        st.pop();
        if (top == minVal) {
            minVal = st.top();  // min val is popped, need to fetch new min val
            st.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minVal;
    }
};
int main() {
    MinStack minStack;
    minStack.push(0);
    minStack.push(0);
    minStack.push(1);
    minStack.push(1);
    minStack.pop();
    int actual = minStack.getMin();
    assert(actual == 0);
    
    // delete 1, 0, now stack: 0
    minStack.pop();
    minStack.pop();
    assert(minStack.getMin() == 0);

    minStack.push(-1);
    actual = minStack.getMin();
    assert(actual == -1);

    minStack.push(-1);
    minStack.pop();
    actual = minStack.getMin();
    assert(actual == -1);

    // method 2: test
    MinStack2 st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    assert(st.getMin() == -3);

    st.pop();
    st.push(-3);
    assert(st.getMin() == -3);
    return 0;
}

#include<iostream>
#include<vector>
#include<map>
#include<algorithm> // min
#include<assert.h>
#include<limits.h>
using namespace std;
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
            mymap.erase(st.back());   // erase by key, log(N), not O(1) time!
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
int main() {
    MinStack minStack;// = new MinStack();
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
    return 0;
}

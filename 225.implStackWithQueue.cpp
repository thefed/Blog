#include<iostream>
#include<queue>
#include<assert.h>
using namespace std;
void printQueue(queue<int> q) {
    // for (queue<int>::iterator iter = q.begin(); iter != q.end(); iter++) {
    //     cout << *iter << ", ";
    // }
    while (!q.empty()) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;
}
// q methods: pop, push, empty, front, back
class Stack {
private: 
    queue<int> myData;
    // 1 2 3-> 3 2 1    
    queue<int> reverseQueue(queue<int> src) {
        queue<int> dest;
        while (!src.empty()) {
            dest.push(src.front());
            src.pop();
        }
        return dest;
    }
public:
    // Push element x onto stack.
    void push(int x) {
        myData.push(x);
        cout << "after push: ";
        printQueue(myData);
    }

    // Removes the element on top of the stack.
    void pop() {
        // q: 1 2 3, rm 3: pop 3 2 1, 
        if (myData.empty()) return;
        queue<int> copiedData;
        while (myData.size() > 1) {
            copiedData.push(myData.front());
            myData.pop();
        }
        myData = copiedData;
        cout << "after pop: ";
        printQueue(myData);
        cout << endl;
    }

    // Get the top element.
    int top() {
        // q: 1 2 3, rt 3: rq: 3 2 1
        if (myData.empty()) return -1;
        queue<int> tmp = myData;
        while (tmp.size() > 1) {
            tmp.pop();
        }
        return tmp.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return myData.empty();
    }
};
void test() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    int actual = st.top();
    printf("actual: %d\n", actual);
    assert(actual == 2 && "wrong output");
    printf("SUCCESS\n");
}
int main() {
    test();
}
// LC 20, check if a string is valid parenthesis
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;
bool isValid(string s) {
    stack<int> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else {
            if (c == ')' && !st.empty() && st.top() == '(') st.pop();
            else if (c == ']' && !st.empty() && st.top() == '[') st.pop();
            else if (c == '}' && !st.empty() && st.top() == '{') st.pop();
            else return false;
        }
    }
    return st.empty();
}
int main() {
    string s = "()[]{([])}";
    bool res = isValid(s);
    assert(res);

    s = "()[]{}(]";
    res = isValid(s);
    assert(!res);

    s = "()[]{}(";
    res = isValid(s);
    assert(!res);
    return 0;
}
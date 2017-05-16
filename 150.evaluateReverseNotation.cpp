// LC 150, evaluate the value of reverse Polish notation
//  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
// ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>
#include <cassert>
#include <vector>
using namespace std;
int evalRPN(vector<string>& tokens) {
    if (tokens.empty()) return 0;
    if (tokens.size() == 1) return stoi(tokens[0]);
    
    unordered_set<char> set = {'+', '-', '*', '/'};
    stack<int> st;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i].size() == 1 && set.count(tokens[i][0])) {
            char op = tokens[i][0];
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            if (op == '+') st.push(val1 + val2);
            else if (op == '-') st.push(val1 - val2);
            else if (op == '*') st.push(val1 * val2);
            else if (op == '/') st.push(val1 / val2);
        }
        else {
            int num = stoi(tokens[i]);
            st.push(num);
        }
    }
    return st.top();
}
int main() {
	vector<string> tokens1 = {"2", "1", "+", "3", "*"};
	int exp1 = 9;	//  -> ((2 + 1) * 3) -> 9
  	vector<string> tokens2 = {"4", "13", "5", "/", "+"};
  	int exp2 = 6;	//  -> (4 + (13 / 5)) -> 6

  	int res1 = evalRPN(tokens1);
  	assert(res1 == exp1);

  	int res2 = evalRPN(tokens2);
  	assert(res2 == exp2);
	return 0;
}
#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm> // max
#include<assert.h>
using namespace std;
template<class T>
void print(const vector<T> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ", ";
    }
    cout << endl;
}
// c++ split string by delimiter
void split(const string &s, char del, vector<string> &strs) {
    stringstream ss(s);
    string str;
    while (getline(ss, str, del)) {
        if (str.size() > 0) {
            strs.push_back(str);
        }
    }
}
int getTabCnt(string s) {   // get number of tabs in front of a string
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '\t') {
            cnt++;
        }
        else {
            break;
        }
    }
    return cnt;
}
bool isFile(string s) {
    return s.find(".") != -1;
}
int getPathLen(const vector<string> &strs) {
    int len = 0;
    for (int i = 0; i < strs.size(); i++) {
        len += strs[i].size() + 1;  // currPath/'
    }
    return len - 1;
}
int lengthLongestPath(string input) {
    vector<string> strs;
    split(input, '\n', strs);
    // use vector as a stack to record depth
    vector<string> st;
    int len = 0;
    int maxLen = 0;
    
    for (int i = 0; i < strs.size(); i++) {
        int tabCnt = getTabCnt(strs[i]);
        string fname = strs[i].substr(tabCnt);  // strip tabs
        if (tabCnt == st.size()) {  // current level
            st.push_back(fname);
            if (isFile(fname)) {
                print(st);
                len = getPathLen(st);
                maxLen = max(len, maxLen);
            }
        }
        else if (tabCnt < st.size()) {  // pop
            while (tabCnt < st.size()) {
                st.pop_back();  // remove top element
            }
            i--;    // in next iteration, push it stack
        }
    }
    return maxLen;
}
void test1() {
    string s = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    int expected = 20;
    int actual = lengthLongestPath(s);
    assert(actual == expected && "max length should be 20");
}
int main() {
    test1();
}